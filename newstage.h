#ifndef NEWSTAGE_H
#define NEWSTAGE_H

#include <QDialog>

namespace Ui {
class NewStage;
}

class NewStage : public QDialog
{
    Q_OBJECT

public:
    explicit NewStage(QWidget *parent = 0);
    ~NewStage();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewStage *ui;
};

#endif // NEWSTAGE_H
