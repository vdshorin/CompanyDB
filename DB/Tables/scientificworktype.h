#ifndef SCIENTIFICWORKTYPE_H
#define SCIENTIFICWORKTYPE_H

#include <QObject>
#include "instruments.h"

class ScientificWorkType : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString value READ getValue WRITE setValue NOTIFY valueChanged)
public:
    explicit ScientificWorkType(QObject *parent = nullptr);
    ScientificWorkType(int _id, QString _value): id(_id), value(_value){}

    int getId() const;
    void setId(int value);

    QString getValue() const;
    void setValue(const QString &_value);

    void Print();

private:
    int id;
    QString value;

signals:
    void idChanged();
    void valueChanged();

};

#endif // SCIENTIFICWORKTYPE_H
