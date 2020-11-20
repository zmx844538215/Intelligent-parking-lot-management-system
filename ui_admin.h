/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *exit;
    QLabel *id;
    QLabel *money;
    QLabel *day;
    QLabel *type;
    QLabel *time;
    QLabel *label2;
    QPushButton *money100;
    QPushButton *money500;
    QPushButton *money5000;
    QPushButton *money1000;
    QPushButton *vip;
    QLabel *photo;

    void setupUi(QWidget *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName(QStringLiteral("admin"));
        admin->resize(800, 480);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        admin->setFont(font);
        admin->setStyleSheet(QStringLiteral("admin{background-image: url(:/car1.jpg);}"));
        listWidget = new QListWidget(admin);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 160, 181, 301));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        listWidget->setFont(font1);
        label = new QLabel(admin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 20, 151, 41));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        exit = new QPushButton(admin);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(620, 0, 181, 51));
        exit->setStyleSheet(QStringLiteral("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));"));
        id = new QLabel(admin);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(220, 90, 311, 41));
        id->setFont(font1);
        id->setAlignment(Qt::AlignCenter);
        money = new QLabel(admin);
        money->setObjectName(QStringLiteral("money"));
        money->setGeometry(QRect(220, 150, 311, 41));
        money->setFont(font1);
        money->setAlignment(Qt::AlignCenter);
        day = new QLabel(admin);
        day->setObjectName(QStringLiteral("day"));
        day->setGeometry(QRect(220, 340, 311, 41));
        day->setFont(font1);
        day->setAlignment(Qt::AlignCenter);
        type = new QLabel(admin);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(220, 280, 311, 41));
        type->setFont(font1);
        type->setAlignment(Qt::AlignCenter);
        time = new QLabel(admin);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(220, 220, 311, 41));
        time->setFont(font1);
        time->setAlignment(Qt::AlignCenter);
        label2 = new QLabel(admin);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(620, 80, 131, 61));
        QFont font3;
        font3.setPointSize(13);
        label2->setFont(font3);
        label2->setAlignment(Qt::AlignCenter);
        money100 = new QPushButton(admin);
        money100->setObjectName(QStringLiteral("money100"));
        money100->setGeometry(QRect(620, 160, 131, 51));
        money100->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
        money500 = new QPushButton(admin);
        money500->setObjectName(QStringLiteral("money500"));
        money500->setGeometry(QRect(620, 240, 131, 51));
        money500->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
        money5000 = new QPushButton(admin);
        money5000->setObjectName(QStringLiteral("money5000"));
        money5000->setGeometry(QRect(620, 400, 131, 51));
        money5000->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
        money1000 = new QPushButton(admin);
        money1000->setObjectName(QStringLiteral("money1000"));
        money1000->setGeometry(QRect(620, 320, 131, 51));
        money1000->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
        vip = new QPushButton(admin);
        vip->setObjectName(QStringLiteral("vip"));
        vip->setGeometry(QRect(310, 400, 131, 51));
        vip->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        photo = new QLabel(admin);
        photo->setObjectName(QStringLiteral("photo"));
        photo->setGeometry(QRect(20, 0, 171, 151));
        photo->setAlignment(Qt::AlignCenter);

        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QWidget *admin)
    {
        admin->setWindowTitle(QApplication::translate("admin", "Form", 0));
        label->setText(QApplication::translate("admin", "\347\256\241\347\220\206\345\221\230\346\250\241\345\274\217", 0));
        exit->setText(QApplication::translate("admin", "exit", 0));
        id->setText(QString());
        money->setText(QString());
        day->setText(QString());
        type->setText(QString());
        time->setText(QString());
        label2->setText(QApplication::translate("admin", "\345\205\205\345\200\274\346\234\215\345\212\241", 0));
        money100->setText(QApplication::translate("admin", "100\345\205\203", 0));
        money500->setText(QApplication::translate("admin", "500\345\205\203", 0));
        money5000->setText(QApplication::translate("admin", "2000\345\205\203", 0));
        money1000->setText(QApplication::translate("admin", "1000\345\205\203", 0));
        vip->setText(QApplication::translate("admin", "\346\210\220\344\270\272VIP", 0));
        photo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
