#ifndef NEWDRIVER_H
#define NEWDRIVER_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class NewDriver;
}

class NewDriver : public QDialog
{
    Q_OBJECT

public:
    explicit NewDriver(QWidget *parent = 0);
    ~NewDriver();
    void updateDriverList();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::NewDriver *ui;
};

#endif // NEWDRIVER_H
