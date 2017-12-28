#include "listrally.h"
#include "ui_listrally.h"

ListRally::ListRally(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListRally)
{
    ui->setupUi(this);
    updateRallyList();
}

ListRally::~ListRally()
{
    delete ui;
}

void ListRally::updateRallyList()
{
    while(ui->rallyList->count() > 0)
    {
        ui->rallyList->takeItem(0);
    }

    QSqlQuery rally = DatabaseManager::getAllRally();
    while (rally.next())
    {
        ui->rallyList->addItem(rally.value(1).toString());
    }
}

void ListRally::on_removeRally_clicked()
{
    QList<QListWidgetItem*> items = ui->rallyList->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Remove rally", "Do you want to remove " + item->text(), QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
            DatabaseManager::deleteRally(item->text());
            delete ui->rallyList->takeItem(ui->rallyList->row(item));
        }
    }
}
