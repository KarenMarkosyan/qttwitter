/****************************************************************************
** Meta object code from reading C++ file 'mainwindowimpl.h'
**
** Created: Fri Jun 20 01:50:50 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainWindow/mainwindowimpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindowImpl[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      34,   15,   15,   15, 0x05,
      45,   15,   15,   15, 0x05,
      66,   15,   15,   15, 0x05,
      84,   15,   15,   15, 0x05,
     107,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     125,   15,   15,   15, 0x0a,
     135,   15,   15,   15, 0x0a,
     149,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindowImpl[] = {
    "MainWindowImpl\0\0showLoginScreen()\0"
    "doLogout()\0showPublicTimeline()\0"
    "showOwnTimeline()\0showFollowerTimeline()\0"
    "showFriendsline()\0doPrint()\0showAboutQt()\0"
    "showAboutQtTwitter()\0"
};

const QMetaObject MainWindowImpl::staticMetaObject = {
    { &mainWindowDerived::staticMetaObject, qt_meta_stringdata_MainWindowImpl,
      qt_meta_data_MainWindowImpl, 0 }
};

const QMetaObject *MainWindowImpl::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindowImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowImpl))
	return static_cast<void*>(const_cast< MainWindowImpl*>(this));
    if (!strcmp(_clname, "Ui::MainWindow"))
	return static_cast< Ui::MainWindow*>(const_cast< MainWindowImpl*>(this));
    return mainWindowDerived::qt_metacast(_clname);
}

int MainWindowImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = mainWindowDerived::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showLoginScreen(); break;
        case 1: doLogout(); break;
        case 2: showPublicTimeline(); break;
        case 3: showOwnTimeline(); break;
        case 4: showFollowerTimeline(); break;
        case 5: showFriendsline(); break;
        case 6: doPrint(); break;
        case 7: showAboutQt(); break;
        case 8: showAboutQtTwitter(); break;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MainWindowImpl::showLoginScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainWindowImpl::doLogout()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindowImpl::showPublicTimeline()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainWindowImpl::showOwnTimeline()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainWindowImpl::showFollowerTimeline()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MainWindowImpl::showFriendsline()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
