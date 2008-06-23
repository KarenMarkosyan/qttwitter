//
// C++ Interface:
//
// Description:
//
//
// Author: Shashank Singh <shashank.personal@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef IMAGEBROWSERIMPL_H
#define IMAGEBROWSERIMPL_H

#include <QWidget>
#include "Ui/imageBrowser.h"
namespace Ui
{
class imageBrowserimpl : public QWidget, public Ui::imageBrowser
{
        Q_OBJECT

public:
        imageBrowserimpl(QWidget* parent = 0, Qt::WFlags fl = 0 );
        ~imageBrowserimpl();
        /*$PUBLIC_FUNCTIONS$*/

public slots:
        /*$PUBLIC_SLOTS$*/

protected:
        /*$PROTECTED_FUNCTIONS$*/

protected slots:
        /*$PROTECTED_SLOTS$*/

};

};
#endif

