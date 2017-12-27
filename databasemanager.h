#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QSqlQuery>
#include <QVariant>
#include <iostream>

class DatabaseManager
{
   public:
       DatabaseManager();
       ~DatabaseManager();

       static QSqlDatabase loadDatabase();
       bool isOpen() const;
       QSqlError lastError();

       /* Driver */
       static void addDriver(QString name);
       static void deleteDriver(QString name);
       static QSqlQuery getAllDrivers();

   private:
       static QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
