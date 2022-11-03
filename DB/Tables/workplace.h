#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <QObject>
#include "instruments.h"
#include "workplacetype.h"

class Workplace : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(WorkplaceType* workplaceType READ getWorkplaceType WRITE setWorkplaceType NOTIFY workplaceTypeChanged)
    Q_PROPERTY(QString position READ getPosition WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QString activity READ getActivity WRITE setActivity NOTIFY activityChanged)
    Q_PROPERTY(QDate dateStart READ getDateStart WRITE setDateStart NOTIFY dateStartChanged)
    Q_PROPERTY(QDate dateEnd READ getDateEnd WRITE setDateEnd NOTIFY dateEndChanged)
public:
    explicit Workplace(QObject *parent = nullptr);
    Workplace(int _idPractice, QString _name, WorkplaceType* _workplaceType, QString _position, QString _activity, QDate _dateStart, QDate _dateEnd):
    id(_idPractice), name(_name), workplaceType(_workplaceType), position(_position), activity(_activity), dateStart(_dateStart), dateEnd(_dateEnd){}

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

    WorkplaceType *getWorkplaceType() const;
    void setWorkplaceType(WorkplaceType *value);

    QString getPosition() const;
    void setPosition(const QString &value);

    QString getActivity() const;
    void setActivity(const QString &value);

    void Print();
    QDate getDateStart() const;
    void setDateStart(const QDate &value);

    QDate getDateEnd() const;
    void setDateEnd(const QDate &value);

private:
    int id;
    QString name;
    WorkplaceType* workplaceType;
    QString position;
    QString activity;
    QDate dateStart;
    QDate dateEnd;

signals:
    void idChanged();
    void nameChanged();
    void workplaceTypeChanged();
    void positionChanged();
    void activityChanged();
    void dateStartChanged();
    void dateEndChanged();
};

#endif // WORKPLACE_H
