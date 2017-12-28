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
    {
        qDebug() << "addDriver" << db.lastError() << "\n";
    }
}

void DatabaseManager::deleteDriver(QString name)
{
    QSqlQuery query;
    query.prepare("DELETE FROM driver WHERE name=:name");
    query.bindValue(":name", name);

    if(!query.exec())
    {
        qDebug() << "deleteDriver" << db.lastError() << "\n";
    }
}

QSqlQuery DatabaseManager::getDriverByName(QString name)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM driver WHERE name=:name");
    query.bindValue(":name", name);

    if(!query.exec())
    {
        qDebug() << "getDriverByName" << db.lastError() << "\n";
    }

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
    {
        qDebug() << "addStage" << db.lastError() << "\n";
    }
}

void DatabaseManager::deleteStage(QString name)
{
    QSqlQuery query;
    query.prepare("DELETE FROM stage WHERE name=:name");
    query.bindValue(":name", name);

    if(!query.exec())
    {
        qDebug() << "deleteStage" << db.lastError() << "\n";
    }
}

QSqlQuery DatabaseManager::getStageByName(QString name)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM stage WHERE name=:name");
    query.bindValue(":name", name);

    if(!query.exec())
    {
        qDebug() << "StageByName" << db.lastError() << "\n";
    }

    return query;
}

QSqlQuery DatabaseManager::getAllStages()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM stage");
    query.exec();
    return query;
}

/* RALLY */
void DatabaseManager::addRally(QString name,
                               int carID,
                               int numberOfStages,
                               int numberOfDrivers,
                               int distance,
                               std::map<int, int> driverID,
                               std::map<int, int> stageID)
{
    QSqlQuery query;
    query.prepare("INSERT INTO rally (\
                   name, \
                   car_id, \
                   number_of_stages, \
                   number_of_drivers, \
                   distance) \
                   VALUES (\
                   :name, \
                   :car_id, \
                   :number_of_stages, \
                   :number_of_drivers, \
                   :distance)");

    query.bindValue(":name", name);
    query.bindValue(":car_id", carID);
    query.bindValue(":number_of_stages", numberOfStages);
    query.bindValue(":number_of_drivers", numberOfDrivers);
    query.bindValue(":distance", distance);

    if(!query.exec())
    {
        qDebug() << "addRally" << db.lastError() << "\n";
    }

    else
    {
        int rallyID = query.lastInsertId().toInt();

        for(int i = 0; i < numberOfStages; i++)
        {
            for(int j = 0; j < numberOfDrivers; j++)
            {
                query.prepare("INSERT INTO result (\
                               rally_id, \
                               stage_id, \
                               driver_id, \
                               car_id, \
                               finished) \
                               VALUES (\
                               :rally_id, \
                               :stage_id, \
                               :driver_id, \
                               :car_id, \
                               :finished)");

                query.bindValue(":rally_id", rallyID);
                query.bindValue(":stage_id", stageID.find(i)->second);
                query.bindValue(":driver_id", driverID.find(j)->second);
                query.bindValue(":car_id", carID);
                query.bindValue(":finished", 0);

                if(!query.exec())
                {
                    qDebug() << "createRallyResults" << db.lastError() << "\n";
                }
            }
        }
    }
}

void DatabaseManager::deleteRally(QString name)
{
    QSqlQuery query = getRallyByName(name);
    query.next();

    QString rallyName = query.value(1).toString();
    int rallyID = query.value(0).toInt();

    query.prepare("DELETE FROM rally WHERE name=:name");
    query.bindValue(":name", rallyName);

    if(!query.exec())
    {
        qDebug() << "deleteRally" << db.lastError() << "\n";
    }
    else
    {
        std::cout << "Rally id:" << rallyID << std::endl;

        query.prepare("DELETE FROM result WHERE rally_id=:id");
        query.bindValue(":id", rallyID);

        if(!query.exec())
        {
            qDebug() << "deleteResults" << db.lastError() << "\n";
        }
    }
}

QSqlQuery DatabaseManager::getRallyByName(QString name)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM rally WHERE name=:name");
    query.bindValue(":name", name);

    if(!query.exec())
    {
        qDebug() << "RallyByName" << db.lastError() << "\n";
    }

    return query;
}

QSqlQuery DatabaseManager::getAllRally()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM rally");
    query.exec();
    return query;
}

/* CAR */
QSqlQuery DatabaseManager::getCarByName(QString name)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM car WHERE name=:name");
    query.bindValue(":name", name);

    if(!query.exec())
        qDebug() << "CarByName" << db.lastError() << "\n";

    return query;
}

QSqlQuery DatabaseManager::getAllCars()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM car");
    query.exec();
    return query;
}
