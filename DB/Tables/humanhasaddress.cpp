#include "humanhasaddress.h"

humanHasAddress::humanHasAddress(QObject *parent) : QObject(parent)
{

}

int humanHasAddress::getIdHuman() const
{
    return idHuman;
}

void humanHasAddress::setIdHuman(int value)
{
    idHuman = value;
    emit idHumanChanged();
}

int humanHasAddress::getIdAddress() const
{
    return idAddress;
}

void humanHasAddress::setIdAddress(int value)
{
    idAddress = value;
    emit idAddressChanged();
}

QString humanHasAddress::getType() const
{
    return type;
}

void humanHasAddress::setType(const QString &value)
{
    type = value;
    emit typeChanged();
}
