/*
[Mon Mar 10 01:45:45 2008]
still to do:: 
(1)make things work...connection of derived ui class is not wokring that's why when linedit change no data is end to backend..
(2)convert qstring to char
(3)implement a system tray icon for this program,,its absolute necessary for this kind of program
(4)ask for login anme password instead of just hardcoidn it..better still ask once save it 

[Mon Mar 10 09:42:06 2008]
connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
putting this line craets a segmentation fault on execution,,now this ismy first stumbling block

[Mon Mar 17 23:15:17 2008]
class uiSendDerived :public QObject , public Ui_sendTwit
{
public:
uiSendDerived(){connect(buttonBox, SIGNAL(accepted()), this, SLOT(me())); }//constructor

void accept(){qDebug()<<"ere";emit getFromUi(lineEdit->text());qDebug()<<lineEdit->text();};

}
is part of the solution/problem
[Mon Mar 17 23:31:48 2008]
most of the things are wokring thanks to rishabh and his usefull input ...now i am only a step behind completing this project
[Mon Mar 17 23:46:17 2008]
Adding Login/password Information
[Tue Mar 18 22:06:28 2008]
// sendMessage="curl -u ";
// sendMessage+=login;
// sendMessage+=":";
// sendMessage+=password;
// sendMessage+=" -s -F status= \"";
// sendMessage+=message;
// sendMessage+="\" http://twitter.com/statuses/update.xml";

sendMessage="curl -u login_name:password -s -F status=\"?\" http://twitter.com/statuses/update.xml";

Well to cut to the chase,, themessage commented is not send even though though being equal to the message just below it

[Tue Mar 18 22:55:51 2008]
fianlly i wa sable to send messages
[Tue Mar 18 22:58:54 2008]
finally login name and password features are also working :D
going to implement 
(1)Login Name Password  Save Feature --done
(2)All The Timelines --done
(4)System tray integration
(4.1)show result of each http transaction or atleast a progress bar
(3)Display Extracted Output from all the xml replies from twitter.com --still planning
(6)polish (I)get images in rc file (II)polish coding & comment (III)Testing
(4.5)change from waitforFinished() in call to curl to something that's non blocking
(5)introduce encryption to save login/password in qsetting
[Wed Mar 19 02:45:04 2008]
working on password /login name save feature
[Wed Mar 19 03:05:21 2008]
finallylogin name and password are being saved , now going in for all the timelines..but right now i am just concerned with downlaoding their respective xml files ,,no xml file crunching right now
yikes.....that would sure would look ugly
[Wed Mar 19 03:37:01 2008]
still struck with login password thing ...check box had to be shown checked if password was apparently that has cause some problems with saving fucntion
[Wed Mar 19 03:48:15 2008]
login screen is wokring perfectly... now timeline is being implemented
[Wed Mar 19 04:32:36 2008]
void timelineDisplay::getFriendsTimeLine()//complete but not tested
void timelineDisplay::getPublicTimeLine()//complete but not tested
[Wed Mar 19 05:40:03 2008]
still working on timlines..with some suitable progress.
[Wed Mar 19 05:47:07 2008]
ONLY 2timlines out 4 are wokring..aah login and password were blank :)
[Wed Mar 19 07:49:49 2008]
login and password not updating themselevs in gettimelivnes class..and that causes authentication failure
[Thu Mar 20 19:33:58 2008]
all the timelines are wokring
[Thu Mar 20 19:53:08 2008]
going in for system tray integration ,for some mysterious reason timelines are not coming xml format they are rather coming in plain text format
[Fri Apr 25 06:19:28 2008]
working on version 2 of this program with main windows approach
[Fri Apr 25 06:58:14 2008]
completed system tray menu +icon integration to the program
[Sat Apr 26 03:59:08 2008]
just working for some minor changes
parentWindow.showMessage("testing"); is working so messages are being shown in aprpriate places :)
[Mon Apr 28 05:09:55 2008]
did some beautification with icons :)
[Mon Apr 28 07:10:18 2008]
facing some intersting kind of problem... mainWindowImpl class is just emitting signals..i m
mean it doesn't give nay error ,,but it refuses to geenrate signals even if told to do so...
i will have to rewrite the class..though it's base class is not facing any kind of prblem
[Mon Apr 28 07:51:22 2008]
finally the problem is solved ,, by making the mainwindowsimplementation class inheriting the modified system tray giving mainwindwos class and 
the Ui mian window class...actually due to earlier coding the ui windows' event loop was being hijacked now it is derived hence 
the new class has properties of both
eureka
[Wed Apr 30 10:49:20 2008]
added twitter backend interface class...this class is supposed to include allt he backned 
abstraction ,,i mena this class will fianlly be implementing all the features of twitter API,,
and it would abstratc all thing like 
[Wed Apr 30 12:23:10 2008]
curl -u login:password http://twitter.com/account/verify_credentials.json ; echo " "
{"authorized":true}
[Wed Apr 30 15:40:00 2008]
finally somehow have declared a barebone structure for twittr backend ..the header file was too repetetive
[Sat May 3 05:12:51 2008]
working once again...just to make http class work,no idea how t make a abstratc http classso let's stick to making ui 
first (updated Sat May 3 06:58:24 2008)
[Mon Jun 23 11:21:33 2008]
started working on qttwitter just few days back... right now i ported Http dwonlaoding  code Marble () to qttwitter and is planning to port more code like the webbrowser.
[Mon Jun 23 13:36:24 2008]
added image browser to test it,, i am trying to make a panoramio image browser ,, which finally find it's place in marble ,rught now this is testing place for it
]

[Fri Oct 24 04:15:32 2008]
removed all the trash codes that had accumulated all along..
now this program is using qttwit lib.. this removes pressure on me to develop library on my own :P
now i can develop a gui on it in much better way BTW  i also removed everything from HTTP directory as it's not required anymore..
this time i did some major cleanup ..and hence this code is now free of following 
(1)unnecessary code
(2)porn which accidentally started piling up in this directory :P :D
(3)open suse wallpapers 

[11:29:30 AM Wednesday, December 10 2008 ] 
finally i am working on intergating login in twitter .. i am planning to integrate laxis into this twitter client :)
..btw public twitter is working..but for some reason it doesn't gives more than 2 twitter at any moment.

[03:26:03 PM Friday, December 12 2008] even murli has joined us in our little project :D
adn apart from that this little project has now two types of ui..
though i am still working on stiching ui to backend..uhhh..it's real pain in arse
*/