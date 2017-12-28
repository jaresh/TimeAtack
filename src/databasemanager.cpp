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
    query.prepare("INSERT INTO driver (\
                   name, \
                   rally_finished, \
                   distance_driven, \
                   stages_driven, \
                   average_speed, \
                   dnf_number)\
                   VALUES (:name, 0, 0, 0, 0, 0)");

    query.bindValue(":name", name);

    if(!query.exec())
        qDebug() << "addDriver" << db.lastError() << "\n";
}

void DatabaseManager::deleteDriver(QString name)
{
    QSqlQuery query;
    query.prepare("DELETE FROM driver WHERE name=:name");
    query.bindValue(":name", name);

    if(!query.exec())
        qDebug() << "deleteDriver" << db.lastError() << "\n";
}

QSqlQuery DatabaseManager::getDriverByName(QString name)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM driver WHERE name=:name");
    query.bindValue(":name", name);

    if(!query.exec())
        qDebug() << "getDriverByName" << db.lastError() << "\n";

    return query;
}

QSqlQuery DatabaseManager::getAllDrivers()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM driver");
    query.exec();
    return query;
}

/* STAGE */
void DatabaseManager::addStage(QString name, int distance)
{
    QSqlQuery query;
    query.prepare("INSERT INTO stage (\
                   name, \
                   distance) \
                   VALUES (:name, :distance)");

    query.bindValue(":name", name);
    query.bindValue(":distance", distance);

    if(!query.exec())
        qDebug() << "addStage" << db.lastError() << "\n";
}

void DatabaseManager::deleteStage(QString name)
{
    QSqlQuery query;
    query.prepare("DELETE FROM stage WHERE name=:name");
    query.bindValue(":name", name);

    if(!query.exec())
        qDebug() << "deleteStage" << db.lastError() << "\n";
}

QSqlQuery DatabaseManager::getStageByName(QString name)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM stage WHERE name=:name");
    query.bindValue(":name", name);

    if(!query.exec())
        qDebug() << "StageByName" << db.lastError() << "\n";

    return query;
}

QSqlQuery DatabaseManager::getAllStages()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM stage");
    query.exec();
    return query;
}
