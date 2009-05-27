//
// C++ Interface: lineedit
//
// Description: 
//
//
// Author: root <root@linux-1gxp>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

class QToolButton;

class LineEdit : public QLineEdit
{
    Q_OBJECT

public:
    LineEdit(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);

private slots:
    void updateCloseButton(const QString &text);

private:
    QToolButton *clearButton;
};

#endif // LIENEDIT_H
