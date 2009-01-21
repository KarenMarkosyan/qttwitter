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
#include "styleSheet.h"
// #include "imagebrowserimpl.h"
#include <QDialog>


int main(int argc,char **argv)
{
        //declarations
        QApplication app(argc,argv);
        //this is derived from ui file and the added functionality  system tray MainWindow Class
        MainWindowImpl mainWindow;
        Ui::loginDialogDerived myLoginDialog;
        Ui::sendTwitDerived mySendTwitDialog;
        Backend::twitterBackend myTwitter;
	
        //connection slots
        QObject::connect(&mainWindow,SIGNAL(quit()),&app,SLOT(quit()));//just quit when you get quit signal
        QObject::connect(mainWindow.actionLogin,SIGNAL(triggered()),&myLoginDialog,SLOT(show()));
        QObject::connect(mainWindow.actionSet_New_Status,SIGNAL(triggered()),&mySendTwitDialog,SLOT(show()));
        QObject::connect(mainWindow.actionPublic,SIGNAL(triggered()),&myTwitter,SLOT(public_timeline()));
        QObject::connect(mainWindow.actionFriends,SIGNAL(triggered()),&myTwitter,SLOT(friends_timeline()));
        QObject::connect(mainWindow.actionOwn,SIGNAL(triggered()),&myTwitter,SLOT(user_timeline()));


        QObject::connect(&myLoginDialog,SIGNAL(setUserPassword(QString,QString)) ,&myTwitter ,SLOT(setUserNamePassword(QString,QString)) );/**login connection */
        QObject::connect(&myTwitter,SIGNAL(public_timeline(QString)),mainWindow.textLabelMainWindow,SLOT(setText(QString))
        );//connection for shwoing public timeline
        QObject::connect(&mySendTwitDialog,SIGNAL(sendTwit(QString)),&myTwitter,SLOT(update(QString)));
        //QObject::connect(mainWindow.action,SIGNAL(triggered()),&myTwitter,SLOT());
        //property setting
	app.setStyleSheet(globalStyle);
//         mySendTwitDialog.setupUi(&containerSendTwitDialog);
        mainWindow.show();
        return app.exec();
}
