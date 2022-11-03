#include "summon.h"

Summon::Summon(QObject *parent) : QObject(parent)
{

}

int Summon::getId() const
{
    return id;
}

void Summon::setId(int value)
{
    id = value;
    emit idChanged();
}

QString Summon::getValue() const
{
    return value;
}

void Summon::setValue(QString &_value)
{
    value = _value;
    emit valueChanged();
}

void Summon::Print()
{
    qDebug() << "Rota: "<< getValue();
}
