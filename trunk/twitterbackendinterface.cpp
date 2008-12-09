#include "twitterbackendinterface.h"
//
twitterBackendInterface::twitterBackendInterface( )
        : QObject()
{
    m_twitLib = new QTwitLib ;
    isLogin = false;
    connect(m_twitLib,SIGNAL(OnResponseReceived(Returnables::Response *)),this,SLOT(OnResponseReceived(Returnables::Response *)));
}

//
void twitterBackendInterface::public_timeline ( /*int since_id*/ )
{
    m_twitLib->GetPublicTimeline();
    qDebug() << "public_timeline";
}

void  twitterBackendInterface::friends_timeline()
{
    qDebug() << " friends";
}

void  twitterBackendInterface::user_timeline()
{
    qDebug() << "user ";
}

void  twitterBackendInterface::showStatus()
{

}

void twitterBackendInterface::update()
{
}

void  twitterBackendInterface::replies()
{
}

void  twitterBackendInterface::destroy()
{
}

void  twitterBackendInterface::friends()
{
}

void  twitterBackendInterface::followers()
{
}

void  twitterBackendInterface::featured()
{
}

void  twitterBackendInterface::showUser()
{
}

void  twitterBackendInterface::direct_messages()
{
}

void  twitterBackendInterface::sent()
{
}

void  twitterBackendInterface::newDirectMessage()
{
}

void  twitterBackendInterface::destroyDirectMessage()
{
}

void  twitterBackendInterface::createFriendship()
{
}

void  twitterBackendInterface::destroyFriendship()
{
}

void  twitterBackendInterface::verify_credentials()
{
}

void  twitterBackendInterface::end_session()
{
}

void  twitterBackendInterface::archive()
{
}

void  twitterBackendInterface::update_location()
{
}

void  twitterBackendInterface::update_delivery_device()
{
}

void  twitterBackendInterface::createFavourite()
{
}

void  twitterBackendInterface::destroyFavourite()
{
}

void  twitterBackendInterface::follow()
{
}

void  twitterBackendInterface::leave()
{
}

void  twitterBackendInterface::createBlockage()
{
}

void  twitterBackendInterface::destroyBlockage()
{
}

void  twitterBackendInterface::test()
{
}

void  twitterBackendInterface::downtime_schedule()
{
}

void twitterBackendInterface::OnError(QString error)
{
}
void twitterBackendInterface::OnMessageReceived(QString message)
{
}
void twitterBackendInterface::OnStatusReceived(SERVER::RESP response)
{
  qDebug()<<"status recived";
}
void twitterBackendInterface::OnResponseReceived(Returnables::Response *)
{
}

// void twitterBackendInterface::OnLoginStatus ( bool isLoggedIn )
// {
//     if ( isLoggedIn )
//     {
//         isLogin = TRUE;
//     }
//     else
//     {
//         isLogin = FALSE;
//     }
// }
