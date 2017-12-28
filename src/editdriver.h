#ifndef EDITDRIVER_H
#define EDITDRIVER_H

#include <QDialog>
#include <QMessageBox>

#include "databasemanager.h"

namespace Ui {
class EditDriver;
}

class EditDriver : public QDialog
{
    Q_OBJECT

public:
    explicit EditDriver(QWidget *parent = 0);
    ~EditDriver();
    void updateDriverList();

private slots:
    void on_addDriver_clicked();
    void on_removeDriver_clicked();
    void on_closeDriver_clicked();

private:
    Ui::EditDriver *ui;
};

#endif // EDITDRIVER_H
