#include "loginDerived.h"
#include <QDebug>

LoginDialogDerived::LoginDialogDerived()
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    setupUi(this);

    // Accept Reject from the OK Cancel buttons
    QObject::connect(this, SIGNAL(accepted()), this, SLOT(emitUserPassword()));
    QObject::connect(this, SIGNAL(rejected()), this, SLOT(clearOnCancel()));

    //Logging in to the twitter
    QObject::connect(this, SIGNAL(setUserPassword(QString,QString)), myTwitter, SLOT(setUserNamePassword(QString,QString)));

    //Enable the password field only if login ID has been entered in the loginLineEdit field
    QObject::connect(loginLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enablePasswordField(const QString &)));

    //Enable the loginButton only if the password has also been entered
    QObject::connect(passwordLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableLoginButton(const QString &)));

    qDebug()<<"reached here in LoginDialogDerived, all connections established";

}

void LoginDialogDerived::emitUserPassword()
{
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
}

//Implementing the slot enableLoginButton(const QString &)
void LoginDialogDerived::enableLoginButton(const QString &text)
{
    loginButton->setEnabled(!text.isEmpty() && passwordLineEdit->isEnabled());
}

//Implementing the slot clearOnCancel() to remove all the texts from the fields on close
void LoginDialogDerived::clearOnCancel()
{
    loginLineEdit->setText("");
    passwordLineEdit->setText("");
    loginLineEdit->setFocus();
}

void LoginDialogDerived::showDialog()
{
    LoginDialogDerived *loginDialog = new LoginDialogDerived();
    loginDialog->show();
}
