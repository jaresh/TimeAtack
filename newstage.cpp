#include "newstage.h"
#include "ui_newstage.h"

NewStage::NewStage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewStage)
{
    ui->setupUi(this);
}

NewStage::~NewStage()
{
    delete ui;
}

void NewStage::on_buttonBox_accepted()
{
   // ui->lineEdit->text()
}
