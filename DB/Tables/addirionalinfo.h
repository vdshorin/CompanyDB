#ifndef ADDIRIONALINFO_H
#define ADDIRIONALINFO_H

#include <QObject>
#include "rota.h"
#include "squad.h"
#include "rank.h"
#include "summon.h"
#include "document.h"
#include "education.h"
#include "practice.h"
#include "scientificwork.h"

class AddirionalInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int idHuman READ getIdHuman WRITE setIdHuman NOTIFY idHumanChanged)
    Q_PROPERTY(Rota* rota READ getRota WRITE setRota NOTIFY rotaChanged)
    Q_PROPERTY(Squad* squad READ getSquad WRITE setSquad NOTIFY squadChanged)
    Q_PROPERTY(Rank* rank READ getRank WRITE setRank NOTIFY rankChanged)
    Q_PROPERTY(Summon* summon READ getSummon WRITE setSummon NOTIFY summonChanged)
    Q_PROPERTY(QString religion READ getReligion WRITE setReligion NOTIFY religionChanged)
    Q_PROPERTY(QString nationality READ getNationality WRITE setNationality NOTIFY nationalityChanged)
    Q_PROPERTY(QString maritalStatus READ getMaritalStatus WRITE setMaritalStatus NOTIFY maritalStatusChanged)
    Q_PROPERTY(QString militaryDepartament READ getMilitaryDepartament WRITE setMilitaryDepartament NOTIFY militaryDepartamentChanged)
    Q_PROPERTY(QDate departureDate READ getDepartureDate WRITE setDepartureDate NOTIFY departureDateChanged)
    Q_PROPERTY(QDate soldierDate READ getSoldierDate WRITE setSoldierDate NOTIFY soldierDateChanged)
    Q_PROPERTY(QString personalNumber READ getPersonalNumber WRITE setPersonalNumber NOTIFY personalNumberChanged)
    Q_PROPERTY(QString overseasTrips READ getOverseasTrips WRITE setOverseasTrips NOTIFY overseasTripsChanged)
    Q_PROPERTY(QString software READ getSoftware WRITE setSoftware NOTIFY softwareChanged)
    Q_PROPERTY(QString programmingLanguages READ getProgrammingLanguages WRITE setProgrammingLanguages NOTIFY programmingLanguagesChanged)
    Q_PROPERTY(QString otherInfo READ getOtherInfo WRITE setOtherInfo NOTIFY otherInfoChanged)
    Q_PROPERTY(QString linkVK READ getLinkVK WRITE setLinkVK NOTIFY linkVKChanged)
    Q_PROPERTY(QString linkInstagramm READ getLinkInstagramm WRITE setLinkInstagramm NOTIFY linkInstagrammChanged)
    Q_PROPERTY(QString email READ getEmail WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString birthplace READ getBirthplace WRITE setBirthplace NOTIFY birthplaceChanged)
    Q_PROPERTY(QString familyType READ getFamilyType WRITE setFamilyType NOTIFY familyTypeChanged)
    Q_PROPERTY(QString languages READ getLanguages WRITE setLanguages NOTIFY languagesChanged)
    Q_PROPERTY(QString clothesSizeStart READ getClothesSizeStart WRITE setClothesSizeStart NOTIFY clothesSizeStartChanged)
    Q_PROPERTY(QString clothesSizePersonal READ getClothesSizePersonal WRITE setClothesSizePersonal NOTIFY clothesSizePersonalChanged)
    Q_PROPERTY(QString sizeShoes READ getSizeShoes WRITE setSizeShoes NOTIFY sizeShoesChanged)
    Q_PROPERTY(QString hatSize READ getHatSize WRITE setHatSize NOTIFY hatSizeChanged)

public:
    explicit AddirionalInfo(QObject *parent = nullptr);
    AddirionalInfo(int _idHuman, Rota* _rota, Squad* _squad, Rank* _rank, Summon* _summon, QString _religion, QString _nationality, QString _marital_status, QDate _departure_date,
    QDate _soldier_date, QString _personal_number, QString _overseas_trips, QString _software, QString _programming_language, QString _other_info, QString _link_vk, QString _link_inst,
    QString _email, QString _birtplace, QString _family_type, QString _languages, QString _clothes_size_start, QString _clothes_size_personal, QString _size_shoes, QString _hat_size) :
        idHuman(_idHuman), rota(_rota), squad(_squad), rank(_rank), summon(_summon), religion(_religion), nationality(_nationality), maritalStatus(_marital_status), departureDate(_departure_date),
        soldierDate(_soldier_date), personalNumber(_personal_number), overseasTrips(_overseas_trips), software(_software), programmingLanguages(_programming_language), otherInfo(_other_info),
        linkVK(_link_vk), linkInstagramm(_link_inst), email(_email), birthplace(_birtplace), familyType(_family_type),
        languages(_languages), clothesSizeStart(_clothes_size_start), clothesSizePersonal(_clothes_size_personal), sizeShoes(_size_shoes), hatSize(_hat_size) {}

    int getIdHuman() const;
    void setIdHuman(int value);

    Rota* getRota() const;
    void setRota(Rota* value);

    Squad* getSquad() const;
    void setSquad(Squad* value);

    Rank* getRank() const;
    void setRank(Rank* value);

    Summon* getSummon() const;
    void setSummon(Summon* value);

    QString getReligion() const;
    void setReligion(const QString &value);

    QString getNationality() const;
    void setNationality(const QString &value);

    QString getMaritalStatus() const;
    void setMaritalStatus(const QString &value);

    QString getMilitaryDepartament() const;
    void setMilitaryDepartament(const QString &value);

    QDate getDepartureDate() const;
    void setDepartureDate(const QDate &value);

    QDate getSoldierDate() const;
    void setSoldierDate(const QDate &value);

    QString getPersonalNumber() const;
    void setPersonalNumber(const QString &value);

    QString getOverseasTrips() const;
    void setOverseasTrips(const QString &value);

    QString getSoftware() const;
    void setSoftware(const QString &value);

    QString getProgrammingLanguages() const;
    void setProgrammingLanguages(const QString &value);

    QString getOtherInfo() const;
    void setOtherInfo(const QString &value);

    QString getLinkVK() const;
    void setLinkVK(const QString &value);

    QString getLinkInstagramm() const;
    void setLinkInstagramm(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getBirthplace() const;
    void setBirthplace(const QString &value);

    QString getFamilyType() const;
    void setFamilyType(const QString &value);

    QString getLanguages() const;
    void setLanguages(const QString &value);

    QString getClothesSizeStart() const;
    void setClothesSizeStart(const QString &value);

    QString getClothesSizePersonal() const;
    void setClothesSizePersonal(const QString &value);

    QString getSizeShoes() const;
    void setSizeShoes(const QString &value);

    QString getHatSize() const;
    void setHatSize(const QString &value);

    void Print();

    QVector<Document *> getDocuments() const;
    void setDocuments(const QVector<Document *> &value);

    QVector<Education *> getEducations() const;
    void setEducations(const QVector<Education *> &value);

    QVector<Practice *> getPractices() const;
    void setPractices(const QVector<Practice *> &value);

    QVector<ScientificWork *> getScientificWorks() const;
    void setScientificWorks(const QVector<ScientificWork *> &value);

private:
    int idHuman;
    Rota* rota;
    Squad* squad;
    Rank* rank;
    Summon* summon;
    QString religion;
    QString nationality;
    QString maritalStatus;
    QString militaryDepartament;
    QDate departureDate;
    QDate soldierDate;
    QString personalNumber;
    QString overseasTrips;
    QString software;
    QString programmingLanguages;
    QString otherInfo;
    QString linkVK;
    QString linkInstagramm;
    QString email;
    QString birthplace;
    QString familyType;
    QString languages;
    QString clothesSizeStart;
    QString clothesSizePersonal;
    QString sizeShoes;
    QString hatSize;

    QVector<Document*> documents;
    QVector<Education*> educations;
    QVector<Practice*> practices;
    QVector<ScientificWork*> scientificWorks;

signals:
    void idHumanChanged();
    void rotaChanged();
    void squadChanged();
    void rankChanged();
    void summonChanged();
    void religionChanged();
    void nationalityChanged();
    void maritalStatusChanged();
    void militaryDepartamentChanged();
    void departureDateChanged();
    void soldierDateChanged();
    void personalNumberChanged();
    void overseasTripsChanged();
    void softwareChanged();
    void programmingLanguagesChanged();
    void otherInfoChanged();
    void linkVKChanged();
    void linkInstagrammChanged();
    void emailChanged();
    void birthplaceChanged();
    void familyTypeChanged();
    void languagesChanged();
    void clothesSizeStartChanged();
    void clothesSizePersonalChanged();
    void sizeShoesChanged();
    void hatSizeChanged();

    void documentsChanged();
    void educationsChanged();
    void practicesChanged();
    void scientificWorksChanged();
};

#endif // ADDIRIONALINFO_H
