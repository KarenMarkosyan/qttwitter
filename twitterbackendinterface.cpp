#include "twitterbackendinterface.h"
//
twitterBackendInterface::twitterBackendInterface(  ) 
	: QObject()
{
	// TODO
}
//
void twitterBackendInterface::public_timeline(/*int since_id*/)
{
	sendMessage="curl http://twitter.com/statuses/public_timeline.xml"; 
	myHttp.httpCall(sendMessage);
	//QString temp(curlCall.readAllStandardOutput());//making it qstring to show on line edit
	//connect(&myHttp,SIGNAL(outputOfHttpCall(QString)),this,SLOT(publc_timeline(QString)));
	qDebug()<<"publivc_timeline"; 
}
	void  twitterBackendInterface::friends_timeline(){
	qDebug()<<" friends";
	}
	void  twitterBackendInterface::user_timeline(){
	qDebug()<<"user ";
	}
	void  twitterBackendInterface::showStatus(){
		
	}
	void twitterBackendInterface::update(){
		
	}
	void  twitterBackendInterface::replies(){
		
	}
	void  twitterBackendInterface::destroy(){
		
	}
	void  twitterBackendInterface::friends(){
		
	}
	void  twitterBackendInterface::followers(){
		
	}
	void  twitterBackendInterface::featured(){
		
	}
	void  twitterBackendInterface::showUser(){
		
	}
	void  twitterBackendInterface::direct_messages(){
		
	}
	void  twitterBackendInterface::sent(){
		
	}
	void  twitterBackendInterface::newDirectMessage(){
		
	}
	void  twitterBackendInterface::destroyDirectMessage(){
		
	}
	void  twitterBackendInterface::createFriendship(){
		
	}
	void  twitterBackendInterface::destroyFriendship(){
		
	}
	void  twitterBackendInterface::verify_credentials(){
		
	}
	void  twitterBackendInterface::end_session(){
		
	}
	void  twitterBackendInterface::archive(){
		
	}
	void  twitterBackendInterface::update_location(){
		
	}
	void  twitterBackendInterface::update_delivery_device(){
		
	}
	void  twitterBackendInterface::createFavourite(){
		
	}
	void  twitterBackendInterface::destroyFavourite(){
		
	}
	void  twitterBackendInterface::follow(){
		
	}
	void  twitterBackendInterface::leave(){
		
	}
	void  twitterBackendInterface::createBlockage(){
		
	}
	void  twitterBackendInterface::destroyBlockage(){
		
	}
	void  twitterBackendInterface::test(){
		
	}
	void  twitterBackendInterface::downtime_schedule(){
		
	}