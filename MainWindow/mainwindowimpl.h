#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include "mainWindowDerived.h"
#include "ui_mainWindow.h"
#include "sendTwitDerived.h"
#include "loginDerived.h"
#include "configDerived.h"
//
class MainWindowImpl : public mainWindowDerived, public Ui::MainWindow
{
Q_OBJECT
public:
	MainWindowImpl( );
public slots:
	void doPrint();
	void showAboutQt();
	void showAboutQtTwitter();
        void showSendDialog();
        void showLoginDialog();
        void showConfigDialog();
signals:
	void showLoginScreen();//signal specifies the window to show login screen and do login work
	void doLogout();//signal is there to make logout work
	void showPublicTimeline();
	void showOwnTimeline();
	void showFollowerTimeline();
    void showFriendsline();
//     void showImageBrowser();//just show the image browser mode


};
#endif
