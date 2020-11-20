#include "car_stop.h"
#include "ui_car_stop.h"

#include <QHostAddress>
#include <QDebug>
#include <QPixmap>

#include <QThread>
#include <QFile>
#include <QMessageBox>

#include "admin.h"

extern "C"
{
//添加头文件
#include  "yuyv.h"
#include  "jpeglib.h"
#include <string.h>
//添加标准IO 接口
#include  <stdio.h>
}

//tcp宏定义-----ip和端口
#define ADDRESS "192.168.23.45"
quint16 PORT = 6666;

unsigned int id;
unsigned int photo_flag;        //抓拍标志
unsigned int video_flag;        //视频标志
unsigned int show_flag;


QString filename_path;



//摄像头初始化
void v4l2_init()
{
    //1.初始化摄像头
    linux_v4l2_yuyv_init("/dev/video7");

    //2.开启抓取画面功能
    linux_v4l2_start_yuyv_capturing();
}

//线程定时器
void workPthread::tid_video()
{
    if(!is_runnable)            //线程退出,关闭定时器
    {
        tid_tim->stop();
        return;
    }

    create_flag = 1;
}

//用于结束线程
void workPthread::stop()
{
    is_runnable =false;
}

//线程构造
workPthread::workPthread(Ui::car_stop *ui)
{
    p_ui = ui;

    is_runnable = true;
    //jpg_name = "";
    pic_num     = 0;
    create_flag = 0;
    start_flag  = 0;

    tid_tim = new QTimer(this);
    connect(tid_tim,SIGNAL(timeout()),this,SLOT(tid_video()));    //录1分钟

    tim_flag = 1;
    tid_tim->start(100000);

}

//线程任务函数
void workPthread::run()
{
    struct jpg_data jpg_buf;

    while(is_runnable)
    {
        if(create_flag == 1)
        {
            QFile videomp4("./dd.mp4");
            if(videomp4.exists())
            {
                system("rm ./dd.mp4");
                qDebug() << "remove ok";
            }

            system("ffmpeg -framerate 10 -i ./video_pic/image%d.jpg dd.mp4");
            qDebug() << "create dd.mp4 success";

            pic_num = 0;
            create_flag = 0;
        }


        if(video_flag == 0)                                         //为0不断监控
        {
            /*
            if(tim_flag == 0)                                       //重新开启定时器
            {
                tid_tim->start(60000-pic_num*1000);                 //减去之前的秒数
            }
            */
            memset(jpg_buf.jpg_data,0,sizeof(jpg_buf.jpg_data));    //初始化

            linux_v4l2_get_yuyv_data (&jpg_buf);                    //3.抓取一帧画面

            //if(create_flag == 0)                                    //不用合成视频
            //{
                jpg_name = QString("./video_pic/image%1.jpg").arg(pic_num);      //生成图片文件路径
                QFile file(jpg_name);
                if(!file.open(QFile::WriteOnly|QFile::Text|QFile::Truncate))
                {
                    qDebug() << "open video_pic file fail write";
                    continue;
                }
                //qDebug() << "open video_pic file success write";

                file.write((const char*)jpg_buf.jpg_data,jpg_buf.jpg_size);
                file.close();

                pic_num++;
            //}
            //else
                //start_flag = 1;                                 //开始合成视频


            if(show_flag == 1)
            {
                linux_v4l2_yuyv_quit();                         //关闭视频流
                video_flag = 1;

                //tim_flag = 0;                                   //定时器关闭标志
                //tid_tim->stop();                                //关闭定时器
                continue;
            }

            QPixmap pic;                                        //4.显示一帧画面
            pic.loadFromData(jpg_buf.jpg_data,jpg_buf.jpg_size);
            p_ui->photo->setPixmap(pic);

        }

        if(photo_flag == 1)                                         //抓拍标志,放入另一个文件夹
        {
            QFile file(filename_path);

            if(!file.open(QFile::WriteOnly|QFile::Text|QFile::Truncate))
            {
                qDebug() << "open id_pic file fail write";
                continue;
            }
            qDebug() << "open id_pic file success write";

            file.write((const char*)jpg_buf.jpg_data,jpg_buf.jpg_size);

            file.close();

            photo_flag = 0;
            video_flag = 1;
            linux_v4l2_yuyv_quit();                     //关闭视频流
        }

    }
}


car_stop::car_stop(int iid,int flag,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::car_stop)
{
    ui->setupUi(this);

    id = iid;
    file_size  = 0;
    file_temp  = 0;
    cost_flag  = 0;
    photo_flag = 0;
    video_flag = 0;
    show_flag  = 0;
    size_flag  = 0;
    file_flag  = 0;


    filename_path = "./id_pic/car_photo.jpg";


    play = new QProcess(this);
    //play ->setProcessChannelMode(QProcess::MergedChannels);

    //设置串口驱动的路径
    my_port =  new QSerialPort("/dev/ttySAC2");

    //打开串口
    if(my_port->open(QIODevice::ReadWrite))
    {
        qDebug() << "open serial success";
    }
    else
    {
         qDebug() << "open serial fail";
    }

    my_port->setBaudRate(QSerialPort::Baud9600); //设置波特率 9600
    my_port->setDataBits(QSerialPort::Data8);    //设置 数据位  8
    my_port->setParity(QSerialPort::NoParity);   //无奇偶校验位
    my_port->setStopBits(QSerialPort::OneStop);  //1位停止位
    my_port->setFlowControl(QSerialPort::NoFlowControl); //无数据流控制

    //读rfid
    connect(my_port,SIGNAL(readyRead()),this,SLOT(read_data()));

    //初始化数据库-----sqlite3
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./car.db");
    if(db.open())
    {
     qDebug() << "open sql ok";
    }
    else
    {
     qDebug()  <<  "open sql fail";
    }

    //初始化命令管理器
    sql  =  new  QSqlQuery(db);

    //tcp传输-----合成语音
    tcp_soc = new QTcpSocket(this);
    connect(tcp_soc,SIGNAL(readyRead()),this,SLOT(tcp_data()));     //读取语音
    tcp_soc->connectToHost(QHostAddress(ADDRESS),PORT);

    //udp传输
    //udp_soc = new QUdpSocket(this);
    //udp_soc->bind(PORT);

    //摄像头初始化
    v4l2_init();

    //创建线程
    my_tid = new workPthread(ui);
    my_tid->start();


    t_photo =  new QTimer(this);
    connect(t_photo,SIGNAL(timeout()),this,SLOT(start_video()));    //开启视频流

    //初始化定时器
    t =  new QTimer(this);
    connect(t,SIGNAL(timeout()),this,SLOT(send_req()));             //发送请求

    t->start(2000);


    //从管理员模式回来后判断
    if(flag == 1)
    {
        add_label();

        QString  cmd = QString("select * from car_info where id='%1';").arg(id);
        if(sql->exec(cmd))
        {
            qDebug() << "select success";

            if(sql->first())
            {
                qDebug() << "car_info id exist";
                ui->label_2->setText(sql->value(0).toString());
                ui->label_4->setText(sql->value(1).toString());            //显示卡类型
                ui->label_12->setText(sql->value(2).toString());
                ui->label_14->setText(sql->value(3).toString());
            }
        }
        else
        {
            qDebug() << "select fail";
        }

        QString  cmd1 = QString("select * from car where id='%1';").arg(id);
        if(sql->exec(cmd1))
        {
            qDebug() << "select success";

            if(sql->first())
            {
                ui->label_6->setText(sql->value(1).toString());
            }
        }
        else
        {
            qDebug() << "select fail";
        }
    }
    if(flag == 2)
    {
        add_label();

        QString  cmd2 = QString("select * from car where id='%1';").arg(id);
        if(sql->exec(cmd2))
        {
            qDebug() << "select success";

            if(sql->first())
            {
                qDebug() << "id exist";
                ui->label_2->setText(sql->value(0).toString());
                reduce_card();
            }
        }
        else
        {
            qDebug() << "select fail";
        }
    }

    this->flag = 0;

}

car_stop::~car_stop()
{
    delete ui;
    delete play;
    delete sql;
    delete tcp_soc;
    delete my_port;
}


//清除label
void car_stop::clear_label()
{
    ui->label->clear();
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label_5->clear();
    ui->label_6->clear();
    ui->label_7->clear();
    ui->label_8->clear();
    ui->label_9->clear();
    ui->label_10->clear();
    ui->label_11->clear();
    ui->label_12->clear();
    ui->label_13->clear();
    ui->label_14->clear();
}

//添加label->text
void car_stop::add_label()
{
    clear_label();

    ui->label->setText("车牌");
    ui->label_3->setText("卡类型");
    ui->label_5->setText("进场时间");
    ui->label_7->setText("出场时间");
    ui->label_9->setText("停车费用");
    ui->label_11->setText("VIP剩余天数");
    ui->label_13->setText("卡上余额");
}

//校验和的算法
unsigned char get_bcc(QByteArray *buf,int n)
{
    char bcc = 0;

    int i;
    for(i=0;i<n;i++)
    {

        bcc = bcc ^ buf->at(i);
    }

    return (~bcc);
}

//读取rfid-----获取id
void car_stop::read_data()
{
    char  buf[10]={0};
    int size = my_port->read(buf,10);

    if(buf[2] == 0  &&  size == 8)  //请求返回
    {
       qDebug() <<  "request ok";

        //对RFID 模块发起防碰撞协议
        QByteArray buf_b;
        buf_b.resize(8);

        buf_b[0] = 0x08;
        buf_b[1] = 0x02;
        buf_b[2] = 0x42;
        buf_b[3] = 0x02;
        buf_b[4] = 0x93;
        buf_b[5] = 0x00;
        buf_b[6] = get_bcc(&buf_b,buf_b[0]-2);
        buf_b[7] = 0x03;

        my_port->write(buf_b);          //发送到串口获取卡id
    }


    if(buf[2] == 0 && size == 10)
    {

        //取出卡号
        id =  *((unsigned int *)&buf[4]);

        add_label();
        ui->label_2->setText(QString::number(id));      //显示id
        qDebug() << "id : " << id;

        QString  cmd = QString("select * from car where id='%1';").arg(id);
        if(sql->exec(cmd))
        {
            qDebug() << "select success";

            if(sql->first())
            {
                qDebug() << "id exist";

                reduce_card();                       //存在即出场
            }
            else
            {
                qDebug() << "id non-exist";

                add_card();                         //不存在即进场
            }

        }
        else
        {
            qDebug() << "select fail";
        }

    }
}

//定时器t-----2秒发送一次请求
void car_stop::send_req()
{
    //定制请求协议
    QByteArray buf;
    buf.resize(7);
    buf[0] = 0x07;  //帧长
    buf[1] = 0x02;  //类型
    buf[2] = 0x41;  //A命令
    buf[3] = 0x01;  //数据长度
    buf[4] = 0x52;  //数据信息
    buf[5] = get_bcc(&buf,buf[0] -2);  //校验和
    buf[6] = 0x03;  //结束符

    my_port->write(buf);            //发送请求到串口
}

//定时器t_photo-----开启视频流
void car_stop::start_video()
{
    v4l2_init();                  //摄像头初始化
    video_flag = 0;
    show_flag  = 0;
    t_photo->stop();
}


//tcp读取数据-----接收语音文件
void car_stop::tcp_data()
{

        QString str = tcp_soc->readAll();
        qDebug() << "size : " << str.size();

        QByteArray msg = str.toUtf8();
        if(msg.startsWith("len:"))
        {
            file_size = msg.mid(4).toInt();
            qDebug() << file_size;

            //调用tftp工具传输
            system("tftp -g -r ./yuyinhecheng/tts_sample.wav 192.168.23.44");

            play->start("aplay tts_sample.wav");
            qDebug()  << "broadcasting tts_sample.wav";


        }


}


//出场播报
void car_stop::reduce_broadcast(double free)
{
    QString broadcast = QString("车牌号为%1,停车费用%2元").arg(id).arg(free);
    QByteArray ba = broadcast.toUtf8();

    tcp_soc->write(ba.data());                  //让服务器合成播报

    flag = 2;
}

void car_stop::exit_info()
{

}

//出场-----计算消费金额
void car_stop::cost()
{
    int sec = 0;                //停车总秒数
    if(sql->first())
    {
        sec = sql->value(0).toInt();
        qDebug() << "sec : " <<sec;
    }
    //int min = sec/60;         //停车分钟


    //显示卡类型
    QString c_type;
    QString  cmd = QString("select * from car_info where id='%1';").arg(id);
    if(sql->exec(cmd))
    {
        if(sql->next())
        {
            //第二个为卡类型
            c_type = sql->value(1).toString();

            ui->label_12->setText(sql->value(2).toString());
            ui->label_14->setText(sql->value(3).toString());
        }
    }
    ui->label_4->setText(c_type);         //显示卡类型

    free = 0;
    if(c_type == "VIP卡")
    {
        free = sec*0.5;
        qDebug() << "free :" << free;       //一秒钟0.5￥
    }
    else
    {
        free = sec*0.8;
        qDebug() << "free :" << free;       //一秒钟0.8￥
    }
    ui->label_10->setText(QString("%1元").arg(free));     //显示费用


    reduce_broadcast(free);                 //出场播报

    //显示图片
    QString  cmd2 = QString("select * from car where id='%1';").arg(id);
    if(sql->exec(cmd2))
    {
        if(sql->next())
        {
            //第三个为图片路径
            filename_path = sql->value(2).toString();
        }
    }
    show_flag  = 1;                         //显示标志
    ui->photo->setPixmap(filename_path);    //显示图片

    cost_flag = 1;                          //未支付标志
}

//出场-----计算时间
void car_stop::reduce_card()
{

    //进场时间
    QString in_time;

    //第二个为进场时间
    in_time = sql->value(1).toString();

    ui->label_6->setText(in_time);          //显示进场时间

    //出场时间
    QString out_time;
    QString cmd1 = QString("select datetime('now');");
    if(sql->exec(cmd1))
    {
        if(sql->first())
        {
            out_time = sql->value(0).toString();
            qDebug() << out_time;
        }

    }
    else
    {
        qDebug() << "get now time fail";
        return;
    }

    ui->label_8->setText(out_time);

    //出场时间 - 进场时间
    QString cmd2 = QString("select (strftime('%s','now') - strftime('%s','%1'));").arg(in_time);
    if(sql->exec(cmd2))
    {
        cost();              //计费
    }
    else
    {
        qDebug()  << "calculate fail";
    }


}

//进场播报
void car_stop::add_broadcast()
{
    QString c_type;
    QString  cmd = QString("select * from car_info where id='%1';").arg(id);
    if(sql->exec(cmd))
    {
        if(sql->next())
        {
            //第二个为卡类型
            c_type = sql->value(1).toString();
        }
    }
    else
    {
        qDebug() << "broadcast fail";
        return;
    }

    QString broadcast = QString("车牌号为%1,%2停车").arg(id).arg(c_type);
    QByteArray ba = broadcast.toUtf8();

    tcp_soc->write(ba.data());                  //让服务器合成播报

    flag = 1;
}


//进场-----另一个表格car_info数据
void car_stop::entry_info()
{
    QString  cmd = QString("select * from car_info where id='%1';").arg(id);
    if(sql->exec(cmd))
    {
        qDebug() << "select success";

        if(sql->first())
        {
            qDebug() << "car_info id exist";

            //存在即为VIP
            ui->label_4->setText(sql->value(1).toString());            //显示卡类型

            ui->label_12->setText(sql->value(2).toString());
            ui->label_14->setText(sql->value(3).toString());
        }
        else
        {
            qDebug() << "car_info id non-exist";


            //不存在即为临时卡
            QString cmd1 = QString("insert into car_info values('%1','临时卡','0','0');").arg(id);
            if(sql->exec(cmd1))
            {
                qDebug() << "car_info reg ok";
            }
            else
            {
                qDebug() << "car_info reg fail";
                return;
            }

            ui->label_4->setText("临时卡");            //显示卡类型

            ui->label_12->setText("0");
            ui->label_14->setText("0");
        }
    }
    else
    {
        qDebug() << "select fail";
    }
}

//进场-----添加到表格car
void car_stop::add_card()
{

    photo_flag = 1;                             //进场抓拍

    //操作另一个数据库表格car_info
    entry_info();


    add_broadcast();                            //进场播报

    QString now_time;                           //当前时间
    QString cmd1 = QString("select datetime('now');");
    if(sql->exec(cmd1))
    {
        if(sql->first())
        {
            now_time = sql->value(0).toString();
            qDebug() << now_time;
        }
    }
    else
    {
        qDebug() << "get now time fail";
        return;
    }
    ui->label_6->setText(now_time);           //显示进场时间

    filename_path = QString("./id_pic/%1").arg(id);

    //把当前卡号插入到 表格中
    QString  cmd2 = QString("insert into car values('%1','%2','%3');").arg(id).arg(now_time).arg(filename_path);
    if(sql->exec(cmd2))
    {
        qDebug() << "reg ok";
    }
    else
    {
        qDebug() << "reg fail";
        //return;
    }

    t_photo->start(8000);       //开启视频流
}


//管理员模式
void car_stop::on_pushButton_clicked()
{
    if(id == 0)     return;

    show_flag = 1;

    t_photo->stop();
    t->stop();

    QString broadcast = QString("exit");
    QByteArray ba = broadcast.toUtf8();

    tcp_soc->write(ba.data());

    //发送 结束信号
    play->kill();

    //回收进程资源
    if(play->waitForFinished())
    {
        qDebug() << "wait ok";
    }
    else
    {
        qDebug() << "wait fail";
    }

    my_tid->stop();     //自定义停止

    my_tid->wait();

    my_port->close();

    admin *adm = new admin(db,id,flag);
    adm->show();
    this->hide();

}


//缴费后播报-----祝福播报
void car_stop::broadcast()
{
    QString broadcast = QString("缴费成功,祝您一路平安");
    QByteArray ba = broadcast.toUtf8();

    tcp_soc->write(ba.data());           //让服务器合成播报
}

//缴费-----删数据
void car_stop::on_pushButton_2_clicked()
{
    if(cost_flag == 0)      return;     //没生成费用则返回




    //删库跑路
    //删除临时卡
    QString cmd = QString("delete from car_info where id='%1' and card_type = '临时卡';").arg(id);
    if(sql->exec(cmd))
    {
        qDebug() << "delete no vip success";
    }
    else
    {
        qDebug() << "delete no vip fail";
    }

    //计算VIP卡
    QString cmd1 = QString("select * from car_info where id='%1';").arg(id);
    if(sql->exec(cmd1))
    {
        qDebug() << "select vip success";
        if(sql->next())
        {
            double money = sql->value(3).toDouble();
            qDebug()  << "money:" << money;

            money -= free;
            if(money <=0 )
            {
                qDebug() << "no few money";
                QMessageBox::warning(this,tr("余额不足"),tr("请前往充值"),QMessageBox::Ok);

                return;
            }

            QString type = sql->value(1).toString();
            int day = sql->value(2).toInt();
            qDebug()  << "day:" << day;


            day = day - 1;
            if(day == 0)
            {
                type = "临时卡";
            }

            qDebug() << day;
            qDebug() << type;

            QString  cmd2 = QString("update car_info set card_type='%1' where id='%2';").arg(type).arg(id);
            if(sql->exec(cmd2))
            {
                qDebug() << "update card_type car_info success";
            }
            else
            {
                qDebug() << "update card_type car_info fail";
            }

            QString  cmd3 = QString("update car_info set day='%1' where id='%2';").arg(day).arg(id);
            if(sql->exec(cmd3))
            {
                qDebug() << "update day car_info success";
            }
            else
            {
                qDebug() << "update day car_info fail";
            }

            QString  cmd4 = QString("update car_info set money='%1' where id='%2';").arg(money).arg(id);
            if(sql->exec(cmd4))
            {
                qDebug() << "update money car_info success";
            }
            else
            {
                qDebug() << "update money car_info fail";
            }
        }

    }
    else
    {
        qDebug() << "select vip fail";
    }

    broadcast();                  //祝福播报

    //删除表格car的数据
    QString cmd2 = QString("delete from car where id='%1';").arg(id);
    if(sql->exec(cmd2))
    {       
        qDebug() << "delete success";
        clear_label();                 //清除label

        ui->label_4->setText("缴费成功");
        ui->label_13->setText("祝您一路平安");

        cost_flag = 0;                //支付完成

        flag = 0;
        id = 0;
        t_photo->start(500);        //开启视频流
    }
    else
    {
        qDebug() << "delete fail";
    }
}
