#include "documenttype.h"

DocumentType::DocumentType(QObject *parent) : QObject(parent)
{

}

int DocumentType::getId() const
{
    return id;
}

void DocumentType::setId(int value)
{
    id = value;
    emit idChanged();
}

QString DocumentType::getValue() const
{
    return value;
}

void DocumentType::setValue(const QString &_value)
{
    value = _value;
    emit valueChanged();
}

void DocumentType::Print()
{
    qDebug() << "DocumentType: "+getValue();
}
