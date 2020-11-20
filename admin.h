#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    admin( QSqlDatabase db,int iid = 0,int flag = 0,QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_exit_clicked();

    void on_vip_clicked();

    void on_money100_clicked();

    void on_money500_clicked();

    void on_money1000_clicked();

    void on_money5000_clicked();

    void on_listWidget_currentTextChanged(const QString &currentText);

    void add_day();

private:
    Ui::admin *ui;

    QSqlDatabase db;
    QSqlQuery *sql;

    int id;
    int flag;
};

#endif // ADMIN_H
