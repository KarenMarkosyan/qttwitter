#include "configDerived.h"

ConfigDialogDerived::ConfigDialogDerived()
{
    qDebug() << "reached in Configuration Dialog";
    this->setAttribute(Qt::WA_DeleteOnClose);
    setupUi(this);

    // Setting up accepted and rejected functions
    QObject::connect(this, SIGNAL(accepted()), this, SLOT(close()));
    QObject::connect(this, SIGNAL(rejected()), this, SLOT(close()));
}

ConfigDialogDerived::~ConfigDialogDerived()
{
    //Stub for cleanup methods
}

//Static function to create and destroy the config box on-the-fly, hence settings to be stored in a file somewhere
void ConfigDialogDerived::showDialog()
{
    ConfigDialogDerived *configDialog = new ConfigDialogDerived();
    configDialog->show();
}
