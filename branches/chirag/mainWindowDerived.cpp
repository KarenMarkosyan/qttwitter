#include "mainWindowDerived.h"
#include <QMessageBox>
#include <QIcon>

void mainWindowDerived::closeEvent(QCloseEvent *event)
{
    if (myTrayIcon.isVisible()) {
        QMessageBox::information(this, tr("Systray"),
                                 tr("The program will keep running in the "
                                    "system tray. To terminate the program, "
                                    "choose <b>Quit</b> in the context menu "
                                    "of the system tray entry."));
        hide();
        event->ignore();
    }
}

mainWindowDerived::mainWindowDerived()
{
	 minimizeAction = new QAction(tr("Mi&nimize"), this);
	 maximizeAction = new QAction(tr("Ma&ximize"), this);
         restoreAction = new QAction(tr("&Restore"), this);
         quitAction = new QAction(tr("&Quit"), this);
         myTrayIconMenu = new QMenu(this);
     
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    connect(quitAction, SIGNAL(triggered()), this, SIGNAL(quit()));

	myTrayIcon.setIcon(QIcon(":/twitter/twhitter_btn_03.png"));
	myTrayIcon.show();
	
    myTrayIconMenu->addAction(minimizeAction);
    myTrayIconMenu->addAction(maximizeAction);
    myTrayIconMenu->addAction(restoreAction);
    myTrayIconMenu->addSeparator();
    myTrayIconMenu->addAction(quitAction);
    myTrayIcon.setContextMenu(myTrayIconMenu);
}

void mainWindowDerived::showMessage(QString message)
{
    myTrayIcon.showMessage("SomebOdy Said",message, QSystemTrayIcon::Information,1000/*duration*/);

}
