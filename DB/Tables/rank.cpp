#include "rank.h"

Rank::Rank(QObject *parent) : QObject(parent)
{

}

int Rank::getId() const
{
    return id;
}

void Rank::setId(int value)
{
    id = value;
    emit idChanged();
}

QString Rank::getValue() const
{
    return value;
}

void Rank::setValue(QString &_value)
{
    value = _value;
    emit valueChanged();
}

void Rank::Print()
{
    qDebug() << "Rota: "<< getValue();
}
