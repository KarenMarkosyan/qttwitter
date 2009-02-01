#include "sendTwitDerived.h"


SendTwitDerived::SendTwitDerived()
{
  qDebug()<<"hi";
  setupUi(this);
  QObject::connect(this, SIGNAL(accepted()), this, SLOT(recieveTwit()));
}


void SendTwitDerived::recieveTwit()
{
//   qDebug()<<label->text();
  emit sendTwit(twitLineEdit->text());
}
