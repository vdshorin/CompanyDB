#include "rota.h"

Rota::Rota(QObject *parent) : QObject(parent)
{

}

int Rota::getId() const
{
    return id;
}

void Rota::setId(int value)
{
    id = value;
    emit idChanged();
}

int Rota::getValue() const
{
    return value;
}

void Rota::setValue(const int _value)
{
    value = _value;
    emit valueChanged();
}

void Rota::Print()
{
    qDebug() << "Rota: "<< getValue();
}
