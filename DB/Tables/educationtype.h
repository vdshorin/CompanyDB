#ifndef EDUCATIONTYPE_H
#define EDUCATIONTYPE_H

#include <QObject>
#include "instruments.h"

class EducationType : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString value READ getValue WRITE setValue NOTIFY valueChanged)
public:
    explicit EducationType(QObject *parent = nullptr);
    EducationType(int _id, QString _value): id(_id), value(_value) {}

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

#endif // EDUCATIONTYPE_H
