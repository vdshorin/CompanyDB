#include "workplacetype.h"

WorkplaceType::WorkplaceType(QObject *parent) : QObject(parent)
{

}

int WorkplaceType::getId() const
{
    return id;
}

void WorkplaceType::setId(int value)
{
    id = value;
    emit idChanged();
}

QString WorkplaceType::getValue() const
{
    return value;
}

void WorkplaceType::setValue(const QString &_value)
{
    value = _value;
    emit valueChanged();
}

void WorkplaceType::Print()
{
    qDebug() << "WorkplaceType: "+getValue();
}
