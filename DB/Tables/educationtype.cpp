#include "educationtype.h"

EducationType::EducationType(QObject *parent) : QObject(parent)
{

}

int EducationType::getId() const
{
    return id;
}

void EducationType::setId(int value)
{
    id = value;
    emit idChanged();
}

QString EducationType::getValue() const
{
    return value;
}

void EducationType::setValue(const QString &_value)
{
    value = _value;
    emit valueChanged();
}

void EducationType::Print()
{
    qDebug() << "EducationType: "+getValue();
}
