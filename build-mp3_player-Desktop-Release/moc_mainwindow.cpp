/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mp3_player/headers/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[35];
    char stringdata0[599];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "sigError"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "sigOpen"
QT_MOC_LITERAL(4, 29, 12), // "sigStopMusic"
QT_MOC_LITERAL(5, 42, 14), // "sigHasPlaylist"
QT_MOC_LITERAL(6, 57, 13), // "sigNoPlaylist"
QT_MOC_LITERAL(7, 71, 13), // "sigSongChange"
QT_MOC_LITERAL(8, 85, 8), // "slotPlay"
QT_MOC_LITERAL(9, 94, 8), // "slotOpen"
QT_MOC_LITERAL(10, 103, 13), // "slotStopMusic"
QT_MOC_LITERAL(11, 117, 33), // "on_sliderLevelVolume_valueCha..."
QT_MOC_LITERAL(12, 151, 5), // "value"
QT_MOC_LITERAL(13, 157, 29), // "on_sliderProgress_sliderMoved"
QT_MOC_LITERAL(14, 187, 8), // "position"
QT_MOC_LITERAL(15, 196, 17), // "onPositionChanged"
QT_MOC_LITERAL(16, 214, 17), // "onDurationChanged"
QT_MOC_LITERAL(17, 232, 8), // "duration"
QT_MOC_LITERAL(18, 241, 23), // "on_pbPauseMusic_clicked"
QT_MOC_LITERAL(19, 265, 24), // "on_pbNextSingiel_clicked"
QT_MOC_LITERAL(20, 290, 28), // "on_pbPreviousSingiel_clicked"
QT_MOC_LITERAL(21, 319, 23), // "on_pbDeleteSong_clicked"
QT_MOC_LITERAL(22, 343, 24), // "on_pbNewPlaylist_clicked"
QT_MOC_LITERAL(23, 368, 27), // "on_pbDeletePlaylist_clicked"
QT_MOC_LITERAL(24, 396, 30), // "on_listSongs_itemDoubleClicked"
QT_MOC_LITERAL(25, 427, 34), // "on_listPlaylists_itemDoubleCl..."
QT_MOC_LITERAL(26, 462, 22), // "on_currentMediaChanged"
QT_MOC_LITERAL(27, 485, 13), // "QMediaContent"
QT_MOC_LITERAL(28, 499, 7), // "content"
QT_MOC_LITERAL(29, 507, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(30, 530, 7), // "checked"
QT_MOC_LITERAL(31, 538, 26), // "on_pbVisualisation_clicked"
QT_MOC_LITERAL(32, 565, 13), // "processBuffer"
QT_MOC_LITERAL(33, 579, 12), // "QAudioBuffer"
QT_MOC_LITERAL(34, 592, 6) // "buffer"

    },
    "MainWindow\0sigError\0\0sigOpen\0sigStopMusic\0"
    "sigHasPlaylist\0sigNoPlaylist\0sigSongChange\0"
    "slotPlay\0slotOpen\0slotStopMusic\0"
    "on_sliderLevelVolume_valueChanged\0"
    "value\0on_sliderProgress_sliderMoved\0"
    "position\0onPositionChanged\0onDurationChanged\0"
    "duration\0on_pbPauseMusic_clicked\0"
    "on_pbNextSingiel_clicked\0"
    "on_pbPreviousSingiel_clicked\0"
    "on_pbDeleteSong_clicked\0"
    "on_pbNewPlaylist_clicked\0"
    "on_pbDeletePlaylist_clicked\0"
    "on_listSongs_itemDoubleClicked\0"
    "on_listPlaylists_itemDoubleClicked\0"
    "on_currentMediaChanged\0QMediaContent\0"
    "content\0on_radioButton_clicked\0checked\0"
    "on_pbVisualisation_clicked\0processBuffer\0"
    "QAudioBuffer\0buffer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  139,    2, 0x06 /* Public */,
       3,    0,  140,    2, 0x06 /* Public */,
       4,    0,  141,    2, 0x06 /* Public */,
       5,    0,  142,    2, 0x06 /* Public */,
       6,    0,  143,    2, 0x06 /* Public */,
       7,    0,  144,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  145,    2, 0x08 /* Private */,
       9,    0,  146,    2, 0x08 /* Private */,
      10,    0,  147,    2, 0x08 /* Private */,
      11,    1,  148,    2, 0x08 /* Private */,
      13,    1,  151,    2, 0x08 /* Private */,
      15,    1,  154,    2, 0x08 /* Private */,
      16,    1,  157,    2, 0x08 /* Private */,
      18,    0,  160,    2, 0x08 /* Private */,
      19,    0,  161,    2, 0x08 /* Private */,
      20,    0,  162,    2, 0x08 /* Private */,
      21,    0,  163,    2, 0x08 /* Private */,
      22,    0,  164,    2, 0x08 /* Private */,
      23,    0,  165,    2, 0x08 /* Private */,
      24,    0,  166,    2, 0x08 /* Private */,
      25,    0,  167,    2, 0x08 /* Private */,
      26,    1,  168,    2, 0x08 /* Private */,
      29,    1,  171,    2, 0x08 /* Private */,
      31,    0,  174,    2, 0x08 /* Private */,
      32,    1,  175,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 33,   34,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigError(); break;
        case 1: _t->sigOpen(); break;
        case 2: _t->sigStopMusic(); break;
        case 3: _t->sigHasPlaylist(); break;
        case 4: _t->sigNoPlaylist(); break;
        case 5: _t->sigSongChange(); break;
        case 6: _t->slotPlay(); break;
        case 7: _t->slotOpen(); break;
        case 8: _t->slotStopMusic(); break;
        case 9: _t->on_sliderLevelVolume_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_sliderProgress_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onPositionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->onDurationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_pbPauseMusic_clicked(); break;
        case 14: _t->on_pbNextSingiel_clicked(); break;
        case 15: _t->on_pbPreviousSingiel_clicked(); break;
        case 16: _t->on_pbDeleteSong_clicked(); break;
        case 17: _t->on_pbNewPlaylist_clicked(); break;
        case 18: _t->on_pbDeletePlaylist_clicked(); break;
        case 19: _t->on_listSongs_itemDoubleClicked(); break;
        case 20: _t->on_listPlaylists_itemDoubleClicked(); break;
        case 21: _t->on_currentMediaChanged((*reinterpret_cast< const QMediaContent(*)>(_a[1]))); break;
        case 22: _t->on_radioButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->on_pbVisualisation_clicked(); break;
        case 24: _t->processBuffer((*reinterpret_cast< QAudioBuffer(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaContent >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioBuffer >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sigError)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sigOpen)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sigStopMusic)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sigHasPlaylist)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sigNoPlaylist)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sigSongChange)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sigError()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::sigOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::sigStopMusic()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::sigHasPlaylist()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::sigNoPlaylist()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::sigSongChange()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
