#include "editdriver.h"
#include "ui_editdriver.h"

EditDriver::EditDriver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDriver)
{
    ui->setupUi(this);
    updateDriverList();
}

EditDriver::~EditDriver()
{
    delete ui;
}

void EditDriver::updateDriverList()
{
    while(ui->driverList->count() > 0)
    {
        ui->driverList->takeItem(0);
    }

    QSqlQuery drivers = DatabaseManager::getAllDrivers();
    while (drivers.next())
    {
        ui->driverList->addItem(drivers.value(1).toString());
    }
}

void EditDriver::on_addDriver_clicked()
{
    QString driverName = ui->nameInput->text();

    QSqlQuery lookForDriver = DatabaseManager::getDriverByName(driverName);
    bool driverExists = false;

    while (lookForDriver.next())
    {
        driverExists = true;
    }

    if(!driverName.compare("") || driverExists)
    {
        QMessageBox::information(0, QString("Information"), QString("Driver name already exists or no name provided."), QMessageBox::Ok);
    }
    else
    {
        DatabaseManager::addDriver(driverName);
        updateDriverList();
    }
}

void EditDriver::on_removeDriver_clicked()
{

    QList<QListWidgetItem*> items = ui->driverList->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Remove driver", "Do you wan to remove " + item->text(), QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
            DatabaseManager::deleteDriver(item->text());
            delete ui->driverList->takeItem(ui->driverList->row(item));
        }
    }
}

void EditDriver::on_closeDriver_clicked()
{
    close();
}
