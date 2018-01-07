#ifndef RALLY_H
#define RALLY_H

#include <QString>
#include <QVector>

#include "databasemanager.h"

class Rally
{
public:
    Rally();
    Rally(QString name);
    QString getName();
    QSqlQuery getResultInfo(int number);
    int getResultNumber();

private:
    int rallyID;
    QString name;
    QString car;
    QVector<int> resultsID;
    int resultsNumber;
    int driversNumber;
    double distance;

};

#endif // RALLY_H
