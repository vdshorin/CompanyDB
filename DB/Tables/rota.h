#ifndef ROTA_H
#define ROTA_H

#include <QObject>
#include "instruments.h"

class Rota : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int value READ getValue WRITE setValue NOTIFY valueChanged)

public:
    explicit Rota(QObject *parent = nullptr);
    Rota(int _id, int _value): id(_id), value(_value) {}

    int getId() const;
    void setId(int value);

    int getValue() const;
    void setValue(const int value);

    void Print();
private:
    int id;
    int value;

signals:
    void idChanged();
    void valueChanged();
};

#endif // ROTA_H
