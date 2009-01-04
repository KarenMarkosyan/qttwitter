#include "sendTwitDerived.h"


SendTwitDerived::SendTwitDerived()
{
  setupUi(this);
  QObject::connect(this, SIGNAL(accepted()), this, SLOT(recieveTwit()));
}


void SendTwitDerived::recieveTwit()
{
  qDebug()<<label->text();
  emit sendTwit(label->text());
}
