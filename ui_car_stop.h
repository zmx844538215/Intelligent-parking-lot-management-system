/********************************************************************************
** Form generated from reading UI file 'car_stop.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAR_STOP_H
#define UI_CAR_STOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_car_stop
{
public:
    QWidget *centralwidget;
    QLabel *photo;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_8;

    void setupUi(QMainWindow *car_stop)
    {
        if (car_stop->objectName().isEmpty())
            car_stop->setObjectName(QStringLiteral("car_stop"));
        car_stop->resize(800, 480);
        centralwidget = new QWidget(car_stop);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        photo = new QLabel(centralwidget);
        photo->setObjectName(QStringLiteral("photo"));
        photo->setGeometry(QRect(0, 0, 548, 411));
        photo->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(549, 50, 251, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_11);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_12);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_13);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_14);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_10);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 0, 251, 51));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 0);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(550, 430, 251, 51));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(-1, 409, 551, 71));
        gridLayout = new QGridLayout(horizontalLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 1, 1, 1);

        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 1, 1, 1, 1);

        car_stop->setCentralWidget(centralwidget);

        retranslateUi(car_stop);

        QMetaObject::connectSlotsByName(car_stop);
    } // setupUi

    void retranslateUi(QMainWindow *car_stop)
    {
        car_stop->setWindowTitle(QApplication::translate("car_stop", "car_stop", 0));
        photo->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        pushButton->setText(QApplication::translate("car_stop", "\347\256\241\347\220\206\345\221\230", 0));
        pushButton_2->setText(QApplication::translate("car_stop", "\347\274\264\350\264\271", 0));
        label_5->setText(QString());
        label_7->setText(QString());
        label_6->setText(QString());
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class car_stop: public Ui_car_stop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAR_STOP_H
