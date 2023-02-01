/****************************************************************************
** Meta object code from reading C++ file 'addmenu.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../OOOPLab2/addmenu.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_AddMenu_t {
    uint offsetsAndSizes[18];
    char stringdata0[8];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[27];
    char stringdata5[6];
    char stringdata6[25];
    char stringdata7[12];
    char stringdata8[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AddMenu_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_AddMenu_t qt_meta_stringdata_AddMenu = {
    {
        QT_MOC_LITERAL(0, 7),  // "AddMenu"
        QT_MOC_LITERAL(8, 8),  // "addTimer"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 8),  // "addAlarm"
        QT_MOC_LITERAL(27, 26),  // "showHideExecuteProgramPath"
        QT_MOC_LITERAL(54, 5),  // "check"
        QT_MOC_LITERAL(60, 24),  // "showHideOpenDocumentPath"
        QT_MOC_LITERAL(85, 11),  // "findProgram"
        QT_MOC_LITERAL(97, 12)   // "findDocument"
    },
    "AddMenu",
    "addTimer",
    "",
    "addAlarm",
    "showHideExecuteProgramPath",
    "check",
    "showHideOpenDocumentPath",
    "findProgram",
    "findDocument"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_AddMenu[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    1,   52,    2, 0x08,    3 /* Private */,
       6,    1,   55,    2, 0x08,    5 /* Private */,
       7,    0,   58,    2, 0x08,    7 /* Private */,
       8,    0,   59,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AddMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_AddMenu.offsetsAndSizes,
    qt_meta_data_AddMenu,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_AddMenu_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AddMenu, std::true_type>,
        // method 'addTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addAlarm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showHideExecuteProgramPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'showHideOpenDocumentPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'findProgram'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'findDocument'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AddMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addTimer(); break;
        case 1: _t->addAlarm(); break;
        case 2: _t->showHideExecuteProgramPath((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->showHideOpenDocumentPath((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->findProgram(); break;
        case 5: _t->findDocument(); break;
        default: ;
        }
    }
}

const QMetaObject *AddMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddMenu.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AddMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
