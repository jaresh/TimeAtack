#include "newrally.h"
#include "ui_newrally.h"

NewRally::NewRally(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewRally)
{
    ui->setupUi(this);

    QSqlDatabase dbRally = DatabaseManager::loadDatabase();
}

NewRally::~NewRally()
{
    delete ui;
}

void NewRally::on_pushButton_clicked()
{
    const QString selected = ui->comboBox->currentText();
    ui->listWidget->addItem(selected);
}

void NewRally::on_pushButton_2_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }
}

void NewRally::on_buttonBox_accepted()
{
    QSqlDatabase dbRally = DatabaseManager::loadDatabase();
}
