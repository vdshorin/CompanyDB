#include "relatives.h"

relatives::relatives(QObject *parent) : QObject(parent)
{

}

QString relatives::getType() const
{
    return type;
}

void relatives::setType(const QString &value)
{
    type = value;
    emit typeChanged();
}

int relatives::getIdHuman() const
{
    return idHuman;
}

void relatives::setIdHuman(int value)
{
    idHuman = value;
    emit idHumanChanged();
}

int relatives::getIdRelative() const
{
    return idRelative;
}

void relatives::setIdRelative(int value)
{
    idRelative = value;
    emit idRelativeChanged();
}
