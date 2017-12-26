#include "mainwindow.h"
#include "newtournament.h"
#include "ui_mainwindow.h"

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
    NewTournament newtournament;
    newtournament.setModal(true);
    newtournament.exec();
}
