#include "sendTwitDerived.h"


SendTwitDerived::SendTwitDerived()
{
    qDebug()<<"Reached the SendTwitDerived class";
    this->setAttribute(Qt::WA_DeleteOnClose);
    setupUi(this);
    QObject::connect(this, SIGNAL(accepted()), this, SLOT(recieveTwit()));
    QObject::connect(this, SIGNAL(rejected()), twitLineEdit, SLOT(setFocus()));

    //Enable the Send tweet button only if the text has also been entered
    QObject::connect(twitLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableSendButton(const QString &)));

    //Update the number of characters entered
    QObject::connect(twitLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(updateCharsLeft(const QString &)));

    //Send the tweet to the Twitter server
    QObject::connect(this, SIGNAL(sendTwit(QString)), myTwitter, SLOT(update(QString)));

}


void SendTwitDerived::recieveTwit()
{
  qDebug()<<"Reached the recieveTwit()";

  //removing all the extra whitespace in the tweet using the QString method 'simplified()'
  QString *tweet = new QString(twitLineEdit->text().simplified());

  emit sendTwit(*tweet);

  twitLineEdit->setText("");
  delete tweet;
  twitLineEdit->setFocus();

  //Somehow even after deleting the tweet pointer the object is existing in the memory
}

void SendTwitDerived::enableSendButton(const QString &text)
{
    pushButton->setEnabled(!text.isEmpty());
}

void SendTwitDerived::updateCharsLeft(const QString &text)
{
    charsLeft->setText(QString::number(text.length()).rightJustified(3, '0') + " of " + QString::number(twitLineEdit->maxLength()));
}

//Implementing the static function to prevent application level persistent obhect creation of this class
void SendTwitDerived::showDialog()
{
    SendTwitDerived *sendDialog = new SendTwitDerived();
    sendDialog->show();
}
