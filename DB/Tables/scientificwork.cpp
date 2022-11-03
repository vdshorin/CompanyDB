#include "scientificwork.h"

ScientificWork::ScientificWork(QObject *parent) : QObject(parent)
{

}

int ScientificWork::getId() const
{
    return id;
}

void ScientificWork::setId(int value)
{
    id = value;
    emit idChanged();
}

ScientificWorkType *ScientificWork::getScientificWorkType() const
{
    return scientificWorkType;
}

void ScientificWork::setScientificWorkType(ScientificWorkType* value)
{
    scientificWorkType = value;
    emit scientificWorkTypeChanged();
}

//int ScientificWork::getAdditionalInfoHumanId() const
//{
//    return additionalInfoHumanId;
//}

//void ScientificWork::setAdditionalInfoHumanId(int value)
//{
//    additionalInfoHumanId = value;
//    emit additionalInfoHumanIdChanged();
//}

QString ScientificWork::getInformation() const
{
    return information;
}

void ScientificWork::setInformation(const QString &value)
{
    information = value;
    emit informationChanged();
}

void ScientificWork::Print()
{
    qDebug() <<"int id: " << getId();
    getScientificWorkType()->Print();
    qDebug() <<"QString information: " << getInformation();
}
