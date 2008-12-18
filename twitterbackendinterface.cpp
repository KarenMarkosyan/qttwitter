#include "twitterbackendinterface.h"
#include <QDebug>
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
  m_twitLib->GetFriendsTimeline();
  qDebug() << " friends";
}

void  twitterBackendInterface::user_timeline()
{
  m_twitLib->GetUsersTimeline();
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
  m_twitLib->GetFriends();
}

void  twitterBackendInterface::followers()
{
  m_twitLib->GetFollowers();
}

void  twitterBackendInterface::featured()
{
}

void  twitterBackendInterface::showUser()
{
}

void  twitterBackendInterface::direct_messages()
{
  m_twitLib->GetSentDirectMessages();
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
  m_twitLib->IsTwitterUp();
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
  
}
void twitterBackendInterface::OnResponseReceived(Returnables::Response *resp)
{
//   qDebug()<<"status recived"<<resp->reqID;
  qDebug()<<"i am here inOneResponserecived \n";

  if(resp)
  {
    switch(resp->reqID)
    {
      case Returnables::PUBLIC_TIMELINE:
      {
        Returnables::PublicTimeline *pTimeline = static_cast<Returnables::PublicTimeline *>(resp);
        DisplayList(pTimeline->list, "Public Timeline");
        delete pTimeline;
        break;
      }
    
     case Returnables::LOGIN:
      {
        qDebug()<<"1reached here";
        Returnables::Login *login = static_cast<Returnables::Login *>(resp);
        QString authorized = login->authorized ? "true" : "false";
//      m_plainTextEdit->appendPlainText("Authorized: "+authorized);
        qDebug()<<"Authorized: "<<authorized;
        delete login;
        break;
      }
      case Returnables::FRIENDS_TIMELINE:
      {
        Returnables::FriendsTimeline *fTimeline = static_cast<Returnables::FriendsTimeline *>(resp);
        DisplayList(fTimeline->list, "Friends Timeline");
        delete fTimeline;
        break;
      }
      case Returnables::USER_TIMELINE:
      {
        Returnables::UserTimeline *userTimeline = static_cast<Returnables::UserTimeline *>(resp);
        DisplayList(userTimeline->list, "Users Timeline");
        delete userTimeline;
        break;
      }
    
    
    } 
  }

}

void twitterBackendInterface::DisplayList(QLinkedList<Returnables::StatusUser*> list, QString header)
{
  Returnables::StatusUser *statusUser = NULL;
  QString value="";

  while(list.isEmpty() == FALSE )
  {
    statusUser = list.takeFirst ();
//     value="ID:"+QString::number(statusUser->status.id) ;
    value+="<b>"+statusUser->user.screenName+ "</b>"" twittered \" ";
    value+=statusUser->status.text +" \" <br>";

  }
          emit(public_timeline(value));

}
void twitterBackendInterface::setUserNamePassword(QString user , QString password)
{
  m_twitLib->Login(user,password);
//   qDebug()<<user<<password;
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
