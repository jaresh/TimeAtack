#include "newrally.h"
#include "ui_newrally.h"

NewRally::NewRally(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewRally)
{
    ui->setupUi(this);
    updateDriverList();
    updateStageList();
}

NewRally::~NewRally()
{
    delete ui;
}

void NewRally::updateDriverList()
{
    QSqlQuery drivers = DatabaseManager::getAllDrivers();
    while (drivers.next())
    {
        ui->driverBox->addItem(drivers.value(1).toString());
    }
}

void NewRally::updateStageList()
{
    QSqlQuery stages = DatabaseManager::getAllStages();
    while (stages.next())
    {
        ui->stageBox->addItem(stages.value(1).toString());
    }
}

int NewRally::getStageDistance(QString name)
{
    QSqlQuery stage = DatabaseManager::getStageByName(name);
    while (stage.next())
    {
        return stage.value(2).toInt();
    }

    return 0;
}

void NewRally::on_addStage_clicked()
{
    const QString selected = ui->stageBox->currentText();
    ui->stageList->addItem(selected);

    int distanceOverall = ui->label_5->text().toInt() + getStageDistance(selected);
    ui->label_5->setText(QString::number(distanceOverall));
}

void NewRally::on_removeStage_clicked()
{
    QList<QListWidgetItem*> items = ui->stageList->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        int distanceOverall = ui->label_5->text().toInt() - getStageDistance(item->text());
        ui->label_5->setText(QString::number(distanceOverall));

        delete ui->stageList->takeItem(ui->stageList->row(item));
    }
}

void NewRally::on_addDriver_clicked()
{
    const QString selected = ui->driverBox->currentText();
    if(selected.compare(""))
    {
        ui->driverList->addItem(selected);
        ui->driverBox->removeItem(ui->driverBox->currentIndex());
    }
}

void NewRally::on_removeDriver_clicked()
{
    QList<QListWidgetItem*> items = ui->driverList->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        ui->driverBox->addItem(item->text());
        delete ui->driverList->takeItem(ui->driverList->row(item));
    }
}
