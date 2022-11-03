#include "squad.h"

Squad::Squad(QObject *parent) : QObject(parent)
{

}

int Squad::getValue() const
{
    return value;
}

void Squad::setValue(int _value)
{
    value = _value;
    emit valueChanged();
}

int Squad::getId() const
{
    return id;
}

void Squad::setId(int value)
{
    id = value;
    emit idChanged();
}

void Squad::Print()
{
    qDebug() << "Rota: "<< getValue();
}
