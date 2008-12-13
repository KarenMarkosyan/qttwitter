#include "twitterbackendinterface.h"

twitterBackendInterface::twitterBackendInterface( )
        : QObject()
{
    m_twitLib = new QTwitLib ;
    isLogin = false;
    timerPublicTweet = new QTimer( this );
    timerPublicTweet->setInterval( 5000 ); //This shall be the timeout for tweet retrieval
    connect(timerPublicTweet, SIGNAL( timeout() ), this, SLOT( public_timeline() ) );
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
  
}

//Abhijeet thinks This is the message handler here that handles all the messages from the qDebug() module
void twitterBackendInterface::OnResponseReceived(Returnables::Response *resp)
{
//   qDebug()<<"status recived";
  
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
    }
  }
      
  
}

void twitterBackendInterface::DisplayList(QLinkedList<Returnables::StatusUser *> list, QString header)
{
  Returnables::StatusUser *statusUser = NULL;
  QString value;

  //Process the list here to extract information like UserStatus and the UserTweetText
  while(!list.isEmpty())
  {
    statusUser = list.takeFirst();
    //value="ID:"+QString::number(statusUser->status.id) ;
    value = statusUser->user.screenName+"\n says \" ";
    value += statusUser->status.text +"\"\n\n";

  }
          emit(public_timeline(value));

}
void twitterBackendInterface::setUserNamePassword(QString user , QString password)
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
