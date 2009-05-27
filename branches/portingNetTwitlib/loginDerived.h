#ifndef LOGINDERIVED_H
#define LOGINDERIVED_H
#include "ui_login.h"
#include "twitterbackendinterface.h"
#include <QSettings>

extern twitterBackendInterface *myTwitter;

class LoginDialogDerived : public QDialog, public Ui::loginDialog
{
    Q_OBJECT

public:
    LoginDialogDerived();

    static void showDialog();

private:
    void storeLoginCredentials();
    void readLoginCredentials();

public slots:
    void emitUserPassword();
    void enablePasswordField(const QString &text);
    void enableLoginButton(const QString &text);
    void clearOnCancel();

signals:
    void setUserPassword(QString user, QString password);
};


namespace Ui {
    class loginDialogDerived: public LoginDialogDerived {};
}

#endif // LOGINDERIVED_H
