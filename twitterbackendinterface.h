#ifndef TWITTERBACKENDINTERFACE_H
#define TWITTERBACKENDINTERFACE_H
#include <QObject>
#include <QDebug>
#include <twitlib/ITwitReply.h>
#include <twitlib/QTwitLib.h>

class twitterBackendInterface : public QObject , public ITwitReply
{
    Q_OBJECT

public:
    twitterBackendInterface();
    bool isLogin;
public slots:
    /*Twitter API SLots*/
    void  public_timeline ( /*int since_id*/ );//Primary
    void  friends_timeline();//Primary
    void  user_timeline();//Primary
    void  showStatus();
    void  update();//Primary
    void  replies();
    void  destroy();
    void  friends();
    void  followers();
    void  featured();
    void  showUser();
    void  direct_messages();
    void  sent();
    void  newDirectMessage();
    void  destroyDirectMessage();
    void  createFriendship();
    void  destroyFriendship();
    void  verify_credentials();
    void  end_session();
    void  archive();
    void  update_location();
    void  update_delivery_device();
    void  createFavourite();
    void  destroyFavourite();
    void  follow();//Primary
    void  leave();//Primary
    void  createBlockage();
    void  destroyBlockage();
    void  test();//Primary
    void  downtime_schedule();//Primary
    /*End OF twitter API Slots*/
    //void setUserNamePassword(QString,QString);

    //callback from libTwit
    void OnError ( std::string error );
    void OnMessageReceived ( std::string message );
    void OnStatusReceived ( SERVER::RESP response );
    void OnLoginStatus ( bool isLoggedIn );

signals:
    void public_timeline ( QString );
    void statusMessage ( QString id );//

private:
    QString sendMessage;
    QTwitLib  *m_twitLib;
};

namespace Backend
{

class twitterBackend: public twitterBackendInterface {};
}
#endif
