/****************************************************************************
** Meta object code from reading C++ file 'twitterbackendinterface.h'
**
** Created: Fri Jun 20 01:50:53 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../twitterbackendinterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'twitterbackendinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_twitterBackendInterface[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   24,   24,   24, 0x0a,
      68,   24,   24,   24, 0x0a,
      87,   24,   24,   24, 0x0a,
     103,   24,   24,   24, 0x0a,
     116,   24,   24,   24, 0x0a,
     125,   24,   24,   24, 0x0a,
     135,   24,   24,   24, 0x0a,
     145,   24,   24,   24, 0x0a,
     155,   24,   24,   24, 0x0a,
     167,   24,   24,   24, 0x0a,
     178,   24,   24,   24, 0x0a,
     189,   24,   24,   24, 0x0a,
     207,   24,   24,   24, 0x0a,
     214,   24,   24,   24, 0x0a,
     233,   24,   24,   24, 0x0a,
     256,   24,   24,   24, 0x0a,
     275,   24,   24,   24, 0x0a,
     295,   24,   24,   24, 0x0a,
     316,   24,   24,   24, 0x0a,
     330,   24,   24,   24, 0x0a,
     340,   24,   24,   24, 0x0a,
     358,   24,   24,   24, 0x0a,
     383,   24,   24,   24, 0x0a,
     401,   24,   24,   24, 0x0a,
     420,   24,   24,   24, 0x0a,
     429,   24,   24,   24, 0x0a,
     437,   24,   24,   24, 0x0a,
     454,   24,   24,   24, 0x0a,
     472,   24,   24,   24, 0x0a,
     479,   24,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_twitterBackendInterface[] = {
    "twitterBackendInterface\0\0"
    "public_timeline(QString)\0public_timeline()\0"
    "friends_timeline()\0user_timeline()\0"
    "showStatus()\0update()\0replies()\0"
    "destroy()\0friends()\0followers()\0"
    "featured()\0showUser()\0direct_messages()\0"
    "sent()\0newDirectMessage()\0"
    "destroyDirectMessage()\0createFriendship()\0"
    "destroyFriendship()\0verify_credentials()\0"
    "end_session()\0archive()\0update_location()\0"
    "update_delivery_device()\0createFavourite()\0"
    "destroyFavourite()\0follow()\0leave()\0"
    "createBlockage()\0destroyBlockage()\0"
    "test()\0downtime_schedule()\0"
};

const QMetaObject twitterBackendInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_twitterBackendInterface,
      qt_meta_data_twitterBackendInterface, 0 }
};

const QMetaObject *twitterBackendInterface::metaObject() const
{
    return &staticMetaObject;
}

void *twitterBackendInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_twitterBackendInterface))
	return static_cast<void*>(const_cast< twitterBackendInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int twitterBackendInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: public_timeline((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: public_timeline(); break;
        case 2: friends_timeline(); break;
        case 3: user_timeline(); break;
        case 4: showStatus(); break;
        case 5: update(); break;
        case 6: replies(); break;
        case 7: destroy(); break;
        case 8: friends(); break;
        case 9: followers(); break;
        case 10: featured(); break;
        case 11: showUser(); break;
        case 12: direct_messages(); break;
        case 13: sent(); break;
        case 14: newDirectMessage(); break;
        case 15: destroyDirectMessage(); break;
        case 16: createFriendship(); break;
        case 17: destroyFriendship(); break;
        case 18: verify_credentials(); break;
        case 19: end_session(); break;
        case 20: archive(); break;
        case 21: update_location(); break;
        case 22: update_delivery_device(); break;
        case 23: createFavourite(); break;
        case 24: destroyFavourite(); break;
        case 25: follow(); break;
        case 26: leave(); break;
        case 27: createBlockage(); break;
        case 28: destroyBlockage(); break;
        case 29: test(); break;
        case 30: downtime_schedule(); break;
        }
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void twitterBackendInterface::public_timeline(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
