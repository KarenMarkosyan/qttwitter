#ifndef SENDTWIT_DERIVED
#define SENDTWIT_DERIVED
#include "ui_sendTwit.h"

class SendTwitDerived : public QDialog , public Ui::sendTwitDialog
{
  Q_OBJECT

  public:
    SendTwitDerived();
  public slots:
    void recieveTwit(QString value);
  signals:
    void sendTwit(QString value);
    
};


namespace Ui {
  class sendTwitDerived: public SendTwitDerived {};
}

#endif