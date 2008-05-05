#ifndef TWITTERBACKENDINTERFACE_H
#define TWITTERBACKENDINTERFACE_H
/**this class will include a snae backend network transparent interface to twitter API
i intend to provide functionality for all twitter api's here
API function to be implemented are::

/----Timeline-----/
public_timeline --http://twitter.com/statuses/public_timeline.json *
friends_timeline --http://twitter.com/statuses/friends_timeline.format
user_timeline --http://twitter.com/statuses/user_timeline.format *


/----User Methods-----/
show -- http://twitter.com/statuses/show/id.format (Returns a single status)=showStatus
update -- http://twitter.com/statuses/update.format (Updates the authenticating user's status)
replies -- http://twitter.com/statuses/replies.format
destroy -- http://twitter.com/statuses/destroy/id.format
friends -- http://twitter.com/statuses/friends.format
followers -- http://twitter.com/statuses/followers.format
featured -- http://twitter.com/statuses/featured.format
show -- http://twitter.com/users/show/id.format = showUser

/-----Messages-----/
direct_messages --http://twitter.com/direct_messages.format
sent --http://twitter.com/direct_messages/sent.format
new --http://twitter.com/direct_messages/new.format (Sends a new direct message)=newDirectMessage
destroy -- http://twitter.com/direct_messages/destroy/id.format (destroy a mesasge)

/------Friendship Methods---------/
create -- http://twitter.com/friendships/create/id.format=createFriendship
destroy -- http://twitter.com/friendships/destroy/id.format=destroyFriendship

/-------Account Methods-----------/
verify_credentials -- http://twitter.com/account/verify_credentials.format *
end_session -- http://twitter.com/account/end_session
archive -- http://twitter.com/account/archive.format
update_location
update_delivery_device

/--------Favorite Methods--------/
favorites -- http://twitter.com/favorites.format
create      ==createFavourite
destroy     ==destroyFavourite

/-------------Notification Methods----------/
follow
leave

/------------Block Methods-------------/
create  ==createBlockage
destroy ==destroyBlockage

/----------------Help Methods---------/
test
downtime_schedule
*/
#include <QObject>
#include <Http/http.h>
#include <QDebug>
//
class twitterBackendInterface : public QObject
{
Q_OBJECT
public:
	twitterBackendInterface();
public slots:
	/*Twitter API SLots*/	
	void  public_timeline(/*int since_id*/);//Primary 
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
	void setUserNamePassword(QString,QString);
signals:
	void public_timeline(QString);
private:
	QString sendMessage;
	Http myHttp;
};

namespace Backend{
    class twitterBackend: public twitterBackendInterface {};
}
#endif
