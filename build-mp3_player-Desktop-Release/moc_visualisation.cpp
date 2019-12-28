/****************************************************************************
** Meta object code from reading C++ file 'visualisation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mp3_player/headers/visualisation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualisation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Visualisation_t {
    QByteArrayData data[7];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Visualisation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Visualisation_t qt_meta_stringdata_Visualisation = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Visualisation"
QT_MOC_LITERAL(1, 14, 11), // "prepareData"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "length"
QT_MOC_LITERAL(4, 34, 13), // "fftw_complex*"
QT_MOC_LITERAL(5, 48, 4), // "data"
QT_MOC_LITERAL(6, 53, 11) // "renderGraph"

    },
    "Visualisation\0prepareData\0\0length\0"
    "fftw_complex*\0data\0renderGraph"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Visualisation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x0a /* Public */,
       6,    0,   29,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void,

       0        // eod
};

void Visualisation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Visualisation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->prepareData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< fftw_complex*(*)>(_a[2]))); break;
        case 1: _t->renderGraph(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Visualisation::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Visualisation.data,
    qt_meta_data_Visualisation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Visualisation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Visualisation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Visualisation.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Visualisation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
