#ifndef ADDRESS_H
#define ADDRESS_H

#include <QObject>
#include "instruments.h"

class Address : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString region READ getRegion WRITE setRegion NOTIFY regionChanged)
    Q_PROPERTY(QString sity READ getSity WRITE setSity NOTIFY sityChanged)
    Q_PROPERTY(QString street READ getStreet WRITE setStreet NOTIFY streetChanged)
    Q_PROPERTY(QString building READ getBuilding WRITE setBuilding NOTIFY buildingChanged)
    Q_PROPERTY(QString flat READ getFlat WRITE setFlat NOTIFY flatChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY typeChanged)

public:
    explicit Address(QObject *parent = nullptr);
    Address(int _idAddress, QString _region, QString _city, QString _street, QString _building, QString _flat):
        id(_idAddress), region(_region), sity(_city), street(_street), building(_building), flat(_flat){}

    QString getRegion() const;
    void setRegion(const QString &value);

    QString getSity() const;
    void setSity(const QString &value);

    QString getStreet() const;
    void setStreet(const QString &value);

    QString getBuilding() const;
    void setBuilding(const QString &value);

    QString getFlat() const;
    void setFlat(const QString &value);

    int getId() const;
    void setId(int value);

    void Print();
    QString getType() const;
    void setType(const QString &value);
    QString getAddress();

private:
    int id;
    QString region;
    QString sity;
    QString street;
    QString building;
    QString flat;
    QString type;

signals:
    void idChanged();
    void regionChanged();
    void sityChanged();
    void streetChanged();
    void buildingChanged();
    void flatChanged();
    void typeChanged();
};

#endif // ADDRESS_H
