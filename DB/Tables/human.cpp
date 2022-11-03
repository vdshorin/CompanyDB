#include "human.h"

Human::Human(QObject *parent) : QObject(parent)
{

}

QString Human::getName_first() const
{
    return name_first;
}

void Human::setName_first(const QString &value)
{
    name_first = value;
    emit name_firstChanged();
}

QString Human::getName_second() const
{
    return name_second;
}

void Human::setName_second(const QString &value)
{
    name_second = value;
    emit name_secondChanged();
}

QString Human::getPatronymic() const
{
    return patronymic;
}

void Human::setPatronymic(const QString &value)
{
    patronymic = value;
    emit patronymicChanged();
}

QDate Human::getBirthdate() const
{
    return birthdate;
}

void Human::setBirthdate(const QDate &value)
{
    birthdate = value;
    emit birthdateChanged();
}

QString Human::getPhonenumber() const
{
    return phonenumber;
}

void Human::setPhonenumber(const QString &value)
{
    phonenumber = value;
    emit phonenumberChanged();
}

int Human::getId() const
{
    return id;
}

void Human::setId(int value)
{
    id = value;
    emit idChanged();
}

void Human::Print()
{
    qDebug() <<"int id: " << getId();
    qDebug() <<"QString name_first: " << getName_first();
    qDebug() <<"QString name_second: " << getName_second();
    qDebug() <<"QString patronymic: " + getPatronymic();
    qDebug() <<"QDate birthdate: " + getBirthdate().toString();
    qDebug() <<"QString phonenumber: " + getPhonenumber();
}

AddirionalInfo *Human::getAddirionalInfo() const
{
    return addirionalInfo;
}

void Human::setAddirionalInfo(AddirionalInfo *value)
{
    addirionalInfo = value;
}

QVector<Human *> Human::getFamily() const
{
    return family;
}

void Human::setFamily(const QVector<Human *> &value)
{
    family = value;
}

QVector<Address *> Human::getAddresss() const
{
    return addresss;
}

void Human::setAddresss(const QVector<Address *> &value)
{
    addresss = value;
}

QVector<Workplace *> Human::getWorkplaces() const
{
    return workplaces;
}

void Human::setWorkplaces(const QVector<Workplace *> &value)
{
    workplaces = value;
}

QString Human::getTypeFamily() const
{
    return typeFamily;
}

void Human::setTypeFamily(const QString &value)
{
    typeFamily = value;
    emit typeFamilyChanged();
}
