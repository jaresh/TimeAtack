#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateRallyList();
    connect(&listrally,SIGNAL(finished(int)), this, SLOT(onCloseUpdateRallyList()));
    connect(&newrally,SIGNAL(finished(int)), this, SLOT(onCloseUpdateRallyList()));

    currentResultNumber = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateRallyList()
{

    if(ui->rallyBox->count() > 0)
    {
        ui->rallyBox->clear();
    }

    QSqlQuery rally = DatabaseManager::getAllRally();
    while (rally.next())
    {
        ui->rallyBox->addItem(rally.value(1).toString());
    }
}

void MainWindow::loadResult()
{
    QSqlQuery result = this->currentRally.getResultInfo(currentResultNumber);
    result.next();

    QString stageName = DatabaseManager::getStageNameByID(result.value(2).toInt());
    QString driverName = DatabaseManager::getDriverNameByID(result.value(3).toInt());
    QString time = result.value(5).toString();
    int dnf = result.value(7).toInt();
    int finished = result.value(8).toInt();

    if(dnf)
    {
        ui->dnfBox->setChecked(true);
    }

    if(finished)
    {
        ui->finishedBox->setChecked(true);
    }

    ui->stageName->setText(stageName);
    ui->driverName->setText(driverName);
    ui->minutesBox->setValue(time.mid(0,2).toInt());
    ui->secondsBox->setValue(time.mid(3,2).toInt());
    ui->msecondsBox->setValue(time.mid(6,2).toInt());

    if(currentResultNumber == 0)
    {
        ui->previousResult->setEnabled(false);
    }
    else
    {
        ui->previousResult->setEnabled(true);
    }

    if(currentResultNumber == currentRally.getResultNumber()-1)
    {
        ui->nextResult->setEnabled(false);
    }
    else
    {
        ui->nextResult->setEnabled(true);
    }
}

void MainWindow::updateStatistics()
{

}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionNew_triggered()
{
    newrally.setModal(true);
    newrally.exec();
}

void MainWindow::on_actionEdit_triggered()
{
    editstage.setModal(true);
    editstage.exec();
}

void MainWindow::on_actionEdit_2_triggered()
{
    editdriver.setModal(true);
    editdriver.exec();
}

void MainWindow::on_actionLoad_triggered()
{
    listrally.updateRallyList();
    listrally.setModal(true);
    listrally.exec();
}

void MainWindow::on_loadRally_clicked()
{
    QString rallyName = ui->rallyBox->currentText();

    if(rallyName.compare(""))
    {
        this->currentRally = Rally(rallyName);
    }

    currentResultNumber = 0;
    updateStatistics();
    loadResult();
    ui->tabWidget->setEnabled(true);
}

void MainWindow::onCloseUpdateRallyList()
{
    updateRallyList();
}

void MainWindow::on_previousResult_clicked()
{
    currentResultNumber --;
    loadResult();
}

void MainWindow::on_nextResult_clicked()
{
    currentResultNumber ++;
    loadResult();
}
