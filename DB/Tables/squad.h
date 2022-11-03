#ifndef SQUAD_H
#define SQUAD_H

#include <QObject>
#include "instruments.h"

class Squad : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int value READ getValue WRITE setValue NOTIFY valueChanged)

public:
    explicit Squad(QObject *parent = nullptr);
    Squad(int _id, int _value): id(_id), value(_value) {}

    int getId() const;
    void setId(int value);

    int getValue() const;
    void setValue(int value);

    void Print();

private:
    int id;
    int value;

signals:
    void idChanged();
    void valueChanged();
};

#endif // SQUAD_H
