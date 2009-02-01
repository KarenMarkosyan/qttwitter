//
// C++ Interface:
//
// Description:
//
//
// Author: Shashank Singh <shashank.personal@gmail.com>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef DERIVEDCONFIGDIALOG_H
#define DERIVEDCONFIGDIALOG_H

#include "ui_config.h"
#include <QDialog>
#include <QNetworkProxy>
#include <QDebug>
namespace Ui
{
class derivedConfigDialog : public QDialog , public Ui::configDialog
{
        Q_OBJECT

public:
        derivedConfigDialog();
        ~derivedConfigDialog();
        /*$PUBLIC_FUNCTIONS$*/

public slots:
        /*$PUBLIC_SLOTS$*/

protected:
        /*$PROTECTED_FUNCTIONS$*/

protected slots:
        /*$PROTECTED_SLOTS$*/
        virtual void          reject();
        virtual void          accept();

};
}
#endif

