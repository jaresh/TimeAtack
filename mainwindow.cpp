#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "newrally.h"
#include "newstage.h"
#include "newdriver.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionNew_triggered()
{
    NewRally newrally;
    newrally.setModal(true);
    newrally.exec();
}

void MainWindow::on_actionEdit_triggered()
{
    NewStage newstage;
    newstage.setModal(true);
    newstage.exec();
}

void MainWindow::on_actionEdit_2_triggered()
{
    NewDriver newdriver;
    newdriver.setModal(true);
    newdriver.exec();
}
