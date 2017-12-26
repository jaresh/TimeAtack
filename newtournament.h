#ifndef NEWTOURNAMENT_H
#define NEWTOURNAMENT_H

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include <QDialog>
#include <QMessageBox>
#include <QDesktopWidget>

#include "databasemanager.h"

namespace Ui {
class NewTournament;
}

class NewTournament : public QDialog
{
    Q_OBJECT

public:
    explicit NewTournament(QWidget *parent = 0);
    ~NewTournament();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_buttonBox_accepted();

private:
    Ui::NewTournament *ui;
};

#endif // NEWTOURNAMENT_H
