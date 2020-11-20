#include "admin.h"
#include "ui_admin.h"

#include <QDebug>

#include "car_stop.h"

admin::admin(QSqlDatabase db , int iid ,int flag ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);

    ui->listWidget->clear();

    id = iid;
    this->flag = flag;

    //初始化数据库-----sqlite3
    this->db = db;

    //初始化命令管理器
    sql  =  new  QSqlQuery(db);

    //遍历表格car_info
    QString  cmd = "select * from car_info;";
    if(sql->exec(cmd))
    {
        qDebug() << "select car_info success";
        while(sql->next())
        {
            ui->listWidget->addItem(sql->value(0).toString());
        }
    }
    else
    {
        qDebug() << "select car_info fail";
    }

}

admin::~admin()
{
    delete ui;
    delete sql;

}

//退出
void admin::on_exit_clicked()
{
    sql->clear();
    delete sql;

    db.close();
    QSqlDatabase::removeDatabase("qt_sql_default_connection");

    car_stop *car_s = new car_stop(id,flag);
    car_s->show();
    //this->hide();
    this->close();
}

//选中列表
void admin::on_listWidget_currentTextChanged(const QString &currentText)
{
    ui->id->setText(currentText);

    //遍历表格car
    QString  cmd = QString("select * from car where id='%1';").arg(currentText);
    if(sql->exec(cmd))
    {
        qDebug() << "select car success";
        if(sql->next())
        {
            ui->time->setText(sql->value(1).toString());
            QPixmap pic(sql->value(2).toString());
            ui->photo->setPixmap(pic);
        }
    }
    else
    {
        qDebug() << "select car fail";
        return;
    }

    //遍历表格car_info
    QString  cmd1 = QString("select * from car_info where id='%1';").arg(currentText);
    if(sql->exec(cmd1))
    {
        qDebug() << "select car_info success";
        if(sql->next())
        {
            ui->type-> setText("卡类型: "+sql->value(1).toString());
            ui->day->  setText("剩余VIP天数: "+sql->value(2).toString());
            ui->money->setText(sql->value(3).toString()+"元");
        }
    }
    else
    {
        qDebug() << "select car_info fail";
    }
}

void admin::add_day()
{
    int day = 3;

    QString  cmd = QString("select day from car_info where id='%1';").arg(ui->id->text());
    if(sql->exec(cmd))
    {
        qDebug() << "select day success";
        if(sql->next())
        {
            day += sql->value(0).toInt();
        }
    }
    else
    {
        qDebug() << "select day success";
        return;
    }

    QString  cmd1 = QString("update car_info set day='%1' where id='%2';").arg(day).arg(ui->id->text());
    if(sql->exec(cmd1))
    {
        qDebug() << "add 3 day success";
        ui->day-> setText(QString("剩余VIP天数: +%1").arg(day));
    }
    else
    {
        qDebug() << "add 3 day fail";
    }
}

//成为VIP
void admin::on_vip_clicked()
{
    if(ui->id->text() == "")     return;

    QString  cmd1 = QString("update car_info set card_type='VIP卡' where id='%1';").arg(ui->id->text());
    if(sql->exec(cmd1))
    {
        qDebug() << "be to VIP success";
        ui->type->setText("VIP卡");
    }
    else
    {
        qDebug() << "be to VIP fail";
        return;
    }


    add_day();              //VIP天数
}

//充值100元
void admin::on_money100_clicked()
{
    if(ui->id->text() == "")     return;

    double money = 100;

    QString  cmd = QString("select money from car_info where id='%1';").arg(ui->id->text());
    if(sql->exec(cmd))
    {
        qDebug() << "select money success";
        if(sql->next())
        {
            money += sql->value(0).toDouble();
        }
    }
    else
    {
        qDebug() << "select money fail";
        return;
    }

    QString  cmd1 = QString("update car_info set money='%1' where id='%2';").arg(money).arg(ui->id->text());
    if(sql->exec(cmd1))
    {
        qDebug() << "recharge 100 success";
        ui->money->setText(QString("%1元").arg(money));
    }
    else
    {
        qDebug() << "recharge 100 fail";
    }
}

//充值500元
void admin::on_money500_clicked()
{
    if(ui->id->text() == "")     return;

    double money = 500;

    QString  cmd = QString("select money from car_info where id='%1';").arg(ui->id->text());
    if(sql->exec(cmd))
    {
        qDebug() << "select money success";
        if(sql->next())
        {
            money += sql->value(0).toDouble();
        }
    }
    else
    {
        qDebug() << "select money fail";
        return;
    }

    QString  cmd1 = QString("update car_info set money='%1' where id='%2';").arg(money).arg(ui->id->text());
    if(sql->exec(cmd1))
    {
        qDebug() << "recharge 500 success";

        ui->money->setText(QString("%1元").arg(money));

    }
    else
    {
        qDebug() << "recharge 500 fail";
    }
}

//充值1000元
void admin::on_money1000_clicked()
{
    if(ui->id->text() == "")     return;

    double money = 1000;

    QString  cmd = QString("select money from car_info where id='%1';").arg(ui->id->text());
    if(sql->exec(cmd))
    {
        qDebug() << "select money success";
        if(sql->next())
        {
            money += sql->value(0).toDouble();
        }
    }
    else
    {
        qDebug() << "select money fail";
        return;
    }

    QString  cmd1 = QString("update car_info set money='%1' where id='%2';").arg(money).arg(ui->id->text());
    if(sql->exec(cmd1))
    {
        qDebug() << "recharge 1000 success";

        ui->money->setText(QString("%1元").arg(money));

    }
    else
    {
        qDebug() << "recharge 1000 fail";
    }
}

//充值2000元
void admin::on_money5000_clicked()
{
    if(ui->id->text() == "")     return;

    double money = 2000;

    QString  cmd = QString("select money from car_info where id='%1';").arg(ui->id->text());
    if(sql->exec(cmd))
    {
        qDebug() << "select money success";
        if(sql->next())
        {
            money += sql->value(0).toDouble();
        }
    }
    else
    {
        qDebug() << "select money fail";
        return;
    }

    QString  cmd1 = QString("update car_info set money='%1' where id='%2';").arg(money).arg(ui->id->text());
    if(sql->exec(cmd1))
    {
        qDebug() << "recharge 2000 success";

        ui->money->setText(QString("%1元").arg(money));

    }
    else
    {
        qDebug() << "recharge 2000 fail";
    }
}

