#include "addirionalinfo.h"

AddirionalInfo::AddirionalInfo(QObject *parent) : QObject(parent)
{

}

int AddirionalInfo::getIdHuman() const
{
    return idHuman;
}

void AddirionalInfo::setIdHuman(int value)
{
    idHuman = value;
    emit idHumanChanged();
}

Rota* AddirionalInfo::getRota() const
{
    return rota;
}

void AddirionalInfo::setRota(Rota* value)
{
    rota = value;
    emit rotaChanged();
}

Squad *AddirionalInfo::getSquad() const
{
    return squad;
}

void AddirionalInfo::setSquad(Squad * value)
{
    squad = value;
    emit squadChanged();
}

Rank* AddirionalInfo::getRank() const
{
    return rank;
}

void AddirionalInfo::setRank(Rank* value)
{
    rank = value;
    emit rankChanged();
}

Summon* AddirionalInfo::getSummon() const
{
    return summon;
}

void AddirionalInfo::setSummon(Summon* value)
{
    summon = value;
    emit summonChanged();
}

QString AddirionalInfo::getReligion() const
{
    return religion;
}

void AddirionalInfo::setReligion(const QString &value)
{
    religion = value;
    emit religionChanged();
}

QString AddirionalInfo::getNationality() const
{
    return nationality;
}

void AddirionalInfo::setNationality(const QString &value)
{
    nationality = value;
    emit nationalityChanged();
}

QString AddirionalInfo::getMaritalStatus() const
{
    return maritalStatus;
}

void AddirionalInfo::setMaritalStatus(const QString &value)
{
    maritalStatus = value;
    emit maritalStatusChanged();
}

QString AddirionalInfo::getMilitaryDepartament() const
{
    return militaryDepartament;
}

void AddirionalInfo::setMilitaryDepartament(const QString &value)
{
    militaryDepartament = value;
    emit militaryDepartamentChanged();
}

QDate AddirionalInfo::getDepartureDate() const
{
    return departureDate;
}

void AddirionalInfo::setDepartureDate(const QDate &value)
{
    departureDate = value;
    emit departureDateChanged();
}

QDate AddirionalInfo::getSoldierDate() const
{
    return soldierDate;
}

void AddirionalInfo::setSoldierDate(const QDate &value)
{
    soldierDate = value;
    emit soldierDateChanged();
}

QString AddirionalInfo::getPersonalNumber() const
{
    return personalNumber;
}

void AddirionalInfo::setPersonalNumber(const QString &value)
{
    personalNumber = value;
    emit personalNumberChanged();
}

QString AddirionalInfo::getOverseasTrips() const
{
    return overseasTrips;
}

void AddirionalInfo::setOverseasTrips(const QString &value)
{
    overseasTrips = value;
    emit overseasTripsChanged();
}

QString AddirionalInfo::getSoftware() const
{
    return software;
}

void AddirionalInfo::setSoftware(const QString &value)
{
    software = value;
    emit softwareChanged();
}

QString AddirionalInfo::getProgrammingLanguages() const
{
    return programmingLanguages;
}

void AddirionalInfo::setProgrammingLanguages(const QString &value)
{
    programmingLanguages = value;
    emit programmingLanguagesChanged();
}

QString AddirionalInfo::getOtherInfo() const
{
    return otherInfo;
}

void AddirionalInfo::setOtherInfo(const QString &value)
{
    otherInfo = value;
    emit otherInfoChanged();
}

QString AddirionalInfo::getLinkVK() const
{
    return linkVK;
}

void AddirionalInfo::setLinkVK(const QString &value)
{
    linkVK = value;
    emit linkVKChanged();
}

QString AddirionalInfo::getLinkInstagramm() const
{
    return linkInstagramm;
}

void AddirionalInfo::setLinkInstagramm(const QString &value)
{
    linkInstagramm = value;
    emit linkInstagrammChanged();
}

QString AddirionalInfo::getEmail() const
{
    return email;
}

void AddirionalInfo::setEmail(const QString &value)
{
    email = value;
    emit emailChanged();
}

QString AddirionalInfo::getBirthplace() const
{
    return birthplace;
}

void AddirionalInfo::setBirthplace(const QString &value)
{
    birthplace = value;
    emit birthplaceChanged();
}

QString AddirionalInfo::getFamilyType() const
{
    return familyType;
}

void AddirionalInfo::setFamilyType(const QString &value)
{
    familyType = value;
    emit familyTypeChanged();
}

QString AddirionalInfo::getLanguages() const
{
    return languages;
}

void AddirionalInfo::setLanguages(const QString &value)
{
    languages = value;
    emit languagesChanged();
}

QString AddirionalInfo::getClothesSizeStart() const
{
    return clothesSizeStart;
}

void AddirionalInfo::setClothesSizeStart(const QString &value)
{
    clothesSizeStart = value;
    emit clothesSizeStartChanged();
}

QString AddirionalInfo::getClothesSizePersonal() const
{
    return clothesSizePersonal;
}

void AddirionalInfo::setClothesSizePersonal(const QString &value)
{
    clothesSizePersonal = value;
    emit clothesSizePersonalChanged();
}

QString AddirionalInfo::getSizeShoes() const
{
    return sizeShoes;
}

void AddirionalInfo::setSizeShoes(const QString &value)
{
    sizeShoes = value;
    emit sizeShoesChanged();
}

QString AddirionalInfo::getHatSize() const
{
    return hatSize;
}

void AddirionalInfo::setHatSize(const QString &value)
{
    hatSize = value;
    emit hatSizeChanged();
}

void AddirionalInfo::Print()
{
    qDebug() <<"int idHuman: " << getIdHuman();
    getRota()->Print();
    getSquad()->Print();
    getRank()->Print();
    getSummon()->Print();
    qDebug() <<"QString religion: " << getReligion();
    qDebug() <<"QString nationality: " << getNationality();
    qDebug() <<"QString maritalStatus: " << getMaritalStatus();
    qDebug() <<"QString militaryDepartament: " << getMilitaryDepartament();
    qDebug() <<"QDate departureDate: " << getDepartureDate().toString();
    qDebug() <<"QDate soldierDate: " << getSoldierDate().toString();
    qDebug() <<"QString personalNumber: " << getPersonalNumber();
    qDebug() <<"QString overseasTrips: " << getOverseasTrips();
    qDebug() <<"QString software: " << getSoftware();
    qDebug() <<"QString programmingLanguages: " << getProgrammingLanguages();
    qDebug() <<"QString otherInfo: " << getOtherInfo();
    qDebug() <<"QString linkVK: " << getLinkVK();
    qDebug() <<"QString linkInstagramm: " << getLinkInstagramm();
    qDebug() <<"QString email: " << getEmail();
    qDebug() <<"QString birthplace: " << getBirthplace();
    qDebug() <<"QString familyType: " << getFamilyType();
    qDebug() <<"QString languages: " << getLanguages();
    qDebug() <<"QString clothesSizeStart: " << getClothesSizeStart();
    qDebug() <<"QString clothesSizePersonal: " << getClothesSizePersonal();
    qDebug() <<"QString sizeShoes: " << getSizeShoes();
    qDebug() <<"QString hatSize: " << getHatSize();
}

QVector<Document *> AddirionalInfo::getDocuments() const
{
    return documents;
}

void AddirionalInfo::setDocuments(const QVector<Document *> &value)
{
    documents = value;
    emit documentsChanged();
}

QVector<Education *> AddirionalInfo::getEducations() const
{
    return educations;
}

void AddirionalInfo::setEducations(const QVector<Education *> &value)
{
    educations = value;
    emit educationsChanged();
}

QVector<Practice *> AddirionalInfo::getPractices() const
{
    return practices;
}

void AddirionalInfo::setPractices(const QVector<Practice *> &value)
{
    practices = value;
    emit practicesChanged();
}

QVector<ScientificWork *> AddirionalInfo::getScientificWorks() const
{
    return scientificWorks;
}

void AddirionalInfo::setScientificWorks(const QVector<ScientificWork *> &value)
{
    scientificWorks = value;
    emit scientificWorksChanged();
}
