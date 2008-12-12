#include "loginDerived.h"

LoginDialogDerived ::LoginDialogDerived()
{
//    QObject::connect(buttonBox,SIGNAL(accepted()),this,SLOT(emitUserPassword()));
}
void LoginDialogDerived ::emitUserPassword()
{
  emit setUserPasswrd(loginLineEdit->text(),passwordLineEdit->text());
}