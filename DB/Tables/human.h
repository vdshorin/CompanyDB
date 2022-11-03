#ifndef HUMAN_H
#define HUMAN_H

#include "instruments.h"
#include <QObject>
#include "addirionalinfo.h"
#include "workplace.h"
#include "address.h"

class Human : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name_first READ getName_first WRITE setName_first NOTIFY name_firstChanged)
    Q_PROPERTY(QString name_second READ getName_second WRITE setName_second NOTIFY name_secondChanged)
    Q_PROPERTY(QString patronymic READ getPatronymic WRITE setPatronymic NOTIFY patronymicChanged)
    Q_PROPERTY(QDate birthdate READ getBirthdate WRITE setBirthdate NOTIFY birthdateChanged)
    Q_PROPERTY(QString phonenumber READ getPhonenumber WRITE setPhonenumber NOTIFY phonenumberChanged)

    Q_PROPERTY(QString typeFamily READ getTypeFamily WRITE setTypeFamily NOTIFY typeFamilyChanged)

    Q_PROPERTY(AddirionalInfo* addirionalInfo READ getAddirionalInfo WRITE setAddirionalInfo NOTIFY addirionalInfoChanged)
    Q_PROPERTY(QVector<Human*> family READ getFamily WRITE setFamily NOTIFY familyChanged)
    Q_PROPERTY(QVector<Address*> addresss READ getAddresss WRITE setAddresss NOTIFY addresssChanged)
    Q_PROPERTY(QVector<Workplace*> workplaces READ getWorkplaces WRITE setWorkplaces NOTIFY workplacesChanged)
public:
    explicit Human(QObject *parent = nullptr);
    Human(int _idHuman, QString _name_first, QString _name_second, QString _patronymic, QDate _birthdate, QString _phone_number):
        id(_idHuman), name_first(_name_first), name_second(_name_second), patronymic(_patronymic), birthdate(_birthdate), phonenumber(_phone_number) {}

    QString getName_first() const;
    void setName_first(const QString &value);

    QString getName_second() const;
    void setName_second(const QString &value);

    QString getPatronymic() const;
    void setPatronymic(const QString &value);

    QDate getBirthdate() const;
    void setBirthdate(const QDate &value);

    QString getPhonenumber() const;
    void setPhonenumber(const QString &value);

    int getId() const;
    void setId(int value);

    void Print();
    AddirionalInfo *getAddirionalInfo() const;
    void setAddirionalInfo(AddirionalInfo *value);

    QVector<Human *> getFamily() const;
    void setFamily(const QVector<Human *> &value);

    QVector<Address *> getAddresss() const;
    void setAddresss(const QVector<Address *> &value);

    QVector<Workplace *> getWorkplaces() const;
    void setWorkplaces(const QVector<Workplace *> &value);

    QString getTypeFamily() const;
    void setTypeFamily(const QString &value);

private:
    int id;
    QString name_first;
    QString name_second;
    QString patronymic;
    QDate birthdate;
    QString phonenumber;

    QString typeFamily;

    AddirionalInfo* addirionalInfo;
    QVector<Human*> family;
    QVector<Address*> addresss;
    QVector<Workplace*> workplaces;

signals:
    void idChanged();
    void name_firstChanged();
    void name_secondChanged();
    void patronymicChanged();
    void birthdateChanged();
    void phonenumberChanged();

    void typeFamilyChanged();

    void addirionalInfoChanged();
    void familyChanged();
    void addresssChanged();
    void workplacesChanged();
};

#endif // HUMAN_H
