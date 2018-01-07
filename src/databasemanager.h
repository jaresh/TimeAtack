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
       static QString getDriverNameByID(int driverID);
       static QSqlQuery getAllDriversForRally(int rallyID);
       static QSqlQuery getAllDrivers();

       /* Stage */
       static void addStage(QString name, double distance, QString surface);
       static void deleteStage(QString name);
       static QSqlQuery getStageByName(QString name);
       static QString getStageNameByID(int stageID);
       static QSqlQuery getAllStages();

       /* Rally */
       static void addRally(QString name,
                            int carID,
                            int numberOfStages,
                            int numberOfDrivers,
                            double distance,
                            std::map<int, int> driverID,
                            std::map<int, int> stageID);
       static void deleteRally(QString name);
       static QSqlQuery getRallyByName(QString name);
       static QSqlQuery getAllRally();
       static QSqlQuery getRallyResults(int rallyID);

       /* Car */
       static QSqlQuery getCarByName(QString name);
       static QString getCarNameByID(int ID);
       static QSqlQuery getAllCars();

       /* Result */
       static QSqlQuery getResultByID(int resultID);

   private:
       static QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
