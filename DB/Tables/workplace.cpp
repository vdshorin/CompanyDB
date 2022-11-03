#include "workplace.h"

Workplace::Workplace(QObject *parent) : QObject(parent)
{

}

int Workplace::getId() const
{
    return id;
}

void Workplace::setId(int value)
{
    id = value;
    emit idChanged();
}

QString Workplace::getName() const
{
    return name;
}

void Workplace::setName(const QString &value)
{
    name = value;
    emit nameChanged();
}

WorkplaceType *Workplace::getWorkplaceType() const
{
    return workplaceType;
}

void Workplace::setWorkplaceType(WorkplaceType *value)
{
    workplaceType = value;
    emit workplaceTypeChanged();
}

QString Workplace::getPosition() const
{
    return position;
}

void Workplace::setPosition(const QString &value)
{
    position = value;
    emit positionChanged();
}

QString Workplace::getActivity() const
{
    return activity;
}

void Workplace::setActivity(const QString &value)
{
    activity = value;
    emit activityChanged();
}


void Workplace::Print()
{
    qDebug() <<"int id:" << getId();
    qDebug() <<"QString name:" << getName();
    getWorkplaceType()->Print();
    qDebug() <<"QString position: " << getPosition();
    qDebug() <<"QString activity: " + getActivity();
    qDebug() <<"QString dateStart: " + getDateStart().toString();
    qDebug() <<"QString dateEnd: " + getDateEnd().toString();
}

QDate Workplace::getDateStart() const
{
    return dateStart;
}

void Workplace::setDateStart(const QDate &value)
{
    dateStart = value;
    emit dateStartChanged();
}

QDate Workplace::getDateEnd() const
{
    return dateEnd;
}

void Workplace::setDateEnd(const QDate &value)
{
    dateEnd = value;
    emit dateEndChanged();
}
