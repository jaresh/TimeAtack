#include <iostream>
#include <QApplication>

#include "mainwindow.h"
#include "databasemanager.h"

int main(int argc, char *argv[])
{
    DatabaseManager *db = new DatabaseManager();

    if(db->isOpen())
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        return a.exec();
    }
    else
    {
        std::cout << "Error. Couldn't load database!" << std::endl;

        return 1;
    }

    return 0;
}
