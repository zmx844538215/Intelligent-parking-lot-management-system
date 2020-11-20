/****************************************************************************
** Meta object code from reading C++ file 'admin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "admin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_admin_t {
    QByteArrayData data[11];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_admin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_admin_t qt_meta_stringdata_admin = {
    {
QT_MOC_LITERAL(0, 0, 5), // "admin"
QT_MOC_LITERAL(1, 6, 15), // "on_exit_clicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "on_vip_clicked"
QT_MOC_LITERAL(4, 38, 19), // "on_money100_clicked"
QT_MOC_LITERAL(5, 58, 19), // "on_money500_clicked"
QT_MOC_LITERAL(6, 78, 20), // "on_money1000_clicked"
QT_MOC_LITERAL(7, 99, 20), // "on_money5000_clicked"
QT_MOC_LITERAL(8, 120, 32), // "on_listWidget_currentTextChanged"
QT_MOC_LITERAL(9, 153, 11), // "currentText"
QT_MOC_LITERAL(10, 165, 7) // "add_day"

    },
    "admin\0on_exit_clicked\0\0on_vip_clicked\0"
    "on_money100_clicked\0on_money500_clicked\0"
    "on_money1000_clicked\0on_money5000_clicked\0"
    "on_listWidget_currentTextChanged\0"
    "currentText\0add_day"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_admin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

       0        // eod
};

void admin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        admin *_t = static_cast<admin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_exit_clicked(); break;
        case 1: _t->on_vip_clicked(); break;
        case 2: _t->on_money100_clicked(); break;
        case 3: _t->on_money500_clicked(); break;
        case 4: _t->on_money1000_clicked(); break;
        case 5: _t->on_money5000_clicked(); break;
        case 6: _t->on_listWidget_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->add_day(); break;
        default: ;
        }
    }
}

const QMetaObject admin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_admin.data,
      qt_meta_data_admin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *admin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *admin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_admin.stringdata0))
        return static_cast<void*>(const_cast< admin*>(this));
    return QWidget::qt_metacast(_clname);
}

int admin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
