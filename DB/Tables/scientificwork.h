#ifndef SCIENTIFICWORK_H
#define SCIENTIFICWORK_H

#include <QObject>
#include "scientificworktype.h"

class ScientificWork : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(ScientificWorkType* scientificWorkType READ getScientificWorkType WRITE setScientificWorkType NOTIFY scientificWorkTypeChanged)
//    Q_PROPERTY(int additionalInfoHumanId READ getAdditionalInfoHumanId WRITE setAdditionalInfoHumanId NOTIFY additionalInfoHumanIdChanged)
    Q_PROPERTY(QString information READ getInformation WRITE setInformation NOTIFY informationChanged)
public:
    explicit ScientificWork(QObject *parent = nullptr);
    ScientificWork(int _id, QString _info, ScientificWorkType* _scientificWorkType):
    id(_id), scientificWorkType(_scientificWorkType), information(_info){}

    int getId() const;
    void setId(int value);

    ScientificWorkType* getScientificWorkType() const;
    void setScientificWorkType(ScientificWorkType* value);

//    int getAdditionalInfoHumanId() const;
//    void setAdditionalInfoHumanId(int value);

    QString getInformation() const;
    void setInformation(const QString &value);

    void Print();

private:
    int id;
    ScientificWorkType* scientificWorkType;
//    int additionalInfoHumanId;
    QString information;

signals:
    void idChanged();
    void scientificWorkTypeChanged();
//    void additionalInfoHumanIdChanged();
    void informationChanged();

};

#endif // SCIENTIFICWORK_H
