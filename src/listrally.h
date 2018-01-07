#ifndef LISTRALLY_H
#define LISTRALLY_H

#include <QDialog>
#include <QMessageBox>

#include "databasemanager.h"
#include "rally.h"

namespace Ui {
class ListRally;
}

class ListRally : public QDialog
{
    Q_OBJECT

public:
    explicit ListRally(QWidget *parent = 0);
    ~ListRally();
    void updateRallyList();

private slots:
    void on_removeRally_clicked();

private:
    Ui::ListRally *ui;
};

#endif // LISTRALLY_H
