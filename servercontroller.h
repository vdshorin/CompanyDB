#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H
#define svalue(a) query.value(a).toString()
#define ivalue(a) query.value(a).toInt()
#define tostr(a) QString::number(a)

#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include "instruments.h"
#include "DB/Tables/human.h"


class ServerController
{
private:
    QSqlDatabase db;
    static ServerController* instance;
    bool startServer();

    //-------------ВАЖНЫЕ МЕТОДЫ-------------------
    int getLastId(QString table, QString column="id", QString where="");
    int Insert(QString table, QVector<QString> namesRow, QVector<QString> values);
    int Delete(QString table, QVector<QString> namesRow, QVector<QString> values);
    int Delete(QString table, QString where);
    int Delete(QString table, int id);
    int Update(QString table, QVector<QString> namesRow, QVector<QString> values, int id);
    int Update(QString table, QVector<QString> namesRow, QVector<QString> values, QString where);
public:
    ServerController();
    ///Паттерн синглтон
    static ServerController * getInstance();

    //-----------------Рота------------------------ +
    Rota* GetRota(int idRota);
    int AddRota(Rota* rota);
    int RemoveRota(Rota* rota);
    int RemoveRota(int id);
    int UpdateRota(Rota* rota);

    //-----------------Взвод------------------------ +
    Squad* GetSquad(int idSquad);
    int AddSquad(Squad* squad);
    int RemoveSquad(Squad* squad);
    int RemoveSquad(int id);
    int UpdateSquad(Squad* squad);

    //-----------------Звание------------------------ +
    Rank* GetRank(int idRank);
    int AddRank(Rank* rank);
    int RemoveRank(Rank* rank);
    int RemoveRank(int id);
    int UpdateRank(Rank* rank);

    //-----------------Призыв------------------------ +
    Summon* GetSummon(int idSummon);
    int AddSummon(Summon* summon);
    int RemoveSummon(Summon* summon);
    int RemoveSummon(int id);
    int UpdateSummon(Summon* summon);

    //-----------------Образование------------------------ +
    EducationType* GetEducationType(int idEducationType);
    QVector<EducationType*> GetAllEducationTypes();
    int AddEducationType(EducationType* educationType);
    int RemoveEducationType(EducationType* educationType);
    int RemoveEducationType(int id);
    int UpdateEducationType(EducationType* educationType);

    Education* GetEducation(int idEducation);
    QVector<Education*> GetEducations(int idHuman);
    int AddEducation(Education* education, int idHuman);
    int RemoveEducation(Education* education);
    int RemoveEducation(int id);
    int UpdateEducation(Education* education);

    //-----------------Человек------------------------ +
    Human* GetHuman(int idHuman);
    int AddHuman(Human* human);
    int RemoveHuman(Human* human);
    int UpdateHuman(Human* human);
    QVector<Human*> GetAllHumans();
    QVector<Human*> GetFamily(int idHuman);
    int AddFamily(Human* family, int idHuman);
    int RemoveFamily(Human* family, int idHuman);
    int UpdateFamily(Human* family, int idHuman);

    //-----------------Документы------------------------ +
    DocumentType* GetDocumentType(int idDocumentType);
    int AddDocumentType(DocumentType* documentType);
    int RemoveDocumentType(DocumentType* documentType);
    int RemoveDocumentType(int id);
    int UpdateDocumentType(DocumentType* documentType);

    QVector<DocumentType*> GetAllDocumentTypes();
    Document* GetDocument(int idDocument);
    int AddDocument(Document* document, int idHuman);
    int RemoveDocument(Document* document);
    int RemoveDocument(int id);
    int UpdateDocument(Document* document);
    QVector<Document*> GetDocuments(int idHuman);

    //-----------------Practice------------------------ +
    Practice* GetPractice(int idPractice);
    int AddPractice(Practice* practice, int idHuman);
    int RemovePractice(Practice* practice);
    int RemovePractice(int id);
    int UpdatePractice(Practice* practice);
    QVector<Practice*> GetPractices(int idHuman);

    //-----------------Работа------------------------ +
    WorkplaceType* GetWorkplaceType(int idWorkplaceType);
    int AddWorkplaceType(WorkplaceType* workplaceType);
    int RemoveWorkplaceType(WorkplaceType* workplaceType);
    int RemoveWorkplaceType(int id);
    int UpdateWorkplaceType(WorkplaceType* workplaceType);
    QVector<WorkplaceType*> GetAllWorkplaceTypes();

    Workplace* GetWorkplace(int idWorkplace);
    int AddWorkplace(Workplace* workplace, int idHuman);
    int RemoveWorkplace(Workplace* workplace);
    int RemoveWorkplace(int id);
    int UpdateWorkplace(Workplace* workplace);
    QVector<Workplace*> GetWorkplaces(int idHuman);

    //-----------------Адресс------------------------ +
    Address* GetAddress(int idAddress);
    int AddAddress(Address* address, int idHuman);
    int RemoveAddress(Address* address, int idHuman);
    int RemoveAddress(int id, int idHuman);
    int UpdateAddress(Address* address, int idHuman);
    QVector<Address*> GeAllAddress(int idHuman);

    //-----------------Статьи------------------------ +
    ScientificWorkType* GetScientificWorkType(int idScientificWorkType);
    int AddScientificWorkType(ScientificWorkType* scientificWorkType);
    int RemoveScientificWorkType(ScientificWorkType* scientificWorkType);
    int RemoveScientificWorkType(int id);
    int UpdateScientificWorkType(ScientificWorkType* scientificWorkType);
    QVector<ScientificWorkType*> GetAllScientificWorkTypes();

    ScientificWork* GetScientificWork(int idScientificWork);
    int AddScientificWork(ScientificWork* scientificWork, int idHuman);
    int RemoveScientificWork(ScientificWork* scientificWork);
    int RemoveScientificWork(int id);
    int UpdateScientificWork(ScientificWork* scientificWork);
    QVector<ScientificWork*> GetScientificWorks(int idHuman);

    //-----------------Куча инфы------------------------ +
    AddirionalInfo* GetAddirionalInfo(int idHuman);
    int AddAddirionalInfo(AddirionalInfo* addirionalInfo);
    int RemoveAddirionalInfo(AddirionalInfo* addirionalInfo);
    int RemoveAddirionalInfo(int id);
    int UpdateAddirionalInfo(AddirionalInfo* addirionalInfo);
};

#endif // SERVERCONTROLLER_H
