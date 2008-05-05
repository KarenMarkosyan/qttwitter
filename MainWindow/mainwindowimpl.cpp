#include "mainwindowimpl.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QDebug>
#include <QMessageBox>
//
MainWindowImpl::MainWindowImpl( ) 
{
	setupUi(this);
	//defining the menu actions of main windwos here.
	
	//Here Comes File Menu
	//connect(actionLogout, SIGNAL(triggered()), this, SIGNAL(doLogout()));
	connect(actionPrint, SIGNAL(triggered()), this, SLOT(doPrint()));
	connect(actionAbout_Qt, SIGNAL(triggered()), this, SLOT(showAboutQt()));
	connect(actionAbout_Qt_Twitter, SIGNAL(triggered()), this, SLOT(showAboutQtTwitter()));
	//(actionExit, SIGNAL(triggered())already handled in Ui File

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
	QMessageBox temp;
	temp.about(this,"About QtTwitter Program","HI this should be where i say about my progam");
}
//

