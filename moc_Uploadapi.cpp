/****************************************************************************
** Meta object code from reading C++ file 'Uploadapi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Uploadapi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Uploadapi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Uploadapi_t {
    QByteArrayData data[5];
    char stringdata[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Uploadapi_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Uploadapi_t qt_meta_stringdata_Uploadapi = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Uploadapi"
QT_MOC_LITERAL(1, 10, 8), // "readdata"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 35, 5) // "reply"

    },
    "Uploadapi\0readdata\0\0QNetworkReply*\0"
    "reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Uploadapi[] = {

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
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void Uploadapi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Uploadapi *_t = static_cast<Uploadapi *>(_o);
        switch (_id) {
        case 0: _t->readdata((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Uploadapi::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Uploadapi.data,
      qt_meta_data_Uploadapi,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Uploadapi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Uploadapi::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Uploadapi.stringdata))
        return static_cast<void*>(const_cast< Uploadapi*>(this));
    if (!strcmp(_clname, "AbstractApi"))
        return static_cast< AbstractApi*>(const_cast< Uploadapi*>(this));
    return QObject::qt_metacast(_clname);
}

int Uploadapi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
