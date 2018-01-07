#ifndef NEWRALLY_H
#define NEWRALLY_H

#include <QDialog>
#include <QMessageBox>
#include <QDesktopWidget>

#include "databasemanager.h"

namespace Ui {
class NewRally;
}

class NewRally : public QDialog
{
    Q_OBJECT

public:
    explicit NewRally(QWidget *parent = 0);
    ~NewRally();
    void updateDriverList();
    void updateStageList();
    void updateCarList();
    int getStageDistance(QString name);
    void addStage(const QString);

private slots:
    void on_removeStage_clicked();
    void on_addDriver_clicked();
    void on_removeDriver_clicked();
    bool on_createRally_clicked();
    void on_close_clicked();
    void on_addGravelStage_clicked();

    void on_addTarmacStage_clicked();

    void on_addSnowStage_clicked();

private:
    Ui::NewRally *ui;
};

#endif // NEWRALLY_H
