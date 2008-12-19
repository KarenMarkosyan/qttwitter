#ifndef SENDTWIT_DERIVED
#define SENDTWIT_DERIVED
#include "ui_sendTwit.h"
#include <QDebug>
class SendTwitDerived : public QWidget , public Ui::sendTwitDialog
{
  Q_OBJECT

  public:
    SendTwitDerived();
  public slots:
    void recieveTwit();
  signals:
    void sendTwit(QString value);
    
};


namespace Ui {
  class sendTwitDerived: public SendTwitDerived {};
}

#endif