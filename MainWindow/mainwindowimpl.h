#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include "mainWindowDerived.h"
#include "ui_mainWindow.h"
//
class MainWindowImpl : public mainWindowDerived, public Ui::MainWindow 
{
Q_OBJECT
public:
	MainWindowImpl( QWidget *parent ,Qt::WindowFlags flags);
public slots:
	void doPrint();
	void showAboutQt();
	void showAboutQtTwitter();
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





