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
    int getStageDistance(QString name);

private slots:
    void on_addStage_clicked();
    void on_removeStage_clicked();

    void on_addDriver_clicked();

    void on_removeDriver_clicked();

private:
    Ui::NewRally *ui;
};

#endif // NEWRALLY_H
