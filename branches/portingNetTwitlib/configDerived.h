#ifndef CONFIGDERIVED_H
#define CONFIGDERIVED_H
#include "ui_config.h"
#include <QDebug>

class ConfigDialogDerived : public QDialog, public Ui::configDialog
{
    Q_OBJECT

    public:
        ConfigDialogDerived();
        virtual ~ConfigDialogDerived();

        static void showDialog();
};

namespace Ui
{
    class configDialogDerived : public ConfigDialogDerived {};
}

#endif // CONFIGDERIVED_H
