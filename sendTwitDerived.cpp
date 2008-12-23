#include "sendTwitDerived.h"


SendTwitDerived::SendTwitDerived()
{
  qDebug()<<"hi";
//   setupUi(this);
//   QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(recieveTwit()));
}


void SendTwitDerived::recieveTwit()
{
  qDebug()<<label->text();
  emit sendTwit(label->text());
}