#include "mainWindowDerived.h"
#include <QMessageBox>
#include <QIcon>

void mainWindowDerived::closeEvent(QCloseEvent *event)
{
    if (myTrayIcon.isVisible())
    {
        /*
        This stub will make sure that the message box onCloseEvent only appears once
        QSettings globalSettings
        */
        QMessageBox::warning(this, tr("Systray"),
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

    //conecting system tray icon activated signal to handle double-clicks and single-left-click
    connect(&myTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconClicked(QSystemTrayIcon::ActivationReason)));

    myTrayIconMenu->addAction(minimizeAction);
    myTrayIconMenu->addAction(maximizeAction);
    myTrayIconMenu->addAction(restoreAction);
    myTrayIconMenu->addSeparator();
    myTrayIconMenu->addAction(quitAction);

    myTrayIcon.setContextMenu(myTrayIconMenu);
    myTrayIcon.setIcon(QIcon(":/twitter/trayIcon"));

    //Showing the system tray icon
    myTrayIcon.show();
}

void mainWindowDerived::showMessage(QString message)
{
    myTrayIcon.showMessage("Somebody Said",message, QSystemTrayIcon::Information,5000/*duration*/);

}

void mainWindowDerived::trayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::DoubleClick)
    {
        this->showNormal();
        this->activateWindow();
    }
}
