/********************************************************************************
** Form generated from reading ui file 'login.ui'
**
** Created: Fri Jun 20 05:26:10 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *loginLineEdit;
    QLabel *label;
    QLineEdit *passwordLineEdit;
    QCheckBox *rememberPasswordCheckBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *loginDialog)
    {
    if (loginDialog->objectName().isEmpty())
        loginDialog->setObjectName(QString::fromUtf8("loginDialog"));
    loginDialog->resize(282, 211);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(loginDialog->sizePolicy().hasHeightForWidth());
    loginDialog->setSizePolicy(sizePolicy);
    loginDialog->setMaximumSize(QSize(282, 211));
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/twitter/twitter_system_tray1.png")), QIcon::Normal, QIcon::Off);
    loginDialog->setWindowIcon(icon);
    verticalLayoutWidget = new QWidget(loginDialog);
    verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
    verticalLayoutWidget->setGeometry(QRect(10, 10, 261, 191));
    verticalLayout = new QVBoxLayout(verticalLayoutWidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    label_2 = new QLabel(verticalLayoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setScaledContents(false);
    label_2->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label_2);

    loginLineEdit = new QLineEdit(verticalLayoutWidget);
    loginLineEdit->setObjectName(QString::fromUtf8("loginLineEdit"));

    verticalLayout->addWidget(loginLineEdit);

    label = new QLabel(verticalLayoutWidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label);

    passwordLineEdit = new QLineEdit(verticalLayoutWidget);
    passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    verticalLayout->addWidget(passwordLineEdit);

    rememberPasswordCheckBox = new QCheckBox(verticalLayoutWidget);
    rememberPasswordCheckBox->setObjectName(QString::fromUtf8("rememberPasswordCheckBox"));
    rememberPasswordCheckBox->setLayoutDirection(Qt::LeftToRight);
    rememberPasswordCheckBox->setTristate(false);

    verticalLayout->addWidget(rememberPasswordCheckBox);

    buttonBox = new QDialogButtonBox(verticalLayoutWidget);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

    verticalLayout->addWidget(buttonBox);


    retranslateUi(loginDialog);
    QObject::connect(buttonBox, SIGNAL(accepted()), loginDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), loginDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
    loginDialog->setWindowTitle(QApplication::translate("loginDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("loginDialog", "Enter You Login Name:", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("loginDialog", "Enter Your Password:", 0, QApplication::UnicodeUTF8));
    rememberPasswordCheckBox->setText(QApplication::translate("loginDialog", "Remeber Password", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(loginDialog);
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
