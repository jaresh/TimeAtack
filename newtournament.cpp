#include "newtournament.h"
#include "ui_newtournament.h"

NewTournament::NewTournament(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTournament)
{
    ui->setupUi(this);

    std::ifstream infile("tracks.txt");
    if(!infile) {
        QMessageBox trackError( QMessageBox::Critical, "No tracks", "Not found tracks.txt file.", QMessageBox::NoButton, this );

        QSize mSize = trackError.sizeHint();
        QRect screenRect = QDesktopWidget().screen()->rect();
        trackError.setGeometry(screenRect.width()/2 - mSize.width()/2, screenRect.height()/2 - mSize.height()/2, 100, 100);
        trackError.exec();
    }
    else {
        std::string line;
        while (std::getline(infile, line))
        {
            ui->comboBox->addItem(QString::fromStdString(line));
        }
    }
}

NewTournament::~NewTournament()
{
    delete ui;
}

void NewTournament::on_pushButton_clicked()
{
    const QString selected = ui->comboBox->currentText();
    ui->listWidget->addItem(selected);
}

void NewTournament::on_pushButton_2_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }
}

void NewTournament::on_buttonBox_accepted()
{
    QString dbname = ui->lineEdit->text();
    DatabaseManager db(dbname);
}
