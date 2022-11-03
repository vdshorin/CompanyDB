#include "practice.h"

Practice::Practice(QObject *parent) : QObject(parent)
{

}

int Practice::getId() const
{
    return id;
}

void Practice::setId(int value)
{
    id = value;
    emit idChanged();
}

QString Practice::getType() const
{
    return type;
}

void Practice::setType(const QString &value)
{
    type = value;
    emit typeChanged();
}

QString Practice::getCompanyName() const
{
    return companyName;
}

void Practice::setCompanyName(const QString &value)
{
    companyName = value;
    emit companyNameChanged();
}

QDate Practice::getDateStart() const
{
    return dateStart;
}

void Practice::setDateStart(const QDate &value)
{
    dateStart = value;
    emit dateStartChanged();
}

QDate Practice::getDateEnd() const
{
    return dateEnd;
}

void Practice::setDateEnd(const QDate &value)
{
    dateEnd = value;
    emit dateEndChanged();
}

//int Practice::getIdAdditionalInfoHumanId() const
//{
//    return idAdditionalInfoHumanId;
//}

//void Practice::setIdAdditionalInfoHumanId(int value)
//{
//    idAdditionalInfoHumanId = value;
//    emit idAdditionalInfoHumanIdChanged();
//}
