/****************************************************************************
** Meta object code from reading C++ file 'car_stop.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "car_stop.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'car_stop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_workPthread_t {
    QByteArrayData data[3];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_workPthread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_workPthread_t qt_meta_stringdata_workPthread = {
    {
QT_MOC_LITERAL(0, 0, 11), // "workPthread"
QT_MOC_LITERAL(1, 12, 9), // "tid_video"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "workPthread\0tid_video\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_workPthread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void workPthread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        workPthread *_t = static_cast<workPthread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tid_video(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject workPthread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_workPthread.data,
      qt_meta_data_workPthread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *workPthread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *workPthread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_workPthread.stringdata0))
        return static_cast<void*>(const_cast< workPthread*>(this));
    return QThread::qt_metacast(_clname);
}

int workPthread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_car_stop_t {
    QByteArrayData data[19];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_car_stop_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_car_stop_t qt_meta_stringdata_car_stop = {
    {
QT_MOC_LITERAL(0, 0, 8), // "car_stop"
QT_MOC_LITERAL(1, 9, 9), // "read_data"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "send_req"
QT_MOC_LITERAL(4, 29, 11), // "start_video"
QT_MOC_LITERAL(5, 41, 8), // "tcp_data"
QT_MOC_LITERAL(6, 50, 8), // "add_card"
QT_MOC_LITERAL(7, 59, 10), // "entry_info"
QT_MOC_LITERAL(8, 70, 13), // "add_broadcast"
QT_MOC_LITERAL(9, 84, 11), // "reduce_card"
QT_MOC_LITERAL(10, 96, 9), // "exit_info"
QT_MOC_LITERAL(11, 106, 16), // "reduce_broadcast"
QT_MOC_LITERAL(12, 123, 4), // "free"
QT_MOC_LITERAL(13, 128, 4), // "cost"
QT_MOC_LITERAL(14, 133, 9), // "broadcast"
QT_MOC_LITERAL(15, 143, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(16, 165, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(17, 189, 9), // "add_label"
QT_MOC_LITERAL(18, 199, 11) // "clear_label"

    },
    "car_stop\0read_data\0\0send_req\0start_video\0"
    "tcp_data\0add_card\0entry_info\0add_broadcast\0"
    "reduce_card\0exit_info\0reduce_broadcast\0"
    "free\0cost\0broadcast\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0add_label\0"
    "clear_label"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_car_stop[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    1,  103,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void car_stop::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        car_stop *_t = static_cast<car_stop *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->read_data(); break;
        case 1: _t->send_req(); break;
        case 2: _t->start_video(); break;
        case 3: _t->tcp_data(); break;
        case 4: _t->add_card(); break;
        case 5: _t->entry_info(); break;
        case 6: _t->add_broadcast(); break;
        case 7: _t->reduce_card(); break;
        case 8: _t->exit_info(); break;
        case 9: _t->reduce_broadcast((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->cost(); break;
        case 11: _t->broadcast(); break;
        case 12: _t->on_pushButton_clicked(); break;
        case 13: _t->on_pushButton_2_clicked(); break;
        case 14: _t->add_label(); break;
        case 15: _t->clear_label(); break;
        default: ;
        }
    }
}

const QMetaObject car_stop::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_car_stop.data,
      qt_meta_data_car_stop,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *car_stop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *car_stop::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_car_stop.stringdata0))
        return static_cast<void*>(const_cast< car_stop*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int car_stop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
