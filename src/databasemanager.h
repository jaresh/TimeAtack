#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
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
       static QSqlQuery getDriverByName(QString name);
       static QSqlQuery getAllDrivers();

       /* Stage */
       static void addStage(QString name, int distance);
       static void deleteStage(QString name);
       static QSqlQuery getStageByName(QString name);
       static QSqlQuery getAllStages();

       /* Rally */
       static void addRally(QString name,
                            int carID,
                            int numberOfStages,
                            int numberOfDrivers,
                            int distance,
                            std::map<int, int> driverID,
                            std::map<int, int> stageID);
       static void deleteRally(QString name);
       static QSqlQuery getRallyByName(QString name);
       static QSqlQuery getAllRally();


       /* Car */
       static QSqlQuery getCarByName(QString name);
       static QSqlQuery getAllCars();

   private:
       static QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
