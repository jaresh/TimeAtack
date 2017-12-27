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
    void addRally();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_buttonBox_accepted();

private:
    Ui::NewRally *ui;
};

#endif // NEWRALLY_H
