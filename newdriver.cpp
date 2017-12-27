#include "newdriver.h"
#include "ui_newdriver.h"

NewDriver::NewDriver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDriver)
{
    ui->setupUi(this);
    updateDriverList();
}

NewDriver::~NewDriver()
{
    delete ui;
}

void NewDriver::updateDriverList()
{
    while(ui->listWidget->count() > 0)
    {
        ui->listWidget->takeItem(0);
    }

    QSqlQuery drivers = DatabaseManager::getAllDrivers();
    while (drivers.next())
    {
        ui->listWidget->addItem(drivers.value(1).toString());
    }
}

void NewDriver::on_pushButton_2_clicked()
{
    DatabaseManager::addDriver(ui->lineEdit->text());
    updateDriverList();
}

void NewDriver::on_pushButton_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        DatabaseManager::deleteDriver(item->text());
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }
}

void NewDriver::on_pushButton_3_clicked()
{
    close();
}
