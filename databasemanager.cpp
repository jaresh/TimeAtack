#include "databasemanager.h"

QSqlDatabase DatabaseManager::db = QSqlDatabase::addDatabase("QSQLITE");

DatabaseManager::DatabaseManager()
{
   db.setDatabaseName("TimeAttack.db");

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

QSqlDatabase DatabaseManager::loadDatabase()
{
    return db;
}

bool DatabaseManager::isOpen() const
{
    return db.isOpen();
}

QSqlError DatabaseManager::lastError()
{
   return db.lastError();
}

/* DRIVER */
void DatabaseManager::addDriver(QString name)
{
    QSqlQuery query;
    query.prepare("INSERT INTO driver(name) VALUES (:name)");
    query.bindValue(":name", name);
    query.exec();
}

void DatabaseManager::deleteDriver(QString name)
{
    QSqlQuery query;
    query.prepare("DELETE FROM driver WHERE name=:name");
    query.bindValue(":name", name);
    query.exec();
}

QSqlQuery DatabaseManager::getAllDrivers()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM driver");
    query.exec();
    return query;
}
