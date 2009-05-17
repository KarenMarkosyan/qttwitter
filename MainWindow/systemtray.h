#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QMenu>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QIcon>

class SystemTray : public QMainWindow
{
    Q_OBJECT
public:
    SystemTray(QWidget *parent = 0, Qt::WindowFlags flags = 0);

protected:
    void closeEvent(QCloseEvent *event);

private:
    QSystemTrayIcon myTrayIcon;
    QMenu *myTrayIconMenu;
    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;

public slots:
    void showMessage(QString);//show a message in notification
    void trayIconClicked(QSystemTrayIcon::ActivationReason); //For showing the main window on double-clicking the tray icon

signals:
    void quit();
};

#endif // SYSTEMTRAY_H
