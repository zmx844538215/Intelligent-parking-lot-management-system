#include "car_stop.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    car_stop w;
    w.show();
    return a.exec();
}
