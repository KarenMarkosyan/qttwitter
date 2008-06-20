/********************************************************************************
** Form generated from reading ui file 'mainWindow.ui'
**
** Created: Fri Jun 20 05:26:10 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogin;
    QAction *actionLogout;
    QAction *actionPrint;
    QAction *actionPublic;
    QAction *actionFriends;
    QAction *actionOwn;
    QAction *actionAbout_Qt_Twitter;
    QAction *actionAbout_Qt;
    QAction *actionHelp;
    QAction *actionExit;
    QAction *actionFacebook_Status_Twitter;
    QAction *actionConfigure;
    QAction *actionSet_New_Status;
    QAction *actionFollow;
    QAction *actionLeave;
    QAction *actionUser_Methods;
    QAction *actionDirect_Message_Methods;
    QAction *actionFriendship_Methods;
    QAction *actionArchive;
    QAction *actionFavorite_Methods;
    QAction *actionBlock_Methods;
    QAction *actionIs_It_Working;
    QWidget *centralwidget;
    QLabel *twitterImageLabel;
    QLabel *textLabelMainWindow;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QMenu *menuAbout_2;
    QMenu *menuOther_Services;
    QMenu *menuSet_FaceBook_Status;
    QMenu *menuTwitter;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(484, 339);
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/twitter/TwitterPostIcon.png")), QIcon::Normal, QIcon::Off);
    MainWindow->setWindowIcon(icon);
    actionLogin = new QAction(MainWindow);
    actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
    actionLogin->setEnabled(true);
    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/twitter/user-online.svg")), QIcon::Normal, QIcon::Off);
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/twitter/twitter_system_tray1.png")), QIcon::Normal, QIcon::On);
    actionLogin->setIcon(icon1);
    actionLogin->setIconVisibleInMenu(true);
    actionLogout = new QAction(MainWindow);
    actionLogout->setObjectName(QString::fromUtf8("actionLogout"));
    actionLogout->setEnabled(false);
    QIcon icon2;
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/twitter/user-offline.svg")), QIcon::Normal, QIcon::Off);
    actionLogout->setIcon(icon2);
    actionPrint = new QAction(MainWindow);
    actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
    QIcon icon3;
    icon3.addPixmap(QPixmap(QString::fromUtf8(":/twitter/print.jpeg")), QIcon::Normal, QIcon::Off);
    actionPrint->setIcon(icon3);
    actionPublic = new QAction(MainWindow);
    actionPublic->setObjectName(QString::fromUtf8("actionPublic"));
    QIcon icon4;
    icon4.addPixmap(QPixmap(QString::fromUtf8(":/twitter/twitter_system_tray_2.0.png")), QIcon::Normal, QIcon::Off);
    actionPublic->setIcon(icon4);
    actionFriends = new QAction(MainWindow);
    actionFriends->setObjectName(QString::fromUtf8("actionFriends"));
    QIcon icon5;
    icon5.addPixmap(QPixmap(QString::fromUtf8(":/twitter/twitter_system_tray.png")), QIcon::Normal, QIcon::Off);
    actionFriends->setIcon(icon5);
    actionOwn = new QAction(MainWindow);
    actionOwn->setObjectName(QString::fromUtf8("actionOwn"));
    QIcon icon6;
    icon6.addPixmap(QPixmap(QString::fromUtf8(":/twitter/twhitter_btn_02.png")), QIcon::Normal, QIcon::Off);
    actionOwn->setIcon(icon6);
    actionAbout_Qt_Twitter = new QAction(MainWindow);
    actionAbout_Qt_Twitter->setObjectName(QString::fromUtf8("actionAbout_Qt_Twitter"));
    actionAbout_Qt_Twitter->setIcon(icon);
    actionAbout_Qt = new QAction(MainWindow);
    actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
    QIcon icon7;
    icon7.addPixmap(QPixmap(QString::fromUtf8(":/twitter/qt.png")), QIcon::Normal, QIcon::Off);
    actionAbout_Qt->setIcon(icon7);
    actionHelp = new QAction(MainWindow);
    actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
    QIcon icon8;
    icon8.addPixmap(QPixmap(QString::fromUtf8(":/twitter/help-about.svg")), QIcon::Normal, QIcon::Off);
    actionHelp->setIcon(icon8);
    actionExit = new QAction(MainWindow);
    actionExit->setObjectName(QString::fromUtf8("actionExit"));
    QIcon icon9;
    icon9.addPixmap(QPixmap(QString::fromUtf8(":/twitter/application-exit.svg")), QIcon::Normal, QIcon::Off);
    actionExit->setIcon(icon9);
    actionFacebook_Status_Twitter = new QAction(MainWindow);
    actionFacebook_Status_Twitter->setObjectName(QString::fromUtf8("actionFacebook_Status_Twitter"));
    actionFacebook_Status_Twitter->setCheckable(true);
    QIcon icon10;
    icon10.addPixmap(QPixmap(QString::fromUtf8(":/twitter/icon.facebook.png")), QIcon::Normal, QIcon::Off);
    actionFacebook_Status_Twitter->setIcon(icon10);
    actionConfigure = new QAction(MainWindow);
    actionConfigure->setObjectName(QString::fromUtf8("actionConfigure"));
    QIcon icon11;
    icon11.addPixmap(QPixmap(QString::fromUtf8(":/twitter/configure.svg")), QIcon::Normal, QIcon::Off);
    actionConfigure->setIcon(icon11);
    actionSet_New_Status = new QAction(MainWindow);
    actionSet_New_Status->setObjectName(QString::fromUtf8("actionSet_New_Status"));
    QIcon icon12;
    icon12.addPixmap(QPixmap(QString::fromUtf8(":/twitter/im-status-message-edit.svg")), QIcon::Normal, QIcon::Off);
    actionSet_New_Status->setIcon(icon12);
    actionFollow = new QAction(MainWindow);
    actionFollow->setObjectName(QString::fromUtf8("actionFollow"));
    QIcon icon13;
    icon13.addPixmap(QPixmap(QString::fromUtf8(":/twitter/add-profile.svg")), QIcon::Normal, QIcon::Off);
    actionFollow->setIcon(icon13);
    actionLeave = new QAction(MainWindow);
    actionLeave->setObjectName(QString::fromUtf8("actionLeave"));
    QIcon icon14;
    icon14.addPixmap(QPixmap(QString::fromUtf8(":/twitter/remove-profile.svg")), QIcon::Normal, QIcon::Off);
    actionLeave->setIcon(icon14);
    actionUser_Methods = new QAction(MainWindow);
    actionUser_Methods->setObjectName(QString::fromUtf8("actionUser_Methods"));
    QIcon icon15;
    icon15.addPixmap(QPixmap(QString::fromUtf8(":/twitter/personal.svg")), QIcon::Normal, QIcon::Off);
    actionUser_Methods->setIcon(icon15);
    actionDirect_Message_Methods = new QAction(MainWindow);
    actionDirect_Message_Methods->setObjectName(QString::fromUtf8("actionDirect_Message_Methods"));
    QIcon icon16;
    icon16.addPixmap(QPixmap(QString::fromUtf8(":/twitter/message-unread.svg")), QIcon::Normal, QIcon::Off);
    actionDirect_Message_Methods->setIcon(icon16);
    actionFriendship_Methods = new QAction(MainWindow);
    actionFriendship_Methods->setObjectName(QString::fromUtf8("actionFriendship_Methods"));
    actionArchive = new QAction(MainWindow);
    actionArchive->setObjectName(QString::fromUtf8("actionArchive"));
    actionFavorite_Methods = new QAction(MainWindow);
    actionFavorite_Methods->setObjectName(QString::fromUtf8("actionFavorite_Methods"));
    actionBlock_Methods = new QAction(MainWindow);
    actionBlock_Methods->setObjectName(QString::fromUtf8("actionBlock_Methods"));
    actionIs_It_Working = new QAction(MainWindow);
    actionIs_It_Working->setObjectName(QString::fromUtf8("actionIs_It_Working"));
    QIcon icon17;
    icon17.addPixmap(QPixmap(QString::fromUtf8(":/twitter/questionmark")), QIcon::Normal, QIcon::Off);
    actionIs_It_Working->setIcon(icon17);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setGeometry(QRect(0, 67, 484, 251));
    twitterImageLabel = new QLabel(centralwidget);
    twitterImageLabel->setObjectName(QString::fromUtf8("twitterImageLabel"));
    twitterImageLabel->setGeometry(QRect(130, 80, 221, 61));
    twitterImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/twitter/Twitter.png")));
    textLabelMainWindow = new QLabel(centralwidget);
    textLabelMainWindow->setObjectName(QString::fromUtf8("textLabelMainWindow"));
    textLabelMainWindow->setGeometry(QRect(10, 30, 461, 121));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 484, 28));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuAbout = new QMenu(menubar);
    menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
    menuAbout_2 = new QMenu(menubar);
    menuAbout_2->setObjectName(QString::fromUtf8("menuAbout_2"));
    menuOther_Services = new QMenu(menubar);
    menuOther_Services->setObjectName(QString::fromUtf8("menuOther_Services"));
    menuSet_FaceBook_Status = new QMenu(menuOther_Services);
    menuSet_FaceBook_Status->setObjectName(QString::fromUtf8("menuSet_FaceBook_Status"));
    menuTwitter = new QMenu(menubar);
    menuTwitter->setObjectName(QString::fromUtf8("menuTwitter"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setGeometry(QRect(0, 318, 484, 21));
    MainWindow->setStatusBar(statusbar);
    toolBar = new QToolBar(MainWindow);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    toolBar->setGeometry(QRect(0, 28, 484, 39));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuAbout->menuAction());
    menubar->addAction(menuTwitter->menuAction());
    menubar->addAction(menuOther_Services->menuAction());
    menubar->addAction(menuAbout_2->menuAction());
    menuFile->addAction(actionLogin);
    menuFile->addAction(actionLogout);
    menuFile->addAction(actionPrint);
    menuFile->addSeparator();
    menuFile->addAction(actionConfigure);
    menuFile->addAction(actionExit);
    menuAbout->addAction(actionPublic);
    menuAbout->addAction(actionFriends);
    menuAbout->addAction(actionOwn);
    menuAbout_2->addSeparator();
    menuAbout_2->addAction(actionIs_It_Working);
    menuAbout_2->addAction(actionAbout_Qt_Twitter);
    menuAbout_2->addAction(actionAbout_Qt);
    menuAbout_2->addAction(actionHelp);
    menuOther_Services->addAction(menuSet_FaceBook_Status->menuAction());
    menuSet_FaceBook_Status->addAction(actionFacebook_Status_Twitter);
    menuTwitter->addAction(actionSet_New_Status);
    menuTwitter->addAction(actionFollow);
    menuTwitter->addAction(actionLeave);
    menuTwitter->addAction(actionUser_Methods);
    menuTwitter->addAction(actionDirect_Message_Methods);
    menuTwitter->addAction(actionFriendship_Methods);
    menuTwitter->addAction(actionArchive);
    menuTwitter->addAction(actionFavorite_Methods);
    menuTwitter->addAction(actionBlock_Methods);
    toolBar->addAction(actionLogin);
    toolBar->addAction(actionSet_New_Status);
    toolBar->addAction(actionFollow);
    toolBar->addAction(actionConfigure);
    toolBar->addAction(actionExit);

    retranslateUi(MainWindow);
    QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionLogin->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    actionLogin->setToolTip(QApplication::translate("MainWindow", "Login To Twitter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    actionLogin->setStatusTip(QApplication::translate("MainWindow", "Simple Login to twitter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    actionLogout->setText(QApplication::translate("MainWindow", "Logout", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    actionLogout->setToolTip(QApplication::translate("MainWindow", "Logout From Twitter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    actionPrint->setText(QApplication::translate("MainWindow", "Print", 0, QApplication::UnicodeUTF8));
    actionPublic->setText(QApplication::translate("MainWindow", "Public", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    actionPublic->setStatusTip(QApplication::translate("MainWindow", "Display TimeLine's From Twitter Server", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    actionFriends->setText(QApplication::translate("MainWindow", "Friends", 0, QApplication::UnicodeUTF8));
    actionOwn->setText(QApplication::translate("MainWindow", "Own", 0, QApplication::UnicodeUTF8));
    actionAbout_Qt_Twitter->setText(QApplication::translate("MainWindow", "About Qt Twitter", 0, QApplication::UnicodeUTF8));
    actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
    actionHelp->setText(QApplication::translate("MainWindow", "New From Twitter", 0, QApplication::UnicodeUTF8));
    actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
    actionFacebook_Status_Twitter->setText(QApplication::translate("MainWindow", "Facebook Status = Twitter", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    actionFacebook_Status_Twitter->setToolTip(QApplication::translate("MainWindow", "Set Facebook Status equal to Twitter's microblog from next update", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    actionFacebook_Status_Twitter->setStatusTip(QApplication::translate("MainWindow", "Set Facebook Status equal to Twitter's microblog from next update", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    actionFacebook_Status_Twitter->setWhatsThis(QApplication::translate("MainWindow", "Set Facebook Status equal to Twitter's microblog from next update", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    actionConfigure->setText(QApplication::translate("MainWindow", "Configure", 0, QApplication::UnicodeUTF8));
    actionSet_New_Status->setText(QApplication::translate("MainWindow", "Set New Status", 0, QApplication::UnicodeUTF8));
    actionFollow->setText(QApplication::translate("MainWindow", "Follow", 0, QApplication::UnicodeUTF8));
    actionLeave->setText(QApplication::translate("MainWindow", "Leave", 0, QApplication::UnicodeUTF8));
    actionUser_Methods->setText(QApplication::translate("MainWindow", "User Methods", 0, QApplication::UnicodeUTF8));
    actionDirect_Message_Methods->setText(QApplication::translate("MainWindow", "Direct Message Methods", 0, QApplication::UnicodeUTF8));
    actionFriendship_Methods->setText(QApplication::translate("MainWindow", "Friendship Methods", 0, QApplication::UnicodeUTF8));
    actionArchive->setText(QApplication::translate("MainWindow", "archive", 0, QApplication::UnicodeUTF8));
    actionFavorite_Methods->setText(QApplication::translate("MainWindow", "Favorite Methods", 0, QApplication::UnicodeUTF8));
    actionBlock_Methods->setText(QApplication::translate("MainWindow", "Block Methods", 0, QApplication::UnicodeUTF8));
    actionIs_It_Working->setText(QApplication::translate("MainWindow", "Is It Working?", 0, QApplication::UnicodeUTF8));
    twitterImageLabel->setText(QString());
    textLabelMainWindow->setText(QString());
    menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    menuAbout->setTitle(QApplication::translate("MainWindow", "Timeline", 0, QApplication::UnicodeUTF8));
    menuAbout_2->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    menuOther_Services->setTitle(QApplication::translate("MainWindow", "Other Services", 0, QApplication::UnicodeUTF8));
    menuSet_FaceBook_Status->setTitle(QApplication::translate("MainWindow", "Set FaceBook Status", 0, QApplication::UnicodeUTF8));
    menuTwitter->setTitle(QApplication::translate("MainWindow", "Twitter", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
