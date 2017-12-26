#include "databasemanager.h"

DatabaseManager::DatabaseManager(QString& name)
{
   db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName(name.append(".db"));

   if (!db.open())
   {
       std::cout << "Error: connection with database fail" << std::endl;
   }
   else
   {
       std::cout << "Database: connection ok" << std::endl;
   }
}

DatabaseManager::~DatabaseManager()
{
    if (db.isOpen())
    {
        db.close();
    }
}

bool DatabaseManager::isOpen() const
{
    return db.isOpen();
}

QSqlError DatabaseManager::lastError()
{
   return db.lastError();
}


