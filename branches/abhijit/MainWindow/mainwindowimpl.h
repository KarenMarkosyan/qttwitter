#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include "mainWindowDerived.h"
#include "ui_mainWindow.h"
#include "sendTwitDerived.h"
#include "loginDerived.h"
#include "configDerived.h"
#include "flickcharm.h"
//
class MainWindowImpl : public mainWindowDerived, public Ui::MainWindow
{
Q_OBJECT
public:
        MainWindowImpl(QWidget *parent = 0, Qt::WindowFlags flags = 0);
public slots:
	void doPrint();
	void showAboutQt();
	void showAboutQtTwitter();
        void showSendDialog();
        void showLoginDialog();
        void showConfigDialog();
        void addTweetBubble(QWidget *);
signals:
	void showLoginScreen();//signal specifies the window to show login screen and do login work
	void doLogout();//signal is there to make logout work
	void showPublicTimeline();
	void showOwnTimeline();
	void showFollowerTimeline();
        void showFriendsline();
//      void showImageBrowser();//just show the image browser mode
private:
        FlickCharm flickScroll;


};
#endif
