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

        if (resp) {
                switch (resp->reqID) {
                case Returnables::PUBLIC_TIMELINE: {
                        Returnables::PublicTimeline *pTimeline = static_cast<Returnables::PublicTimeline *>(resp);
                        DisplayList(pTimeline->list, Returnables::PUBLIC_TIMELINE);
                        delete pTimeline;
                        break;
                }
                case Returnables::VERIFY_CREDENTIALS: {
                        qDebug()<<"reached here in Login case";
//                 Returnables::VERIFY_CREDENTIALS *login = static_cast<Returnables::VERIFY_CREDENTIALS *>(resp);
//                 QString authorized = login->authorized ? "true" : "false";
//                 //m_plainTextEdit->appendPlainText("Authorized: "+authorized);
//                 qDebug()<<"Authorized: "<<authorized;
//                 delete login;

                        break;
                }
                case Returnables::FRIENDS_TIMELINE: {
                        Returnables::FriendsTimeline *fTimeline = static_cast<Returnables::FriendsTimeline *>(resp);
                        DisplayList(fTimeline->list, Returnables::FRIENDS_TIMELINE);
                        delete fTimeline;
                        break;
                }
                case Returnables::USER_TIMELINE: {
                        Returnables::UserTimeline *userTimeline = static_cast<Returnables::UserTimeline *>(resp);
                        DisplayList(userTimeline->list, Returnables::USER_TIMELINE);
                        delete userTimeline;
                        break;
                }
                case Returnables::NEW_STATUS: {
                        Returnables::NewStatus *newStatus = static_cast<Returnables::NewStatus *>(resp);
                        /*           QLinkedList<Returnables::StatusElement*> list;
                                   list.append(newStatus->status);
                                   DisplayList(list, "New Status");
                        */
                        delete newStatus;
                        break;
                }
                case Returnables::RECENT_MENTIONS: {
                        Returnables::RecentMentions *mentions = static_cast<Returnables::RecentMentions *>(resp);
                        /*         DisplayList(mentions->list, "Recent Mentions");
                        */
                        delete mentions;
                        break;
                }
                case Returnables::REMOVE_STATUS: {
                        Returnables::RemoveStatus *removedStatus = static_cast<Returnables::RemoveStatus *>(resp);
                        /*       QLinkedList<Returnables::StatusElement*> list;
                               list.append(removedStatus->status);
                               DisplayList(list, "Remove Status");
                        */
                        delete removedStatus;
                        break;
                }
                case Returnables::FRIENDS: {
                        Returnables::Friends *friends = static_cast<Returnables::Friends *>(resp);
                        /*     DisplayList(friends->list, "Friends");
                        */
                        delete friends;
                        break;
                }
                case Returnables::FOLLOWERS: {
                        Returnables::Followers *followers = static_cast<Returnables::Followers *>(resp);
                        /*   DisplayList(followers->list, "Followers");
                        */
                        delete followers;
                        break;
                }
                case Returnables::USER_DETAILS: {
                        Returnables::UserDetails *userDetails = static_cast<Returnables::UserDetails *>(resp);
                        /* QLinkedList<Returnables::ExtUserInfoElement*> list;
                         list.append(userDetails->userExt);
                         DisplayList(list, "User Details");
                        */
                        delete userDetails;
                        break;
                }

                case Returnables::SENT_DIRECT_MESSAGES: {
                        Returnables::SentDirectMessages *sentDirectMessages = static_cast<Returnables::SentDirectMessages *>(resp);
                        /*DisplayList(sentDirectMessages->list, "Sent Direct Messages");
                        */
                        delete sentDirectMessages;
                        break;
                }
                case Returnables::RECEIVED_DIRECT_MESSAGES: {
                        Returnables::ReceivedDirectMessages *receivedDirectMessages = static_cast<Returnables::ReceivedDirectMessages *>(resp);
                        /*DisplayList(receivedDirectMessages->list, "Received Direct Messages");
                        */
                        delete receivedDirectMessages;
                        break;
                }
                case Returnables::SEND_DIRECT_MESSAGE: {
                        Returnables::SendDirectMessage *sendDirectMessage = static_cast<Returnables::SendDirectMessage *>(resp);
                        /* m_plainTextEdit->appendHtml("<h2>Send Direct Messages</h2>");
                         m_plainTextEdit->appendPlainText("");
                         m_plainTextEdit->appendPlainText("ID: "+QString::number(sendDirectMessage->message->headerInfo.id));
                         m_plainTextEdit->appendPlainText("Sender: "+sendDirectMessage->message->sender.screenName);
                         m_plainTextEdit->appendPlainText("Recipient: "+sendDirectMessage->message->recipient.screenName);
                         m_plainTextEdit->appendPlainText("Created At: "+sendDirectMessage->message->headerInfo.createdAt);
                         m_plainTextEdit->appendPlainText("Text: "+sendDirectMessage->message->headerInfo.text);
                        */
                        delete sendDirectMessage;
                        break;
                }
                case Returnables::REMOVE_DIRECT_MESSAGE: {
                        Returnables::RemoveDirectMessage *removeDirectMessage = static_cast<Returnables::RemoveDirectMessage *>(resp);
                        /*m_plainTextEdit->appendHtml("<h2>Remove Direct Messages</h2>");
                        m_plainTextEdit->appendPlainText("");
                        m_plainTextEdit->appendPlainText("ID: "+QString::number(removeDirectMessage->message->headerInfo.id));
                        m_plainTextEdit->appendPlainText("Sender: "+removeDirectMessage->message->sender.screenName);
                        m_plainTextEdit->appendPlainText("Recipient: "+removeDirectMessage->message->recipient.screenName);
                        m_plainTextEdit->appendPlainText("Created At: "+removeDirectMessage->message->headerInfo.createdAt);
                        m_plainTextEdit->appendPlainText("Text: "+removeDirectMessage->message->headerInfo.text);
                        */
                        delete removeDirectMessage;
                        break;
                }
                case Returnables::ADD_FRIENDSHIP: {
                        Returnables::AddFriendship *addFriendship = static_cast<Returnables::AddFriendship *>(resp);
                        /*QLinkedList<Returnables::BasicUserInfoElement*> list;
                        list.append(addFriendship->user);
                        DisplayList(list, "Add Friendship");
                        */
                        delete addFriendship;
                        break;
                }
                case Returnables::REMOVE_FRIENDSHIP: {
                        Returnables::RemoveFriendship *removeFriendship = static_cast<Returnables::RemoveFriendship *>(resp);
                        /*QLinkedList<Returnables::BasicUserInfoElement*> list;
                        list.append(removeFriendship->user);
                        DisplayList(list, "Remove Friendship");
                        */
                        delete removeFriendship;
                        break;
                }
                case Returnables::FRIENDSHIP_EXISTS: {
                        Returnables::FriendshipExist *friendshipExists = static_cast<Returnables::FriendshipExist *>(resp);
                        /* m_plainTextEdit->appendHtml("<h2>Friendship Exist</h2>");
                         m_plainTextEdit->appendPlainText("");
                         QString friends = friendshipExists->friends ? "true" : "false";
                         m_plainTextEdit->appendPlainText("Are Friends?: "+friends);
                        */
                        delete friendshipExists;
                        break;
                }
                case Returnables::DELIVERY_DEVICE: {
                        Returnables::DeliveryDevice *deliveryDevice = static_cast<Returnables::DeliveryDevice *>(resp);
                        /*QLinkedList<Returnables::BasicUserInfoElement*> list;
                        list.append(deliveryDevice->user);
                        DisplayList(list, "Update Delivery Device");
                        */
                        delete deliveryDevice;
                        break;
                }
                case Returnables::API_REQUESTS: {
                        Returnables::ApiRequests *apiRequests = static_cast<Returnables::ApiRequests *>(resp);
                        /*m_plainTextEdit->appendHtml("<h2>Remaining API requests</h2>");
                        m_plainTextEdit->appendPlainText("");
                        m_plainTextEdit->appendPlainText("Hourly Limit: "+QString::number(apiRequests->hourlyLimit));
                        m_plainTextEdit->appendPlainText("Remaining hits: "+QString::number(apiRequests->remainingHits));
                        m_plainTextEdit->appendPlainText("Reset time: "+apiRequests->resetTime);
                        m_plainTextEdit->appendPlainText("Reset time in seconds: "+QString::number(apiRequests->resetTimeSeconds));
                        */
                        delete apiRequests;
                        break;
                }
                case Returnables::ADD_FAVORITE: {
                        Returnables::AddFavorite *addFavorite = static_cast<Returnables::AddFavorite *>(resp);
                        /*QLinkedList<Returnables::StatusElement*> list;
                        list.append(addFavorite->status);
                        DisplayList(list, "Add Favorite");
                        */
                        delete addFavorite;
                        break;
                }
                case Returnables::REMOVE_FAVORITE: {
                        Returnables::RemoveFavorite *removeFavorite = static_cast<Returnables::RemoveFavorite *>(resp);
                        /*QLinkedList<Returnables::StatusElement*> list;
                        list.append(removeFavorite->status);
                        DisplayList(list, "Remove Favorite");
                        */
                        delete removeFavorite;
                        break;
                }
                case Returnables::PROFILE_COLORS: {
                        Returnables::ProfileColors *profileColors = static_cast<Returnables::ProfileColors*>(resp);
                        /*QLinkedList<Returnables::ExtUserInfoElement*> list;
                        list.append(profileColors->userExt);
                        DisplayList(list, "Profile Colors");
                        */
                        delete profileColors;
                        break;
                }
                case Returnables::PROFILE_IMAGE: {
                        Returnables::ProfileImage *profileImage = static_cast<Returnables::ProfileImage*>(resp);
                        /*QLinkedList<Returnables::ExtUserInfoElement*> list;
                        list.append(profileImage->userExt);
                        DisplayList(list, "Profile Image");
                        */
                        delete profileImage;
                        break;
                }
                case Returnables::PROFILE_BACKGROUND_IMAGE: {
                        Returnables::ProfileBackgroundImage *profileBackgroundImage = static_cast<Returnables::ProfileBackgroundImage*>(resp);
                        /*QLinkedList<Returnables::ExtUserInfoElement*> list;
                        list.append(profileBackgroundImage->userExt);
                        DisplayList(list, "Profile Background Image");
                        */
                        delete profileBackgroundImage;
                        break;
                }
                case Returnables::PROFILE: {
                        Returnables::Profile *profile = static_cast<Returnables::Profile*>(resp);
                        /*QLinkedList<Returnables::ExtUserInfoElement*> list;
                        list.append(profile->userExt);
                        DisplayList(list, "Profile");
                        */
                        delete profile;
                        break;
                }
                case Returnables::FRIENDS_IDS: {
                        Returnables::FriendsIDs *friendsIDs = static_cast<Returnables::FriendsIDs*>(resp);
                        /*DisplayList(friendsIDs->list, "FriendsIDs");
                        */
                        delete friendsIDs;
                        break;
                }
                case Returnables::FOLLOWERS_IDS: {
                        Returnables::FollowersIDs *followersIDs = static_cast<Returnables::FollowersIDs*>(resp);
                        /* DisplayList(followersIDs->list, "FollowersIDs");
                        */
                        delete followersIDs;
                        break;
                }
                case Returnables::ENABLE_NOTIFICATIONS: {
                        Returnables::EnableNotifications *enableNotifications = static_cast<Returnables::EnableNotifications*>(resp);
                        /*QLinkedList<Returnables::BasicUserInfoElement*> list;
                        list.append(enableNotifications->user);
                        DisplayList(list, "Enable Notifications");
                        */
                        delete enableNotifications;
                        break;
                }
                case Returnables::DISABLE_NOTIFICATIONS: {
                        Returnables::DisableNotifications *disableNotifications = static_cast<Returnables::DisableNotifications*>(resp);
                        /*QLinkedList<Returnables::BasicUserInfoElement*>list;
                        list.append(disableNotifications->user);
                        DisplayList(list, "Disable Notifications");
                        */
                        delete disableNotifications;
                        break;
                }
                case Returnables::BLOCK_USER: {
                        Returnables::BlockUser *blockUser = static_cast<Returnables::BlockUser*>(resp);
                        /*QLinkedList<Returnables::BasicUserInfoElement*> list;
                        list.append(blockUser->user);
                        DisplayList(list, "Block User");
                        */
                        delete blockUser;
                        break;
                }
                case Returnables::UNBLOCK_USER: {
                        Returnables::UnBlockUser *unBlockUser = static_cast<Returnables::UnBlockUser*>(resp);
                        /*QLinkedList<Returnables::BasicUserInfoElement*> list;
                        list.append(unBlockUser->user);
                        DisplayList(list, "UnBlock User");
                        */
                        delete unBlockUser;
                        break;
                }
                //TODO:Other cases to be implemented soon
                }
        }
}


void twitterBackendInterface::DisplayList(QLinkedList<Returnables::StatusElement*> list, Returnables::RequestId reqId)
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

        Returnables::StatusElement* statusUser = NULL;
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
        case Returnables::PUBLIC_TIMELINE: {
                emit (public_timeline(value));
                break;
        }
        case Returnables::FRIENDS_TIMELINE: {
                emit (friends_timeline(value));
                break;
        }
        case Returnables::USER_TIMELINE: {
                emit (user_timeline(value));
                break;
        }

        default: {
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
