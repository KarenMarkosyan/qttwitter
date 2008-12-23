#include "sendTwitDerived.h"


SendTwitDerived::SendTwitDerived()
{
  qDebug()<<"hi";
//   setupUi(this);
  QObject::connect(this, SIGNAL(accepted()), this, SLOT(recieveTwit()));//FIXME why the fuck is this connect not working..
//   QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(recieveTwit()));

}


void SendTwitDerived::recieveTwit()
{
  qDebug()<<"2hi";
  qDebug()<<label->text();
  emit sendTwit(label->text());
}
