/* this program is developed on QDevelop -- a good Qt IDE by Jean - Luc Biord and others :) & Kdevelop also
qt used = Qt Open Source Edition version 4.4.1-snapshot-20080419.
on open suse 10.3
[02:53:53 PM Tuesday, December 09 2008] update i am using qt 4.4.3 and qt creator/kate/vim and ubuntu
*/
#include <QApplication>
#include "MainWindow/mainwindowimpl.h"
#include "loginDerived.h"
#include "sendTwitDerived.h"
#include "twitterbackendinterface.h"
// #include "imagebrowserimpl.h"
#include <QDialog>


int main(int argc,char **argv)
{
    //declarations
    QApplication app(argc,argv);

    //this is derived from ui file and the added functionality  system tray MainWindow Class
    MainWindowImpl mainWindow;

    // These containers are not required and are ambiguous
    // QDialog containerSendTwitDialog;
    QDialog containerImageBrowser;
    // QDialog containerLoginDialog;

    Ui::loginDialogDerived myLoginDialog;

    Ui::sendTwitDerived mySendTwitDialog;

    // Ui::imageBrowserimpl myImageBroswer; //not needed right now
    Backend::twitterBackend myTwitter;

    //==================================================================
    //connection slots
    //==================================================================
    QObject::connect(&mainWindow,SIGNAL(quit()),&app,SLOT(quit()));//just quit when you get quit signal

    //For displaying the Login Dialog Box..
    QObject::connect(mainWindow.actionLogin,SIGNAL(triggered()),&myLoginDialog,SLOT(show()));

    //For displaying the Send Tweet Dialog Box
    QObject::connect(mainWindow.actionSet_New_Status,SIGNAL(triggered()),&mySendTwitDialog,SLOT(show()));

    QObject::connect(mainWindow.actionPublic, SIGNAL(triggered()), &myTwitter, SLOT(public_timeline()));
    QObject::connect(mainWindow.actionFriends, SIGNAL(triggered()), &myTwitter, SLOT(friends_timeline()));
    QObject::connect(mainWindow.actionOwn, SIGNAL(triggered()), &myTwitter, SLOT(user_timeline()));


    //connecting the signal actionPublic to start the timer to auto-fetch the tweets after a fixed time interval
    QObject::connect(mainWindow.actionPublic, SIGNAL(triggered()), myTwitter.timerPublicTweet, SLOT(start()));
    //the slot to be later replaced by myTwitter.timerFriendsTweet->start();
    //QObject::connect(mainWindow.actionFriends, SIGNAL(triggered()), &myTwitter, SLOT(friends_timeline()));
    // the slot to be later replaced by myTwitter.timerUserTweet->start();
    //QObject::connect(mainWindow.actionOwn, SIGNAL(triggered()), &myTwitter, SLOT(user_timeline()));

    QObject::connect(mainWindow.actionView_Images_From_Area,SIGNAL(triggered()),&containerImageBrowser,SLOT(show()));

    //login connection
    QObject::connect(&myLoginDialog, SIGNAL(setUserPassword(QString,QString)), &myTwitter, SLOT(setUserNamePassword(QString,QString)));


    //Displaying the Public Timeline messages to the respective tab
    QObject::connect(&myTwitter, SIGNAL(public_timeline(QString)), mainWindow.textBrowserPT, SLOT(append(QString)) );

    //Raising the tab when the respective message is displayed, but this is just a temporary action, (wont work probably)
    QObject::connect(mainWindow.actionPublic, SIGNAL(triggered()), mainWindow.tabPublicTimeline, SLOT(raise()));


    //QObject::connect(mainWindow.action,SIGNAL(triggered()),&myTwitter,SLOT());
    //property setting
    //temporarily disabling the setupUi thing for the LOgin Dialog
    //Disabling this unnecessary thing actually made the Loging Box thing work where the password box remained disabled
    //even after calling setEnabled thing. So I propose that even this ambiguous container for sendTwit is not reqd.
    // myLoginDialog.setupUi(&containerLoginDialog);
    // mySendTwitDialog.setupUi(&containerSendTwitDialog);
    QObject::connect(mainWindow.actionQuit, SIGNAL(triggered()), &app, SLOT(quit()));

    //just a temporary putting of a lot of text to the public timeline to check the transparency
    mainWindow.textBrowserPT->append("la jlfjalsd kjflasklsdkj lsdlfj lasdkjflksjdlfkjlaskdjflkjasldkfjlaksjflkjaslkdfjlaksjdflkjsldkjflkajsdlfkjlaskjflkjasld fioewjcodjflakdsfjc ladskjfl kadslfkjladsfljldskjflkjaslfjalsdkfjlksjdflajslfjlajsfoepwfijofkdnfk gjfdksjgh kjkjdfhgkjfhg kdfhg; akd;h ;  ahadskgh orit erihv ierh ierh ieru hgierghikj skdkdfjgkdfjgh wpeiorhg ierwohghaakhdhadfkjh kjhagjkhgperi adgfk jhgkja gdkjhg akdhierhiurethkhkljadgh kajhgkalh irht iert herth rkejth kajdfg kjadkgh ahfrithwieruthkj ghlskjdfh a;kdfh;gf oierth eiruh tkjdghdskj gkladjghkrehiwerh ver r       weriutiowuert ioertrt eroitoir tewrutpowieurtoiuweorituowruotiowurtoiwurtoiwer   eri toiurtoie ri or towiert oeur hfkjghskdfjghk kjdfhgk jhdsfkjghdfkghskldghwiorthweortkjhkdjfgkjdshfkghkdjfhgklsjdgh kljsdfhgkjlsdfghipoerhgksjdfgkshdf gkjdfshgkl jsdfgio diog erpohpwerohgklsjdfhgkjshdfklgkldsjfghsdifgh sidhg skdfh glkshg");
    mainWindow.textBrowserPT->append("la jlfjalsd kjflasklsdkj lsdlfj lasdkjflksjdlfkjlaskdjflkjasldkfjlaksjflkjaslkdfjlaksjdflkjsldkjflkajsdlfkjlaskjflkjasld fioewjcodjflakdsfjc ladskjfl kadslfkjladsfljldskjflkjaslfjalsdkfjlksjdflajslfjlajsfoepwfijofkdnfk gjfdksjgh kjkjdfhgkjfhg kdfhg; akd;h ;  ahadskgh orit erihv ierh ierh ieru hgierghikj skdkdfjgkdfjgh wpeiorhg ierwohghaakhdhadfkjh kjhagjkhgperi adgfk jhgkja gdkjhg akdhierhiurethkhkljadgh kajhgkalh irht iert herth rkejth kajdfg kjadkgh ahfrithwieruthkj ghlskjdfh a;kdfh;gf oierth eiruh tkjdghdskj gkladjghkrehiwerh ver r       weriutiowuert ioertrt eroitoir tewrutpowieurtoiuweorituowruotiowurtoiwurtoiwer   eri toiurtoie ri or towiert oeur hfkjghskdfjghk kjdfhgk jhdsfkjghdfkghskldghwiorthweortkjhkdjfgkjdshfkghkdjfhgklsjdgh kljsdfhgkjlsdfghipoerhgksjdfgkshdf gkjdfshgkl jsdfgio diog erpohpwerohgklsjdfhgkjshdfklgkldsjfghsdifgh sidhg skdfh glkshg");
    mainWindow.textBrowserPT->append("la jlfjalsd kjflasklsdkj lsdlfj lasdkjflksjdlfkjlaskdjflkjasldkfjlaksjflkjaslkdfjlaksjdflkjsldkjflkajsdlfkjlaskjflkjasld fioewjcodjflakdsfjc ladskjfl kadslfkjladsfljldskjflkjaslfjalsdkfjlksjdflajslfjlajsfoepwfijofkdnfk gjfdksjgh kjkjdfhgkjfhg kdfhg; akd;h ;  ahadskgh orit erihv ierh ierh ieru hgierghikj skdkdfjgkdfjgh wpeiorhg ierwohghaakhdhadfkjh kjhagjkhgperi adgfk jhgkja gdkjhg akdhierhiurethkhkljadgh kajhgkalh irht iert herth rkejth kajdfg kjadkgh ahfrithwieruthkj ghlskjdfh a;kdfh;gf oierth eiruh tkjdghdskj gkladjghkrehiwerh ver r       weriutiowuert ioertrt eroitoir tewrutpowieurtoiuweorituowruotiowurtoiwurtoiwer   eri toiurtoie ri or towiert oeur hfkjghskdfjghk kjdfhgk jhdsfkjghdfkghskldghwiorthweortkjhkdjfgkjdshfkghkdjfhgklsjdgh kljsdfhgkjlsdfghipoerhgksjdfgkshdf gkjdfshgkl jsdfgio diog erpohpwerohgklsjdfhgkjshdfklgkldsjfghsdifgh sidhg skdfh glkshg");

    mainWindow.show();
    return app.exec();
}
