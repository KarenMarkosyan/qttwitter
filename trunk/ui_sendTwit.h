/********************************************************************************
** Form generated from reading ui file 'sendTwit.ui'
**
** Created: Mon May 5 16:36:46 2008
**      by: Qt User Interface Compiler version 4.4.0-snapshot-20080429
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SENDTWIT_H
#define UI_SENDTWIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sendTwitDialog
{
public:
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *twitLineEdit;
    QLabel *label;

    void setupUi(QDialog *sendTwitDialog)
    {
    if (sendTwitDialog->objectName().isEmpty())
        sendTwitDialog->setObjectName(QString::fromUtf8("sendTwitDialog"));
    sendTwitDialog->resize(340, 167);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(sendTwitDialog->sizePolicy().hasHeightForWidth());
    sendTwitDialog->setSizePolicy(sizePolicy);
    sendTwitDialog->setMaximumSize(QSize(340, 167));
    groupBox = new QGroupBox(sendTwitDialog);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 10, 321, 141));
    gridLayoutWidget = new QWidget(groupBox);
    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(10, 20, 301, 111));
    gridLayout = new QGridLayout(gridLayoutWidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);
    pushButton = new QPushButton(gridLayoutWidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    gridLayout->addWidget(pushButton, 2, 0, 1, 1);

    pushButton_2 = new QPushButton(gridLayoutWidget);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

    gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

    twitLineEdit = new QLineEdit(gridLayoutWidget);
    twitLineEdit->setObjectName(QString::fromUtf8("twitLineEdit"));
    twitLineEdit->setMaxLength(140);
    twitLineEdit->setFrame(true);
    twitLineEdit->setDragEnabled(true);

    gridLayout->addWidget(twitLineEdit, 1, 0, 1, 2);

    label = new QLabel(gridLayoutWidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setTextFormat(Qt::RichText);
    label->setScaledContents(true);
    label->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label, 0, 0, 1, 2);


    retranslateUi(sendTwitDialog);
    QObject::connect(pushButton, SIGNAL(clicked()), sendTwitDialog, SLOT(accept()));
    QObject::connect(pushButton_2, SIGNAL(clicked()), sendTwitDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(sendTwitDialog);
    } // setupUi

    void retranslateUi(QDialog *sendTwitDialog)
    {
    sendTwitDialog->setWindowTitle(QApplication::translate("sendTwitDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QString());
    pushButton->setText(QApplication::translate("sendTwitDialog", "Ok", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("sendTwitDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("sendTwitDialog", "<B>Type Your Twit Here</B>", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(sendTwitDialog);
    } // retranslateUi

};

namespace Ui {
    class sendTwitDialog: public Ui_sendTwitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDTWIT_H
