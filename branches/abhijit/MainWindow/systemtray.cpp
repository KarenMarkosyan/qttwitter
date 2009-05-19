#include "systemtray.h"

SystemTray::SystemTray(QWidget *parent, Qt::WindowFlags flags)
        : QMainWindow(parent, flags)
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

    myTrayIconMenu->addAction(minimizeAction);
    myTrayIconMenu->addAction(maximizeAction);
    myTrayIconMenu->addAction(restoreAction);
    myTrayIconMenu->addSeparator();
    myTrayIconMenu->addAction(quitAction);

    myTrayIcon.setContextMenu(myTrayIconMenu);
    myTrayIcon.setIcon(QIcon(":/twitter/trayIcon"));

    //conecting system tray icon activated signal to handle double-clicks and single-left-click
    connect(&myTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconClicked(QSystemTrayIcon::ActivationReason)));

    //Showing the system tray icon
    myTrayIcon.show();
}

void SystemTray::closeEvent(QCloseEvent *event)
{
    if (myTrayIcon.isVisible())
    {
        /*
        This stub will make sure that the message box onCloseEvent only appears once
        QSettings globalSettings
        */
        QMessageBox::warning(this, tr("Going in stealth mode..."),
                                 tr("The program will keep running in the "
                                    "system tray. To terminate the program, "
                                    "choose <b>Quit</b> in the context menu "
                                    "of the system tray entry."));
        hide();
        event->ignore();
    }
}

void SystemTray::showMessage(QString message)
{
    myTrayIcon.showMessage("Somebody Said",message, QSystemTrayIcon::Information,5000/*duration*/);
}

void SystemTray::trayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::DoubleClick)
    {
        this->showNormal();
        this->activateWindow();
    }
}
