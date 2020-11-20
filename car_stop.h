#ifndef CAR_STOP_H
#define CAR_STOP_H

#include <QMainWindow>

#include <QProcess>

//添加串口的头文件
#include <QSerialPort>

//数据库管理器
#include <QSqlDatabase>
#include <QSqlQuery>

//TCP
#include <QTcpSocket>
//UDP
#include <QUdpSocket>
#include <QTimer>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class car_stop; }
QT_END_NAMESPACE

//线程类
class workPthread : public QThread
{
    Q_OBJECT

    void run();

public:
    workPthread(Ui::car_stop *ui);

    void stop();    //用于关闭线程

private slots:
    void tid_video();

private:
    Ui::car_stop *p_ui;
    QTimer *tid_tim;

    QString jpg_name;
    unsigned int pic_num;
    unsigned int tim_flag;
    unsigned int create_flag;
    unsigned int start_flag;

    bool is_runnable;
};



class car_stop : public QMainWindow
{
    Q_OBJECT

public:
    car_stop(int iid = 0,int flag = 0,QWidget *parent = nullptr);
    ~car_stop();

private slots:
    void read_data();

    void send_req();

    void start_video();

    void tcp_data();

    void add_card();                        //进场

    void entry_info();

    void add_broadcast();                   //进场播报

    void reduce_card();                     //出场

    void exit_info();

    void reduce_broadcast(double free);    //出场播报

    void cost();                            //出场消费金额

    void broadcast();                       //祝福播报

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void add_label();                       //添加text

    void clear_label();                     //清屏

private:
    Ui::car_stop *ui;

    QProcess *play;

    QSerialPort *my_port;

    QSqlDatabase db;
    QSqlQuery *sql;

    QTcpSocket *tcp_soc;
    //QUdpSocket *udp_soc;
    QTimer *t;
    QTimer *t_photo;

    unsigned int file_size;
    unsigned int file_temp;
    unsigned int size_flag;
    unsigned int file_flag;
    unsigned int cost_flag;   //计费标志

    int flag;
    double free;

    workPthread *my_tid;
};
#endif // CAR_STOP_H
