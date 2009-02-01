/* this program is developed on QDevelop -- a good Qt IDE by Jean - Luc Biord and others :) & Kdevelop
   And also on Qt Creator -- A very clean and optimised Qt IDE from Nokia-Trolltech
qt used = Qt Open Source Edition version 4.4.3.
on open suse 11.1 and Windows XP Professional SP2
[02:53:53 PM Tuesday, December 09 2008] update i am using qt 4.4.3 and qt creator/kate/vim and ubuntu
*/
#include <QApplication>
#include <QDialog>
#include "MainWindow/mainwindowimpl.h"
//#include "loginDerived.h"
//#include "sendTwitDerived.h"
//#include "imagebrowserimpl.h"
#include "twitterbackendinterface.h"
#include "styleSheet.h"

extern twitterBackendInterface *myTwitter = new twitterBackendInterface();


int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    //this is derived from ui file and the added functionality  system tray MainWindow Class
    MainWindowImpl mainWindow;

    // These containers are not required and are ambiguous
    QDialog containerImageBrowser;
    //Ui::imageBrowserimpl myImageBroswer; //not needed right now

    //Creating Login and Send Tweet dialogs
    //Ui::loginDialogDerived myLoginDialog;
    //Ui::sendTwitDerived mySendTwitDialog;

    //==================================================================
    //connection slots
    //==================================================================

    //just quit when you get quit signal from the system tray menu
    QObject::connect(&mainWindow,SIGNAL(quit()),&app,SLOT(quit()));
    //Quit completely from the app. Shortcut is Ctrl-Q
    QObject::connect(mainWindow.actionQuit, SIGNAL(triggered()), &app, SLOT(quit()));

    //For displaying the Login Dialog Box.
    //QObject::connect(mainWindow.actionLogin,SIGNAL(triggered()),&myLoginDialog,SLOT(show()));
    QObject::connect(mainWindow.actionLogin, SIGNAL(triggered()), &mainWindow, SLOT(showLoginDialog()));
    //login connection, transferring temporarily to the loginDerived.cpp and checking if login can be localised like sendTweet
    //QObject::connect(&myLoginDialog, SIGNAL(setUserPassword(QString,QString)), myTwitter, SLOT(setUserNamePassword(QString,QString)));

    //For displaying the Send Tweet Dialog Box
    //QObject::connect(mainWindow.actionSet_New_Status,SIGNAL(triggered()),&mySendTwitDialog,SLOT(show()));
    QObject::connect(mainWindow.actionSet_New_Status, SIGNAL(triggered()), &mainWindow, SLOT(showSendDialog()));

    //For displaying the configuration box
    QObject::connect(mainWindow.actionConfigure, SIGNAL(triggered()), &mainWindow, SLOT(showConfigDialog()));

    //Connecting the Timeline Menu Actions to respective timelime fetching methods
    QObject::connect(mainWindow.actionPublic, SIGNAL(triggered()), myTwitter, SLOT(public_timeline()));
    QObject::connect(mainWindow.actionFriends, SIGNAL(triggered()), myTwitter, SLOT(friends_timeline()));
    QObject::connect(mainWindow.actionOwn, SIGNAL(triggered()), myTwitter, SLOT(user_timeline()));


    //connecting the signal actionPublic to start the timer to auto-fetch the tweets after a fixed time interval
    QObject::connect(mainWindow.actionPublic, SIGNAL(triggered()), myTwitter->timerPublicTweet, SLOT(start()));
    //the slot to be later replaced by myTwitter->timerFriendsTweet->start();
    //QObject::connect(mainWindow.actionFriends, SIGNAL(triggered()), myTwitter, SLOT(friends_timeline()));
    // the slot to be later replaced by myTwitter->timerUserTweet->start();
    //QObject::connect(mainWindow.actionOwn, SIGNAL(triggered()), myTwitter, SLOT(user_timeline()));

    //Displaying the Public Timeline messages to the respective tab
    QObject::connect(myTwitter, SIGNAL(public_timeline(QString)), mainWindow.textBrowserPT, SLOT(append(QString)) );
    //QObject::connect(&mySendTwitDialog, SIGNAL(sendTwit(QString)), myTwitter, SLOT(update(QString))); //From Shanky's Branch.. Yet to see its function.

    //Image Display Widget connections
    QObject::connect(mainWindow.actionView_Images_From_Area,SIGNAL(triggered()),&containerImageBrowser,SLOT(show()));

    //Now adding few junk code for debugging purposes only. This whole block can be removed later
/*    {
        mainWindow.textBrowserPT->setFontFamily("Lucida Console");
        mainWindow.textBrowserPT->append("                                           \n"
                                         "     QQQQQQQQQ               tttt          \n"
                                         "   QQ:::::::::QQ          ttt:::t          \n"
                                         " QQ:::::::::::::QQ        t:::::t          \n"
                                         "Q:::::::QQQ:::::::Q       t:::::t          \n"
                                         "Q::::::O   Q::::::Q ttttttt:::::ttttttt    \n"
                                         "Q:::::O     Q:::::Q t:::::::::::::::::t    \n"
                                         "Q:::::O     Q:::::Q t:::::::::::::::::t    \n"
                                         "Q:::::O     Q:::::Q tttttt:::::::tttttt    \n"
                                         "Q:::::O     Q:::::Q       t:::::t          \n"
                                         "Q:::::O     Q:::::Q       t:::::t          \n"
                                         "Q:::::O  QQQQ:::::Q       t:::::t          \n"
                                         "Q::::::O Q::::::::Q       t:::::t    tttttt\n"
                                         "Q:::::::QQ::::::::Q       t::::::tttt:::::t\n"
                                         " QQ::::::::::::::Q        tt::::::::::::::t\n"
                                         "   QQ:::::::::::Q           tt:::::::::::tt\n"
                                         "     QQQQQQQQ::::QQ           ttttttttttt  \n"
                                         "             Q:::::Q                       \n"
                                         "              QQQQQQ                       \n"
                                         "                                           \n");
        mainWindow.textBrowserPT->append("\n"
                                         "     #####                                           #         ###   \n"
                                         "    #     # #    # # ##### ##### ###### #####       ##        #   #  \n"
                                         "    #     # #    # #   #     #   #      #    #     # #       #     # \n"
                                         "    #     # #    # #   #     #   #####  #    #       #       #     # \n"
                                         "    #   # # # ## # #   #     #   #      #####        #   ### #     # \n"
                                         "    #    #  ##  ## #   #     #   #      #   #        #   ###  #   #  \n"
                                         "     #### # #    # #   #     #   ###### #    #     ##### ###   ###   \n"
                                         "                                                                     \n"
                                         "\n\n\n    Banner Art by ..::==Abhijeet Anand==::..\n");

        mainWindow.textBrowserFT->setFontFamily("Lucida Console");
        mainWindow.textBrowserFT->append("\n\n\n\n\n\n"
                                         "     #####                                           #         ###   \n"
                                         "    #     # #    # # ##### ##### ###### #####       ##        #   #  \n"
                                         "    #     # #    # #   #     #   #      #    #     # #       #     # \n"
                                         "    #     # #    # #   #     #   #####  #    #       #       #     # \n"
                                         "    #   # # # ## # #   #     #   #      #####        #   ### #     # \n"
                                         "    #    #  ##  ## #   #     #   #      #   #        #   ###  #   #  \n"
                                         "     #### # #    # #   #     #   ###### #    #     ##### ###   ###   \n"
                                         "                                                                     \n"
                                         "    Banner Art by ..::==Abhijeet Anand==::..\n");

        mainWindow.textBrowserMTT->setFontFamily("Terminal");
        mainWindow.textBrowserMTT->append("\n\n\n\n\n\n"
                                         "     #####                                           #         ###   \n"
                                         "    #     # #    # # ##### ##### ###### #####       ##        #   #  \n"
                                         "    #     # #    # #   #     #   #      #    #     # #       #     # \n"
                                         "    #     # #    # #   #     #   #####  #    #       #       #     # \n"
                                         "    #   # # # ## # #   #     #   #      #####        #   ### #     # \n"
                                         "    #    #  ##  ## #   #     #   #      #   #        #   ###  #   #  \n"
                                         "     #### # #    # #   #     #   ###### #    #     ##### ###   ###   \n"
                                         "                                                                     \n"
                                         "    Banner Art by ..::==Abhijeet Anand==::..\n");
    }//This removable block ends here
*/
    app.setStyleSheet(globalStyle);
    mainWindow.resize(800, 600);
    mainWindow.show();
    return app.exec();
}
