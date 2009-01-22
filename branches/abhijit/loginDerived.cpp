#include "loginDerived.h"
#include <QDebug>
LoginDialogDerived::LoginDialogDerived()
{
    setupUi(this);

    qDebug() << "Is the loginButton Enabled? " << loginButton->isEnabled();

    // Accept Reject from the OK Cancel buttons
    QObject::connect(this, SIGNAL(accepted()), this, SLOT(emitUserPassword()));
    QObject::connect(this, SIGNAL(rejected()), this, SLOT(clearOnCancel()));

    //Enable the password field only if login ID has been entered in the loginLineEdit field
    QObject::connect(loginLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enablePasswordField(const QString &)));

    //Enable the loginButton only if the password has also been entered
    QObject::connect(passwordLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableLoginButton(const QString &)));

    qDebug()<<"reached here in LoginDialogDerived, all connections established";

}

void LoginDialogDerived::emitUserPassword()
{
    //qDebug()<<"loginDeribved"<<loginLineEdit->text()<<passwordLineEdit->text();
    emit setUserPassword(loginLineEdit->text(),passwordLineEdit->text());
    loginLineEdit->setText("");
    passwordLineEdit->setText("");
    loginLineEdit->setFocus();
}

//Implementing the slot enablePasswordField(const QString &)
void LoginDialogDerived::enablePasswordField(const QString &text)
{
    passwordLineEdit->setEnabled(!text.isEmpty());
    passwordLineEdit->setText("");
    qDebug() << "Is the passwordLineEdit Enabled in the enablePasswordField slot? " << passwordLineEdit->isEnabled() << passwordLineEdit->isReadOnly() << passwordLineEdit->isHidden() << passwordLineEdit->isVisible();
}

//Implementing the slot enableLoginButton(const QString &)
void LoginDialogDerived::enableLoginButton(const QString &text)
{
    //loginButton->button(QDialogloginButton::Ok)->setEnabled(!text.isEmpty());
    loginButton->setEnabled(!text.isEmpty() && passwordLineEdit->isEnabled());
    qDebug() << "Is the loginButton Enabled in the enableLoginButton slot? " << loginButton->isEnabled();
}

//Implementing the slot clearOnCancel() to remove all the texts from the fields on close
void LoginDialogDerived::clearOnCancel()
{
    loginLineEdit->setText("");
    passwordLineEdit->setText("");
    loginLineEdit->setFocus();
}
