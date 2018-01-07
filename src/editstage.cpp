#include "editstage.h"
#include "ui_editstage.h"

EditStage::EditStage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditStage)
{
    ui->setupUi(this);
    updateStageList();
}

EditStage::~EditStage()
{
    delete ui;
}

void EditStage::updateStageList()
{
    while(ui->stageList->count() > 0)
    {
        ui->stageList->takeItem(0);
    }

    QSqlQuery stages = DatabaseManager::getAllStages();
    while (stages.next())
    {
        ui->stageList->addItem(stages.value(1).toString());
    }
}

void EditStage::on_addStage_clicked()
{
    QString stageName = ui->nameInput->text();
    double distance = ui->doubleSpinBox->value();

    QSqlQuery lookForStage = DatabaseManager::getStageByName(stageName);
    bool stageExists = false;

    while (lookForStage.next())
    {
        stageExists = true;
    }

    if(!stageName.compare("") || stageExists)
    {
        QMessageBox::information(0, QString("Information"), QString("Stage name already exists or no name provided."), QMessageBox::Ok);
    }
    else
    {
        if(distance == 0.0)
        {
            QMessageBox::information(0, QString("Information"), QString("Distance can't be zero."), QMessageBox::Ok);
        }
        else
        {
            QString surface = ui->surfaceInput->currentText();

            DatabaseManager::addStage(stageName, distance, surface);
            updateStageList();
        }
    }
}

void EditStage::on_removeStage_clicked()
{
    QList<QListWidgetItem*> items = ui->stageList->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Remove stage", "Do you wan to remove " + item->text(), QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
            DatabaseManager::deleteStage(item->text());
            delete ui->stageList->takeItem(ui->stageList->row(item));
        }
    }
}

void EditStage::on_closeStage_clicked()
{
    close();
}
