#include "mainwindowimpl.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QDebug>
#include <QMessageBox>
#include "sendTwitDerived.h"
#include "loginDerived.h"

MainWindowImpl::MainWindowImpl( )
{
    setupUi(this);
    //defining the menu actions of main windwos here.

    //Here Comes File Menu
    //connect(actionLogout, SIGNAL(triggered()), this, SIGNAL(doLogout()));
    connect(actionPrint, SIGNAL(triggered()), this, SLOT(doPrint()));
    connect(actionAbout_Qt, SIGNAL(triggered()), this, SLOT(showAboutQt()));
    connect(actionAbout_Qt_Twitter, SIGNAL(triggered()), this, SLOT(showAboutQtTwitter()));
    // connect(actionView_Images_From_Area,SIGNAL(triggered() ),this ,SIGNAL(showImageBrowser()));

    //Here Comes Timeline Menu

}
void MainWindowImpl::doPrint()
{
    QPrinter myPrinter;
    QPrintDialog *dialog = new QPrintDialog(&myPrinter, this);
    dialog->setWindowTitle(tr("Print Document"));
    // dialog-->show();

}
void MainWindowImpl::showAboutQt()
{
    QMessageBox temp;
    temp.aboutQt(this,"About Qt Framework/Toolkit");
}
void MainWindowImpl::showAboutQtTwitter()
{
    QMessageBox::about(this,"About Qwitter Book Program",
                       tr("<h2>Qwitter Book 1.0</h2>"
                       "<h5>Copyright &copy; 2008-09, <a href=http://techfreaks4u.com>Techfreaks4u Inc.</a></h5>"
                       "<p>This program is based on the Open Source GPL version of Qt 4, and the Twitter APIs "
                       "implemented in the open QTwitLib class. Also in the future, Facebook capabilities will be embedded, "
                       "where you can have your face in our Good Books :-)."
                       "<p>This program is being jointly developed by:"
                       "\n\t<h4>Abhijeet Anand (<a href=mailto:abhijeet.juit@gmail.com>abhijeet.juit@gmail.com</a>)</h4>"
                       "\n\t<h4>Shashank Singh (<a href=mailto:shashank.personal@gmail.com>shashank.personal@gmail.com</a>)</h4>"
                       ));
}

void MainWindowImpl::showSendDialog()
{
    SendTwitDerived::showDialog();
}

void MainWindowImpl::showLoginDialog()
{
    LoginDialogDerived::showDialog();
}
