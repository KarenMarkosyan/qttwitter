#ifndef LOGINDERIVED_H
#define LOGINDERIVED_H
#include "ui_login.h"

class LoginDialogDerived : public QDialog, public Ui::loginDialog
{
    Q_OBJECT
// 
public:
    LoginDialogDerived();
//     
public slots:
    void emitUserPassword();
    void enablePasswordField(const QString &text);
    void enableLoginButton(const QString &text);
// 
signals:
    void setUserPassword(QString user, QString password);
};


namespace Ui {
    class loginDialogDerived: public LoginDialogDerived {};
}

#endif // LOGINDERIVED_H
