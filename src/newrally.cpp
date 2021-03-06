#include "newrally.h"
#include "ui_newrally.h"

NewRally::NewRally(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewRally)
{
    ui->setupUi(this);
    updateDriverList();
    updateStageList();
    updateCarList();
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
        QString type = stages.value(3).toString();

        if(!type.compare("Gravel"))
        {
            ui->stageGravelBox->addItem(stages.value(1).toString());
        }
        else if(!type.compare("Tarmac"))
        {
            ui->stageTarmacBox->addItem(stages.value(1).toString());
        }
        else if(!type.compare("Snow"))
        {
            ui->stageSnowBox->addItem(stages.value(1).toString());
        }
    }
}

void NewRally::updateCarList()
{
    QSqlQuery cars = DatabaseManager::getAllCars();
    while (cars.next())
    {
        ui->carBox->addItem(cars.value(1).toString());
    }
}

int NewRally::getStageDistance(QString name)
{
    QSqlQuery stage = DatabaseManager::getStageByName(name);
    while (stage.next())
    {
        return stage.value(2).toDouble();
    }

    return 0;
}

void NewRally::addStage(const QString name)
{
    ui->stageList->addItem(name);

    double distanceOverall = ui->label_5->text().toDouble() + getStageDistance(name);
    ui->label_5->setText(QString::number(distanceOverall, 'd', 1));
}

void NewRally::on_removeStage_clicked()
{
    QList<QListWidgetItem*> items = ui->stageList->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        int distanceOverall = ui->label_5->text().toDouble() - getStageDistance(item->text());
        ui->label_5->setText(QString::number(distanceOverall, 'd', 1));

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

bool NewRally::on_createRally_clicked()
{
    QString rallyName = ui->nameInput->text();
    std::map<int, int> driverID = {};
    std::map<int, int> stageID = {};
    int carID = 0;
    int numberOfStages = ui->stageList->count();
    int numberOfDrivers = ui->driverList->count();
    double distanceOverall = ui->label_5->text().toDouble();

    QSqlQuery lookForRally = DatabaseManager::getRallyByName(rallyName);
    bool rallyExists = false;

    while (lookForRally.next())
    {
        rallyExists = true;
    }

    if(!rallyName.compare("") || rallyExists)
    {
        QMessageBox::information(0, QString("Information"), QString("Rally name already exists or no name provided."), QMessageBox::Ok);
        return 0;
    }
    else
    {
        if(numberOfDrivers == 0 || numberOfStages == 0)
        {
            QMessageBox::information(0, QString("Information"), QString("Provide at least one stage and one driver."), QMessageBox::Ok);
            return 0;
        }
        else
        {
            for(int i = 0; i < numberOfDrivers; ++i)
            {
                QListWidgetItem* item = ui->driverList->item(i);
                QSqlQuery lookForDriver = DatabaseManager::getDriverByName(item->text());
                lookForDriver.next();

                driverID[i] = lookForDriver.value(0).toInt();
            }

            for(int i = 0; i < numberOfStages; ++i)
            {
                QListWidgetItem* item = ui->stageList->item(i);
                QSqlQuery lookForStage = DatabaseManager::getStageByName(item->text());
                lookForStage.next();

                stageID[i] = lookForStage.value(0).toInt();
            }
        }

        QSqlQuery car =DatabaseManager::getCarByName(ui->carBox->currentText());
        car.next();
        carID = car.value(0).toInt();

        DatabaseManager::addRally(rallyName,
                                  carID,
                                  numberOfStages,
                                  numberOfDrivers,
                                  distanceOverall,
                                  driverID,
                                  stageID);

        close();
        return 1;
    }
}

void NewRally::on_close_clicked()
{
    close();
}

void NewRally::on_addGravelStage_clicked()
{
    const QString selected = ui->stageGravelBox->currentText();
    addStage(selected);
}

void NewRally::on_addTarmacStage_clicked()
{
    const QString selected = ui->stageTarmacBox->currentText();
    addStage(selected);
}

void NewRally::on_addSnowStage_clicked()
{
    const QString selected = ui->stageSnowBox->currentText();
    addStage(selected);
}
