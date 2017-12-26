#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <iostream>

class DatabaseManager
{
   public:
       DatabaseManager(QString& name);
       ~DatabaseManager();
       bool isOpen() const;
       QSqlError lastError();

   private:
       QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
