#ifndef RANK_H
#define RANK_H

#include <QObject>
#include "instruments.h"

class Rank : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString value READ getValue WRITE setValue NOTIFY valueChanged)
public:
    explicit Rank(QObject *parent = nullptr);
    Rank(int _id, QString _value): id(_id), value(_value) {}

    int getId() const;
    void setId(int value);

    QString getValue() const;
    void setValue(QString &_value);

    void Print();

private:
    int id;
    QString value;

signals:
    void idChanged();
    void valueChanged();
};

#endif // RANK_H
