#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "newrally.h"
#include "editstage.h"
#include "editdriver.h"
#include "listrally.h"

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
    EditStage editstage;
    editstage.setModal(true);
    editstage.exec();
}

void MainWindow::on_actionEdit_2_triggered()
{
    EditDriver editdriver;
    editdriver.setModal(true);
    editdriver.exec();
}

void MainWindow::on_actionLoad_triggered()
{
    ListRally listrally;
    listrally.setModal(true);
    listrally.exec();
}
