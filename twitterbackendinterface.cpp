#include "twitterbackendinterface.h"
//
twitterBackendInterface::twitterBackendInterface(  )
                : QObject()
{

        myStoragePolicy = new CacheStoragePolicy ( "/root/.qttwitter/cache" );//FIXME do something about this also
        myDownloader = new HttpDownloadManager ( QUrl ( "http://twitter.com/" ) , myStoragePolicy );
        connect ( myDownloader, SIGNAL ( statusMessage ( QString ) ),this, SIGNAL ( statusMessage ( QString ) ) );
}
//
void twitterBackendInterface::public_timeline(/*int since_id*/)
{
        sendMessage="statuses/public_timeline.json";
        myDownloader->addJob(sendMessage,sendMessage);
        qDebug()<<"publivc_timeline";
}
void  twitterBackendInterface::friends_timeline()
{
        sendMessage="statuses/friends_timeline.json";
        myDownloader->addJob(sendMessage,sendMessage);
        qDebug()<<" friends";
}
void  twitterBackendInterface::user_timeline()
{
        sendMessage="statuses/user_timeline.json";
        myDownloader->addJob(sendMessage,sendMessage);
        qDebug()<<"user ";
}
void  twitterBackendInterface::showStatus()
{
        sendMessage="statuses/show/id.json";
        myDownloader->addJob(sendMessage,sendMessage);

}
void twitterBackendInterface::update()
{
        sendMessage="statuses/update.json";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::replies()
{
        sendMessage="statuses/replies.json";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::destroy()
{
        sendMessage="statuses/destroy/id.json";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::friends()
{
        sendMessage="statuses/friends.json";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::followers()
{
        sendMessage="statuses/followers.json";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::featured()
{
        sendMessage="statuses/featured.json";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::showUser()
{
        sendMessage="show/id.json";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::direct_messages()
{
        sendMessage="direct_messages.json";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::sent()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::newDirectMessage()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::destroyDirectMessage()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::createFriendship()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::destroyFriendship()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::verify_credentials()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::end_session()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::archive()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::update_location()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::update_delivery_device()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::createFavourite()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::destroyFavourite()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::follow()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::leave()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::createBlockage()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::destroyBlockage()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::test()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
void  twitterBackendInterface::downtime_schedule()
{
        sendMessage="";
        myDownloader->addJob(sendMessage,sendMessage);
}
