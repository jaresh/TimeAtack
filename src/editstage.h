#ifndef EDITSTAGE_H
#define EDITSTAGE_H

#include <QDialog>
#include <QMessageBox>

#include "databasemanager.h"

namespace Ui {
class EditStage;
}

class EditStage : public QDialog
{
    Q_OBJECT

public:
    explicit EditStage(QWidget *parent = 0);
    ~EditStage();
    void updateStageList();

private slots:
    void on_addStage_clicked();
    void on_removeStage_clicked();
    void on_closeStage_clicked();

private:
    Ui::EditStage *ui;
};

#endif // EDITSTAGE_H
