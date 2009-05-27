#ifndef SENDTWIT_DERIVED
#define SENDTWIT_DERIVED
#include "ui_sendTwit.h"
#include <QDebug>
#include "twitterbackendinterface.h"

extern twitterBackendInterface *myTwitter;

class SendTwitDerived : public QDialog , public Ui::sendTwitDialog
{
  Q_OBJECT

  public:
    SendTwitDerived();

    //Creating a static function to create the send tweet dialog only when needed
    //And then destroy it after usage
    static void showDialog();

  public slots:
    void recieveTwit();
    void enableSendButton( const QString & );
    void updateCharsLeft( const QString & );
  signals:
    void sendTwit(QString value);

};


namespace Ui {
  class sendTwitDerived: public SendTwitDerived {};
}

#endif
