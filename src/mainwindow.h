#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QListWidgetItem>

#include "databasemanager.h"
#include "rally.h"
#include "newrally.h"
#include "editstage.h"
#include "editdriver.h"
#include "listrally.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateRallyList();
    void loadRallyToUI();
    void loadResult();
    void updateStatistics();

private slots:
    void on_actionExit_triggered();
    void on_actionNew_triggered();
    void on_actionEdit_triggered();
    void on_actionEdit_2_triggered();
    void on_actionLoad_triggered();
    void on_loadRally_clicked();
    void onCloseUpdateRallyList();

    void on_previousResult_clicked();

    void on_nextResult_clicked();

private:
    Ui::MainWindow *ui;

    Rally currentRally;
    ListRally listrally;
    NewRally newrally;
    EditStage editstage;
    EditDriver editdriver;

    int currentResultNumber;
};

#endif // MAINWINDOW_H
