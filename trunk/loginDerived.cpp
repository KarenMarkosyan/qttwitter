#include "loginDerived.h"
#include <QDebug>
LoginDialogDerived ::LoginDialogDerived() 
{
  setupUi(this);
    QObject::connect(this,SIGNAL(accepted()),this,SLOT(emitUserPassword()));
//   QObject::connect(this,SIGNAL(rejected()),this,SLOT(emitUserPassword()));

  qDebug()<<"reached here";

}
void LoginDialogDerived ::emitUserPassword()
{
//   qDebug()<<loginLineEdit->text()<<passwordLineEdit->text();
//   emit setUserPassword(loginLineEdit->text(),passwordLineEdit->text());
}

