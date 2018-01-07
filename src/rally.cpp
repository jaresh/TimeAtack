#include "rally.h"

Rally::Rally()
{

}

Rally::Rally(QString name)
{
    QSqlQuery rallyData = DatabaseManager::getRallyByName(name);

    rallyData.next();
    this->rallyID       = rallyData.value(0).toInt();
    this->name          = rallyData.value(1).toString();

    int carID           = rallyData.value(2).toInt();
    this->car           = DatabaseManager::getCarNameByID(carID);

    this->resultsNumber = rallyData.value(3).toInt() * 2;
    this->driversNumber = rallyData.value(4).toInt();
    this->distance      = rallyData.value(5).toDouble();

    this->resultsID = QVector<int>(resultsNumber);
    QSqlQuery results = DatabaseManager::getRallyResults(this->rallyID);

    for(int i = 0; i < this->resultsID.size(); ++i)
    {
        results.next();
        this->resultsID[i] = results.value(0).toInt();
    }
}

QString Rally::getName()
{
    return this->name;
}

QSqlQuery Rally::getResultInfo(int number)
{
    QSqlQuery result = DatabaseManager::getResultByID(this->resultsID.at(number));
    return result;
}

int Rally::getResultNumber()
{
    return this->resultsNumber;
}
