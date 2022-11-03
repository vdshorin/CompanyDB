#include "scientificworktype.h"

ScientificWorkType::ScientificWorkType(QObject *parent) : QObject(parent)
{

}

int ScientificWorkType::getId() const
{
    return id;
}

void ScientificWorkType::setId(int value)
{
    id = value;
    emit idChanged();
}

QString ScientificWorkType::getValue() const
{
    return value;
}

void ScientificWorkType::setValue(const QString &_value)
{
    value = _value;
    valueChanged();
}

void ScientificWorkType::Print()
{
    qDebug() << "ScientificWorkType: "+getValue();
}
