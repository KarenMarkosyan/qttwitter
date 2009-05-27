#include "twitterbackendinterface.h"
#include <QDebug>

twitterBackendInterface::twitterBackendInterface( )
        : QObject()
{
    m_twitLib = new QTwitLib ;
    isLogin = false;
    lastTweeter = new QString();
    lastTweet = new QString();

    //Creating a timer to fetch the public timeline periodically, this can be later made to fetch at a user specified interval
    timerPublicTweet = new QTimer( this );
    timerPublicTweet->setInterval( 60000 ); //This shall be the timeout for tweet retrieval in milliseconds
    connect(timerPublicTweet, SIGNAL( timeout() ), this, SLOT( public_timeline() ) );

    //On similar pattern the timer for the other two timelines can be created viz. timerFriendsTweet and timerUserTweet

    connect(m_twitLib,SIGNAL(OnResponseReceived(Returnables::Response *)),this,SLOT(OnResponseReceived(Returnables::Response *)));
}

void twitterBackendInterface::public_timeline ( /*int since_id*/ )
{
    m_twitLib->GetPublicTimeline();
    qDebug() << "public_timeline";
}

void twitterBackendInterface::setUserNamePassword(QString user , QString password)
{
    m_twitLib->Login(user, password);
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

void twitterBackendInterface::update(QString status)
{
    qDebug() << "In the method update() status";
    m_twitLib->PostNewStatus(status);
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

//This is the response handler from the QTwitLib handling all the enums from Returnables::
void twitterBackendInterface::OnResponseReceived(Returnables::Response *resp)
{
    qDebug()<<"i am here in OnResponseRecieved() with request ID"/*<<resp->reqID*/;

    if(resp)
    {
        switch(resp->reqID)
        {
            case Returnables::PUBLIC_TIMELINE:
            {
                Returnables::PublicTimeline *pTimeline = static_cast<Returnables::PublicTimeline *>(resp);
                DisplayList(pTimeline->list, Returnables::PUBLIC_TIMELINE);
                delete pTimeline;
                break;
            }
            case Returnables::LOGIN:
            {
                qDebug()<<"reached here in Login case";
                Returnables::Login *login = static_cast<Returnables::Login *>(resp);
                QString authorized = login->authorized ? "true" : "false";
                //m_plainTextEdit->appendPlainText("Authorized: "+authorized);
                qDebug()<<"Authorized: "<<authorized;
                delete login;
                break;
            }
            case Returnables::FRIENDS_TIMELINE:
            {
                Returnables::FriendsTimeline *fTimeline = static_cast<Returnables::FriendsTimeline *>(resp);
                DisplayList(fTimeline->list, Returnables::FRIENDS_TIMELINE);
                delete fTimeline;
                break;
            }
            case Returnables::USER_TIMELINE:
            {
                Returnables::UserTimeline *userTimeline = static_cast<Returnables::UserTimeline *>(resp);
                DisplayList(userTimeline->list, Returnables::USER_TIMELINE);
                delete userTimeline;
                break;
            }
            //Other cases to be implemented soon
        }
    }
}


void twitterBackendInterface::DisplayList(QLinkedList<Returnables::StatusUser *> list, Returnables::RequestId reqId)
{
 /* Returnables::StatusUser *statusUser = NULL;
  QString value = "";
<<<<<<< .mine
  QString tweeter = "";
  qDebug() << statusUser->user.screenName;
  tweeter += (statusUser->user).screenName;
  QString tweet = "";
  tweet += (statusUser->status).text;

  QString tweeter = list->user.screenName;QString tweet = list->status.text;

  //Process the list here to extract information like UserStatus and the UserTweetText
  while(!list.isEmpty())
  {
    statusUser = list.takeFirst(); //taking the first status and user information from the list.
    //Here check for ducplicate entries, and if Unique send to the parser for formatting the tweet
    //The parser has not yet been implemented, so currently only sending the unformatted text
    if( tweeter.compare(*lastTweeter, Qt::CaseSensitive) && tweet.compare(*lastTweet, Qt::CaseSensitive) ){
        value += tweeter + " says\n\"" + tweet + "\"\n";
        *lastTweeter = tweeter;
        *lastTweet = tweet;
    if( tweeter != lastTweeter && tweet != lastTweet ){
       value = tweeter + " says\n\"" + tweet + "\"\n";
       lastTweeter = tweeter;
       lastTweet = tweet;
       value+=statusUser->status.text+"<br>";
       //The emit signal has been shifted here to see if still the signal crashes
       emit (public_timeline(value));
   }
    emit (public_timeline(value));

    //value="ID:"+QString::number(statusUser->status.id) ; //this line was supposed to be inside the if block

  }

    //The emit Signal was initially here, but now moved to the IF block.
    //The program used to crash until now. Pluasible reason being an empty 'value' getting passed
*/

//====================== Working Code Follows - Courtesy Shanky ====================

  Returnables::StatusUser *statusUser = NULL;
  TweetBubbleWidget *tweetBubble = NULL;
  QString value="See new gui";

  while (!(list.isEmpty())) {
    statusUser = list.takeLast();
    tweetBubble = new TweetBubbleWidget();
    tweetBubble->copyData(statusUser);
    emit (newGuiCreated(tweetBubble));

    /* Commented out to test the new GUI
    QString formattedTweet = statusUser->status.text;
    if (!formattedTweet.isEmpty()) {
        int j = 0;
        int l = 0;
        int h = 0;

        //HTTP Links Creation (currently only partially implemented)
        while ((l = formattedTweet.indexOf("http://", l)) != -1) {
            int n;
            if ( ((n = formattedTweet.indexOf("; ", l+7)) != -1) || ((n = formattedTweet.indexOf(", ", l+7)) != -1) || ((n = formattedTweet.indexOf(" ", l+7)) != -1) ) {
                formattedTweet.insert(n, "</A>");
                formattedTweet.insert(l, "<A href='" + formattedTweet.mid(l, n-l) + "'>");
                l = n + 9 + (n-l) + 2 + 4;
            }
            else {
                formattedTweet.append("</A>");
                formattedTweet.insert(l, "<A href='" + formattedTweet.mid(l, (formattedTweet.size()-4)-l) + "'>");
                l = -1;
            }
        }

        //@replies Links Creation
        while ((j = formattedTweet.indexOf("@", j)) != -1) {
            int k;
            if ( ((k = formattedTweet.indexOf(", ", j+1)) != -1) || ((k = formattedTweet.indexOf("; ", j+1)) != -1) || ((k = formattedTweet.indexOf(": ", j+1)) != -1) || ((k = formattedTweet.indexOf(" ", j+1)) != -1) ) {
                formattedTweet.insert(k, "</A>");
                formattedTweet.insert(j+1, "<A href='http://www.twitter.com/" + formattedTweet.mid(j+1, (k-1)-j) + "'>");
                j = k + 32 + (k-j) + 2 + 4;
            }
            else {
                formattedTweet.append("</A>");
                formattedTweet.insert(j+1, "<A href='http://www.twitter.com/" + formattedTweet.mid(j+1, ((formattedTweet.size()-1)-4)-j) + "'>");
                j = -1;
            }
        }

        //Hash Search Links Creation
        while ((h = formattedTweet.indexOf("#", h)) != -1) {
            int d = formattedTweet.indexOf(" ", h+1);
            if (d != -1) {
                formattedTweet.insert(d, "</A>");
                formattedTweet.insert(h+1, "<A href='http://search.twitter.com/search?q=" + formattedTweet.mid(h+1, (d-1)-h) + "'>");
                h = d + 44 + (d-h) + 2 + 4;
            }
            else {
                formattedTweet.append("</A>");
                formattedTweet.insert(h+1, "<A href='http://search.twitter.com/search?q=" + formattedTweet.mid(h+1, ((formattedTweet.size()-1)-4)-h) + "'>");
                h = -1;
            }
        }
    }

    value += "<b>" + statusUser->user.screenName + "</b>" + " twittered \" ";
    value += formattedTweet + " \" <br>";*/
  }

  switch (reqId) {
  case Returnables::PUBLIC_TIMELINE:
      {
          emit (public_timeline(value));
          break;
      }
  case Returnables::FRIENDS_TIMELINE:
      {
          emit (friends_timeline(value));
          break;
      }
  case Returnables::USER_TIMELINE:
      {
          emit (user_timeline(value));
          break;
      }

  default:
      {
          emit (public_timeline(value));
          break;
      }
  }
}

/*
void twitterBackendInterface::OnLoginStatus ( bool isLoggedIn )
{
    if ( isLoggedIn )
    {
        isLogin = TRUE;
    }
    else
    {
        isLogin = FALSE;
    }
}
*/
