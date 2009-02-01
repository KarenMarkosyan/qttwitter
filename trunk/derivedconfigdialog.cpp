//
// C++ Implementation:
//
// Description:
//
//
// Author: Shashank Singh <shashank.personal@gmail.com>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include "derivedconfigdialog.h"
using namespace Ui;
derivedConfigDialog::derivedConfigDialog()
                : Ui::configDialog()
{
 setupUi(this);
qDebug()<<"i am in derived config dialog";               
}

derivedConfigDialog::~derivedConfigDialog()
{
}

/*$SPECIALIZATION$*/
void derivedConfigDialog::reject()
{
        QDialog::reject();
}

void derivedConfigDialog::accept()
{
qDebug()<<"i reached in derive config dialog"<<proxyUrl->text();
bool conversionStatus;
int port = (proxyPort->text()).toInt(&conversionStatus);
 QNetworkProxy proxy;
if ((userName->text()).isEmpty() == FALSE)
{
 proxy.setType(QNetworkProxy::Socks5Proxy);

 proxy.setHostName(proxyUrl->text());

 proxy.setPort(port);

if((userName->text()).isEmpty() == FALSE && (password->text()).isEmpty() == FALSE )
{
 proxy.setUser(userName->text());
 proxy.setPassword(password->text());
}
 QNetworkProxy::setApplicationProxy(proxy);
}

        QDialog::accept();
}



