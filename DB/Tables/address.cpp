#include "address.h"

Address::Address(QObject *parent) : QObject(parent)
{

}

QString Address::getRegion() const
{
    return region;
}

void Address::setRegion(const QString &value)
{
    region = value;
    emit regionChanged();
}

QString Address::getSity() const
{
    return sity;
}

void Address::setSity(const QString &value)
{
    sity = value;
    emit sityChanged();
}

QString Address::getStreet() const
{
    return street;
}

void Address::setStreet(const QString &value)
{
    street = value;
    emit streetChanged();
}

QString Address::getBuilding() const
{
    return building;
}

void Address::setBuilding(const QString &value)
{
    building = value;
    emit buildingChanged();
}

QString Address::getFlat() const
{
    return flat;
}

void Address::setFlat(const QString &value)
{
    flat = value;
    emit flatChanged();
}

int Address::getId() const
{
    return id;
}

void Address::setId(int value)
{
    id = value;
    emit idChanged();
}

void Address::Print()
{
    qDebug() <<"int id: " << getId();
    qDebug() <<"region: " << getRegion();
    qDebug() <<"sity: " << getSity();
    qDebug() <<"street: " + getStreet();
    qDebug() <<"building: " + getBuilding();
    qDebug() <<"flat: " + getFlat();
}

QString Address::getType() const
{
    return type;
}

void Address::setType(const QString &value)
{
    type = value;
    emit typeChanged();
}

QString Address::getAddress()
{
    return getRegion() + ", " \
            + getSity() + ", " \
            + getStreet() + ", " \
            + getBuilding() + ", " \
            + getFlat();
}
