#include "servercontroller.h"

ServerController* ServerController::instance = nullptr;

ServerController::ServerController()
{
    startServer();
}

bool ServerController::startServer()
{
    QVector<QString> paths({
                               "..\\SuperRotaDataBase\\SuperDataBaseRota ",
                               "C:\\Users\\SplavOP\\Desktop\\fyv\\Projects\\SuperRotaDataBase\\SuperDataBaseRota",
                               "F:\\maksim\\SuperRotaDataBase\\SuperDataBaseRota",
                               "C:/Users/Administrator/Desktop/SuperDataBaseRota",
                               "C:/Users/test/Desktop/tula_hack/git/SuperRotaDataBase/SuperDataBaseRota",
                               "C:\\Users\\rota\\Documents\\GitHub\\SuperRotaDataBase\\SuperDataBaseRota",
                               "C:\\Users\\Rota5\\My info\\SuperRotaDataBase\\SuperDataBaseRota"
                           });

    db = QSqlDatabase::addDatabase("QSQLITE");

    foreach(QString p, paths){
        if(QFile::exists(p)){
            db.setDatabaseName(p);
        }
    }

    if(db.databaseName()=="")
        qFatal("ERROR: Файл базы данных не найден");

    if(db.open()){
        return true;
    } else {
        qFatal("ERROR: Соединение с базой данных не установлено");
        return false;
    }
}

ServerController *ServerController::getInstance()
{
    if(!instance)
        instance = new ServerController();
    return instance;
}

int ServerController::getLastId(QString table, QString column, QString where)
{
    auto str = QString("SELECT %0 FROM %1 %3 ORDER BY %0 DESC LIMIT 1").arg(column).arg(table).arg(where);
    QSqlQuery query(str);
    query.first();
    return ivalue(0);
}

int ServerController::Insert(QString table, QVector<QString> namesRow, QVector<QString> values)
{
    if(namesRow.length()!=values.length())
    {
        qFatal("ERROR: количество столбцов не соответсвует количеству значений");
        return -1;
    }

    QString nameRow;
    for(int i = 0; i < namesRow.count(); i++){
        nameRow += namesRow[i];
        if(i != namesRow.count() - 1)
            nameRow += ", ";
    }

    QString val;
    for(int i = 0; i < values.count(); i++){
        val += "'"+values[i]+"'";
        if(i != values.count() - 1)
            val += ", ";
    }

    auto str = QString("INSERT INTO %0 (%1) VALUES (%2);")
            .arg(table)
            .arg(nameRow)
            .arg(val);

    QSqlQuery query(str);
    //query.exec();

    return 0;
}

int ServerController::Delete(QString table, QVector<QString> namesRow, QVector<QString> values)
{
    if(namesRow.length()!=values.length())
    {
        qFatal("ERROR: количество столбцов не соответсвует количеству значений");
        return -1;
    }

    QString where;
    for(int i = 0; i < namesRow.count(); i++){
        where += namesRow[i];
        where +=" = ";
        where += values[i];
        if(i != namesRow.count() - 1)
            where += " AND ";
    }

    auto str = QString("DELETE FROM %0 WHERE %1;")
            .arg(table)
            .arg(where);

    QSqlQuery query(str);
    //query.exec();

    return 0;
}

int ServerController::Delete(QString table, QString where)
{
    auto str = QString("DELETE FROM %0 WHERE %1;")
            .arg(table)
            .arg(where);

    QSqlQuery query(str);
    //query.exec();

    return 0;
}

int ServerController::Delete(QString table, int id)
{
    if(id<=0)
        qFatal("ERROR: Неверное значение id");
    return Delete(table, QString("id = %0").arg(id));
}

int ServerController::Update(QString table, QVector<QString> namesRow, QVector<QString> values, int id)
{
    return Update(table, namesRow, values, QString("id = %0").arg(id));
}

int ServerController::Update(QString table, QVector<QString> namesRow, QVector<QString> values, QString where)
{
    if(namesRow.length()!=values.length())
    {
        qFatal("ERROR: количество столбцов не соответсвует количеству значений");
        return -1;
    }

    QString nameRow;
    for(int i = 0; i < namesRow.count(); i++){
        nameRow += namesRow[i];
        nameRow += " = ";
        nameRow += "'"+values[i]+"'";
        if(i != namesRow.count() - 1)
            nameRow += ", ";
    }

    auto str = QString("UPDATE %0 SET %1 WHERE %2;")
            .arg(table)
            .arg(nameRow)
            .arg(where);

    QSqlQuery query(str);
    //query.exec();

    return 0;
}

Rota *ServerController::GetRota(int idRota)
{
    auto str = QString("SELECT id, value FROM rota WHERE id = %0;").arg(idRota);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;
    Rota* rota= new Rota(idRota, ivalue(1));
    return rota;
}

int ServerController::AddRota(Rota *rota)
{
    Insert("rota", {"value"},{QString::number(rota->getValue())});

    int id = getLastId("rota");
    rota->setId(id);

    return 0;
}

int ServerController::RemoveRota(Rota *rota)
{
    return Delete("rota",rota->getId());
}

int ServerController::RemoveRota(int id)
{
    return Delete("rota",id);
}

int ServerController::UpdateRota(Rota *rota)
{
    return Update("rota", {"value"},{QString::number(rota->getValue())}, rota->getId());
}

Squad *ServerController::GetSquad(int idSquad)
{
    auto str = QString("SELECT id, value FROM squad WHERE id = %0;").arg(idSquad);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;
    Squad* squad= new Squad(idSquad, ivalue(1));
    return squad;
}

int ServerController::AddSquad(Squad *squad)
{
    Insert("squad", {"value"},{QString::number(squad->getValue())});

    int id = getLastId("squad");
    squad->setId(id);

    return 0;
}

int ServerController::RemoveSquad(Squad *squad)
{
    return Delete("squad",squad->getId());
}

int ServerController::RemoveSquad(int id)
{
    return Delete("squad",id);
}

int ServerController::UpdateSquad(Squad *squad)
{
    return Update("squad", {"value"},{QString::number(squad->getValue())}, squad->getId());
}

Rank *ServerController::GetRank(int idRank)
{
    auto str = QString("SELECT id, value FROM rank WHERE id = %0;").arg(idRank);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;
    Rank* rank= new Rank(idRank, svalue(1));
    return rank;
}

int ServerController::AddRank(Rank *rank)
{
    Insert("rank", {"value"},{rank->getValue()});

    int id = getLastId("rank");
    rank->setId(id);

    return 0;
}

int ServerController::RemoveRank(Rank *rank)
{
    return Delete("rank",rank->getId());
}

int ServerController::RemoveRank(int id)
{
    return Delete("rank",id);
}

int ServerController::UpdateRank(Rank *rank)
{
    return Update("rank", {"value"},{rank->getValue()}, rank->getId());
}

Summon *ServerController::GetSummon(int idSummon)
{
    auto str = QString("SELECT id, value FROM summon WHERE id = %0;").arg(idSummon);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;
    Summon* summon= new Summon(idSummon, svalue(1));
    return summon;
}

int ServerController::AddSummon(Summon *summon)
{
    Insert("summon", {"value"},{summon->getValue()});

    int id = getLastId("summon");
    summon->setId(id);

    return 0;
}

int ServerController::RemoveSummon(Summon *summon)
{
    return Delete("summon",summon->getId());
}

int ServerController::RemoveSummon(int id)
{
    return Delete("summon",id);
}

int ServerController::UpdateSummon(Summon *summon)
{
    return Update("rank", {"value"},{summon->getValue()}, summon->getId());
}

DocumentType *ServerController::GetDocumentType(int idDocumentType)
{
    auto str = QString("SELECT id, value FROM document_type WHERE id = %0;").arg(idDocumentType);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;
    DocumentType* documentType= new DocumentType(idDocumentType, svalue(1));
    return documentType;
}

int ServerController::AddDocumentType(DocumentType *documentType)
{
    Insert("document_type", {"value"},{documentType->getValue()});

    int id = getLastId("document_type");
    documentType->setId(id);

    return 0;
}

int ServerController::RemoveDocumentType(DocumentType *documentType)
{
    return Delete("document_type",documentType->getId());
}

int ServerController::RemoveDocumentType(int id)
{
    return Delete("document_type",id);
}

int ServerController::UpdateDocumentType(DocumentType *documentType)
{
    return Update("document_type", {"value"},{documentType->getValue()}, documentType->getId());
}

QVector<DocumentType *> ServerController::GetAllDocumentTypes()
{
    auto str = QString("SELECT id FROM document_type;");
    QSqlQuery query(str);

    QVector<DocumentType*> documentTypes;

    while(query.next())
    {
        int document_id = ivalue(0);
        DocumentType* documentType=GetDocumentType(document_id);
        documentTypes.append(documentType);
    }

    return documentTypes;
}

Document *ServerController::GetDocument(int idDocument)
{
    auto str = QString("SELECT id, series, number, issue_place, issue_date, additional_number, document_type_id, additional_info_human_id  "
                    "FROM document WHERE id = %0;").arg(idDocument);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;

    QString series = svalue(1);
    QString number = svalue(2);
    QString issue_place = svalue(3);
    QDate issue_date = Instruments::getDate(svalue(4));
    QString additional_number = svalue(5);
    int document_type_id = ivalue(6);
    DocumentType* documentType = GetDocumentType(document_type_id);
    int additional_info_human_id = ivalue(7);

    Document* document= new Document(idDocument, series, number, issue_place, issue_date,additional_number,documentType);
    return document;
}

int ServerController::AddDocument(Document *document, int idHuman)
{
    Insert("document", {"series", "number", "issue_place", "issue_date", "additional_number", "document_type_id", "additional_info_human_id"},
           {document->getSeries(), document->getNumber(), document->getIssuePlace(), document->getIssueDate().toString(),
            document->getAdditionalNumber(), QString::number(document->getDocumentType()->getId()), QString::number(idHuman)});

    int id = getLastId("document");
    document->setId(id);

    return 0;
}

int ServerController::RemoveDocument(Document *document)
{
    return Delete("document",document->getId());
}

int ServerController::RemoveDocument(int id)
{
    return Delete("document",id);
}

int ServerController::UpdateDocument(Document *document)
{
    return Update("document", {"series", "number", "issue_place", "issue_date", "additional_number", "document_type_id"},
                  {document->getSeries(), document->getNumber(), document->getIssuePlace(), document->getIssueDate().toString(),
                   document->getAdditionalNumber(), QString::number(document->getDocumentType()->getId())}, document->getId());
}

QVector<Document *> ServerController::GetDocuments(int idHuman)
{
    auto str = QString("SELECT id FROM document WHERE additional_info_human_id = %0;").arg(idHuman);
    QSqlQuery query(str);

    QVector<Document*> documentc;

    while(query.next())
    {
        int education_id = ivalue(0);
        Document* document=GetDocument(education_id);
        documentc.append(document);
    }

    return documentc;
}

Practice *ServerController::GetPractice(int idPractice)
{
    auto str = QString("SELECT id, type, company_name, date_start,date_end, additional_info_human_id  "
                    "FROM practice WHERE id = %0;").arg(idPractice);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;

    QString type = svalue(1);
    QString company_name = svalue(2);
    QDate date_start = Instruments::getDate(svalue(3));
    QDate date_end = Instruments::getDate(svalue(4));
    int additional_info_human_id = ivalue(7);

    Practice* practice= new Practice(idPractice, type, company_name, date_start, date_end);
    return practice;
}

int ServerController::AddPractice(Practice *practice, int idHuman)
{
    Insert("practice", {"type", "company_name", "date_start", "date_end", "additional_info_human_id"},
           {practice->getType(), practice->getCompanyName(), practice->getDateStart().toString(), practice->getDateEnd().toString(), QString::number(idHuman)});

    int id = getLastId("practice");
    practice->setId(id);

    return 0;
}

int ServerController::RemovePractice(Practice *practice)
{
    return Delete("practice",practice->getId());
}

int ServerController::RemovePractice(int id)
{
    return Delete("practice",id);
}

int ServerController::UpdatePractice(Practice *practice)
{
    return Update("practice", {"type", "company_name", "date_start", "date_end"},
                  {practice->getType(), practice->getCompanyName(), practice->getDateStart().toString(), practice->getDateEnd().toString()}, practice->getId());
}

QVector<Practice *> ServerController::GetPractices(int idHuman)
{
    auto str = QString("SELECT id FROM practice WHERE additional_info_human_id = %0;").arg(idHuman);
    QSqlQuery query(str);

    QVector<Practice*> educations;

    while(query.next())
    {
        int practice_id = ivalue(0);
        Practice* practice=GetPractice(practice_id);
        educations.append(practice);
    }

    return educations;
}

WorkplaceType *ServerController::GetWorkplaceType(int idWorkplaceType)
{
    auto str = QString("SELECT id, value FROM workplace_type WHERE id = %0;").arg(idWorkplaceType);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;
    WorkplaceType* workplaceType= new WorkplaceType(idWorkplaceType, svalue(1));
    return workplaceType;
}

int ServerController::AddWorkplaceType(WorkplaceType *workplaceType)
{
    Insert("workplace_type", {"value"},{workplaceType->getValue()});

    int id = getLastId("workplace_type");
    workplaceType->setId(id);

    return 0;
}

int ServerController::RemoveWorkplaceType(WorkplaceType *workplaceType)
{
    return Delete("workplace_type", workplaceType->getId());
}

int ServerController::RemoveWorkplaceType(int id)
{
    return Delete("workplace_type", id);
}

int ServerController::UpdateWorkplaceType(WorkplaceType *workplaceType)
{
    return Update("workplace_type", {"value"},{workplaceType->getValue()}, workplaceType->getId());
}

QVector<WorkplaceType *> ServerController::GetAllWorkplaceTypes()
{
    auto str = QString("SELECT id FROM workplace_type;");
    QSqlQuery query(str);

    QVector<WorkplaceType*> workplaceTypes;

    while(query.next())
    {
        int workplaceType_id = ivalue(0);
        WorkplaceType* document=GetWorkplaceType(workplaceType_id);
        workplaceTypes.append(document);
    }

    return workplaceTypes;
}

Workplace *ServerController::GetWorkplace(int idWorkplace)
{
    auto str = QString("SELECT id, name, workplace_type_id, position, activity, date_start, date_end, human_id "
                    "FROM workplace WHERE id = %0;").arg(idWorkplace);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;

    QString name = svalue(1);
    int workplace_type_id = ivalue(2);
    WorkplaceType* workplaceType = GetWorkplaceType(workplace_type_id);
    QString position = svalue(3);
    QString activity = svalue(4);
    QDate dateStart = Instruments::getDate(svalue(5));
    QDate dateEnd = Instruments::getDate(svalue(6));
    int human_id = ivalue(7);

    Workplace* workplace= new Workplace(idWorkplace, name, workplaceType, position, activity,dateStart,dateEnd);
    return workplace;
}

int ServerController::AddWorkplace(Workplace *workplace, int idHuman)
{
    Insert("workplace", {"name", "workplace_type_id", "position", "activity", "date_start", "date_end", "human_id"},
           {workplace->getName(), QString::number(workplace->getWorkplaceType()->getId()), workplace->getPosition(),
            workplace->getActivity(), workplace->getDateStart().toString(), workplace->getDateEnd().toString(), QString::number(idHuman)});

    int id = getLastId("workplace");
    workplace->setId(id);

    return 0;
}

int ServerController::RemoveWorkplace(Workplace *workplace)
{
    return Delete("workplace", workplace->getId());
}

int ServerController::RemoveWorkplace(int id)
{
    return Delete("workplace", id);
}

int ServerController::UpdateWorkplace(Workplace *workplace)
{
    return Update("workplace", {"name", "workplace_type_id", "position", "activity", "date_start", "date_end"},
                  {workplace->getName(), QString::number(workplace->getWorkplaceType()->getId()), workplace->getPosition(),
                   workplace->getActivity(), workplace->getDateStart().toString(), workplace->getDateEnd().toString()}, workplace->getId());
}

QVector<Workplace *> ServerController::GetWorkplaces(int idHuman)
{
    auto str = QString("SELECT id FROM workplace WHERE human_id = %0;").arg(idHuman);
    QSqlQuery query(str);

    QVector<Workplace*> workplaces;

    while(query.next())
    {
        int workplace_id = ivalue(0);
        Workplace* workplace=GetWorkplace(workplace_id);
        workplaces.append(workplace);
    }

    return workplaces;
}

Address *ServerController::GetAddress(int idAddress)
{
    auto str = QString("SELECT id, region, city, street, building, flat "
                    "FROM address WHERE id = %0;").arg(idAddress);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;

    QString region = svalue(1);
    QString city = svalue(2);
    QString street = svalue(3);
    QString building = svalue(4);
    QString flat = svalue(5);

    Address* address= new Address(idAddress, region, city, street, building, flat);
    return address;
}

int ServerController::AddAddress(Address *address, int idHuman)
{
    Insert("address", {"region", "city", "street", "building", "flat"},
           {address->getRegion(), address->getSity(), address->getStreet(), address->getBuilding(), address->getFlat()});
    int idAddress=getLastId("address","id");

    address->setId(idAddress);

    return Insert("human_has_address", {"human_id", "address_id", "type"},
                  {QString::number(idHuman), QString::number(idAddress), address->getType()});
}

int ServerController::RemoveAddress(Address *address, int idHuman)
{
    return RemoveAddress(address->getId(),idHuman);
}

int ServerController::RemoveAddress(int id, int idHuman)
{
    Delete("address", id);
    return Delete("human_has_address", {"human_id", "address_id"}, { QString::number(idHuman), QString::number(id)});
}

int ServerController::UpdateAddress(Address *address, int idHuman)
{
    Update("address", {"region", "city", "street", "building", "flat"},
           {address->getRegion(), address->getSity(), address->getStreet(), address->getBuilding(), address->getFlat()}, address->getId());

    return Update("human_has_address", {"type"},
                  {address->getType()},QString("human_id = %0 AND address_id = %1").arg(idHuman).arg(address->getId()));
}

QVector<Address *> ServerController::GeAllAddress(int idHuman)
{
    auto str = QString("SELECT address_id, type FROM address a JOIN human_has_address ha ON a.id = ha.human_id WHERE a.id=%0;").arg(idHuman);
    QSqlQuery query(str);

    QVector<Address*> addresss;

    while(query.next())
    {
        int address_id = ivalue(0);
        Address* address = GetAddress(address_id);
        address->setType(svalue(1));
        addresss.append(address);
    }

    return addresss;
}

ScientificWorkType *ServerController::GetScientificWorkType(int idScientificWorkType)
{
    auto str = QString("SELECT id, value FROM scientific_work_type WHERE id = %0;").arg(idScientificWorkType);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;
    ScientificWorkType* workplaceType= new ScientificWorkType(idScientificWorkType, svalue(1));
    return workplaceType;
}

int ServerController::AddScientificWorkType(ScientificWorkType *scientificWorkType)
{
    Insert("scientific_work_type", {"value"},{scientificWorkType->getValue()});

    int id = getLastId("scientific_work_type");
    scientificWorkType->setId(id);

    return 0;
}

int ServerController::RemoveScientificWorkType(ScientificWorkType *scientificWorkType)
{
    return RemoveScientificWorkType(scientificWorkType->getId());
}

int ServerController::RemoveScientificWorkType(int id)
{
    return Delete("scientific_work_type", id);
}

int ServerController::UpdateScientificWorkType(ScientificWorkType *scientificWorkType)
{
    return Update("scientific_work_type", {"value"},{scientificWorkType->getValue()}, scientificWorkType->getId());
}

QVector<ScientificWorkType *> ServerController::GetAllScientificWorkTypes()
{
    auto str = QString("SELECT id FROM scientific_work_type;");
    QSqlQuery query(str);

    QVector<ScientificWorkType*> workplaceTypes;

    while(query.next())
    {
        int scientificWorkType_id = ivalue(0);
        ScientificWorkType* scientificWorkType=GetScientificWorkType(scientificWorkType_id);
        workplaceTypes.append(scientificWorkType);
    }

    return workplaceTypes;
}

ScientificWork *ServerController::GetScientificWork(int idScientificWork)
{
    auto str = QString("SELECT id, information, scientific_work_type_id, additional_info_human_id "
                    "FROM scientific_work WHERE id = %0;").arg(idScientificWork);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;

    QString information = svalue(1);
    int scientific_work_type_id = ivalue(2);
    ScientificWorkType* scientificWorkType = GetScientificWorkType(scientific_work_type_id);
    int additional_info_human_id = ivalue(3);

    ScientificWork* scientificWork= new ScientificWork(idScientificWork, information, scientificWorkType);
    return scientificWork;
}

int ServerController::AddScientificWork(ScientificWork *scientificWork, int idHuman)
{
    Insert("scientific_work", {"information", "scientific_work_type_id", "additional_info_human_id"},
           {scientificWork->getInformation(), QString::number(scientificWork->getScientificWorkType()->getId()), QString::number(idHuman)});

    int id = getLastId("scientific_work");
    scientificWork->setId(id);

    return 0;
}

int ServerController::RemoveScientificWork(ScientificWork *scientificWork)
{
    return RemoveScientificWork(scientificWork->getId());
}

int ServerController::RemoveScientificWork(int id)
{
    return Delete("scientific_work", id);
}

int ServerController::UpdateScientificWork(ScientificWork *scientificWork)
{
    return Update("scientific_work", {"information", "scientific_work_type_id"},
                  {scientificWork->getInformation(), QString::number(scientificWork->getScientificWorkType()->getId())}, scientificWork->getId());
}

QVector<ScientificWork *> ServerController::GetScientificWorks(int idHuman)
{
    auto str = QString("SELECT id FROM scientific_work WHERE additional_info_human_id=%0;").arg(idHuman);
    QSqlQuery query(str);

    QVector<ScientificWork*> scientificWorks;

    while(query.next())
    {
        int scientificWork_id = ivalue(0);
        ScientificWork* scientificWork = GetScientificWork(scientificWork_id);
        scientificWorks.append(scientificWork);
    }

    return scientificWorks;
}

AddirionalInfo *ServerController::GetAddirionalInfo(int idHuman)
{
    auto str = QString("SELECT human_id, rota_id, squad_id, rank_id, summon_id, religion, nationality, marital_status, departure_date, "
"soldier_date, personal_number, overseas_trips, software, programming_language, other_info, link_vk, link_inst, email, birtplace, family_type,"
" languages, clothes_size_start, clothes_size_personal, size_shoes, hat_size "
                    "FROM additional_info WHERE human_id = %0;").arg(idHuman);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;

    int rota_id = ivalue(1);
    Rota* rota = GetRota(rota_id);
    int squad_id = ivalue(2);
    Squad* squad = GetSquad(squad_id);
    int rank_id = ivalue(3);
    Rank* rank = GetRank(rank_id);
    int summon_id = ivalue(4);
    Summon* summon = GetSummon(summon_id);
    QString religion = svalue(5);
    QString nationality = svalue(6);
    QString marital_status = svalue(7);
    QDate departure_date = Instruments::getDate(svalue(8));
    QDate soldier_date = Instruments::getDate(svalue(9));
    QString personal_number = svalue(10);
    QString overseas_trips = svalue(11);
    QString software = svalue(12);
    QString programming_language = svalue(13);
    QString other_info = svalue(14);
    QString link_vk = svalue(15);
    QString link_inst = svalue(16);
    QString email = svalue(17);
    QString birtplace = svalue(18);
    QString family_type = svalue(19);
    QString languages = svalue(20);
    QString clothes_size_start = svalue(21);
    QString clothes_size_personal = svalue(22);
    QString size_shoes = svalue(23);
    QString hat_size = svalue(24);

    AddirionalInfo* addirionalInfo= new AddirionalInfo(idHuman, rota, squad, rank, summon, religion, nationality, marital_status, departure_date,
                                                       soldier_date, personal_number, overseas_trips, software, programming_language, other_info, link_vk, link_inst, email, birtplace, family_type,
                                                       languages, clothes_size_start, clothes_size_personal, size_shoes, hat_size);

    QVector<Document*> documents = GetDocuments(idHuman);
    QVector<Education*> educations = GetEducations(idHuman);
    QVector<Practice*> practices = GetPractices(idHuman);
    QVector<ScientificWork*> scientificWorks = GetScientificWorks(idHuman);

    addirionalInfo->setDocuments(documents);
    addirionalInfo->setEducations(educations);
    addirionalInfo->setPractices(practices);
    addirionalInfo->setScientificWorks(scientificWorks);

    return addirionalInfo;
}

int ServerController::AddAddirionalInfo(AddirionalInfo *ai)
{
    Insert("additional_info", {"human_id", "rota_id", "squad_id", "rank_id", "summon_id", "religion", "nationality", "marital_status", "departure_date",
                               "soldier_date", "personal_number", "overseas_trips", "software", "programming_language", "other_info", "link_vk", "link_inst", "email", "birtplace", "family_type",
                               "languages", "clothes_size_start", "clothes_size_personal", "size_shoes", "hat_size"},
           {QString::number(ai->getIdHuman()), QString::number(ai->getRota()->getId()), QString::number(ai->getSquad()->getId()),  QString::number(ai->getRank()->getId()),
            QString::number(ai->getSummon()->getId()), ai->getReligion(), ai->getNationality(), ai->getMaritalStatus(),ai->getDepartureDate().toString(),
            ai->getSoldierDate().toString(), ai->getPersonalNumber(), ai->getOverseasTrips(), ai->getSoftware(), ai->getProgrammingLanguages(), ai->getOtherInfo(),
            ai->getLinkVK(), ai->getLinkInstagramm(), ai->getEmail(), ai->getBirthplace(), ai->getFamilyType(), ai->getLanguages(),
            ai->getClothesSizeStart(), ai->getClothesSizePersonal(), ai->getSizeShoes(), ai->getHatSize()});

    foreach(auto document, ai->getDocuments())
        AddDocument(document,ai->getIdHuman());

    foreach(auto education, ai->getEducations())
        AddEducation(education,ai->getIdHuman());

    foreach(auto practice, ai->getPractices())
        AddPractice(practice,ai->getIdHuman());

    foreach(auto scientificWork, ai->getScientificWorks())
        AddScientificWork(scientificWork,ai->getIdHuman());
}

int ServerController::RemoveAddirionalInfo(AddirionalInfo *ai)
{
    foreach(auto document, ai->getDocuments())
        RemoveDocument(document);

    foreach(auto education, ai->getEducations())
        RemoveEducation(education);

    foreach(auto practice, ai->getPractices())
        RemovePractice(practice);

    foreach(auto scientificWork, ai->getScientificWorks())
        RemoveScientificWork(scientificWork);

    return RemoveAddirionalInfo(ai->getIdHuman());
}

int ServerController::RemoveAddirionalInfo(int id)
{
    return Delete("additional_info",QString("human_id = %0").arg(id));
}

int ServerController::UpdateAddirionalInfo(AddirionalInfo *ai)
{
    Update("additional_info", {"rota_id", "squad_id", "rank_id", "summon_id", "religion", "nationality", "marital_status", "departure_date",
                               "soldier_date", "personal_number", "overseas_trips", "software", "programming_language", "other_info", "link_vk", "link_inst", "email", "birtplace", "family_type",
                               "languages", "clothes_size_start", "clothes_size_personal", "size_shoes", "hat_size"},
           {QString::number(ai->getRota()->getId()), QString::number(ai->getSquad()->getId()),  QString::number(ai->getRank()->getId()),
            QString::number(ai->getSummon()->getId()), ai->getReligion(), ai->getNationality(), ai->getMaritalStatus(),ai->getDepartureDate().toString(),
            ai->getSoldierDate().toString(), ai->getPersonalNumber(), ai->getOverseasTrips(), ai->getSoftware(), ai->getProgrammingLanguages(), ai->getOtherInfo(),
            ai->getLinkVK(), ai->getLinkInstagramm(), ai->getEmail(), ai->getBirthplace(), ai->getFamilyType(), ai->getLanguages(),
            ai->getClothesSizeStart(), ai->getClothesSizePersonal(), ai->getSizeShoes(), ai->getHatSize()}, QString("human_id = %0").arg(ai->getIdHuman()));

    foreach(auto document, ai->getDocuments())
        UpdateDocument(document);

    foreach(auto education, ai->getEducations())
        UpdateEducation(education);

    foreach(auto practice, ai->getPractices())
        UpdatePractice(practice);

    foreach(auto scientificWork, ai->getScientificWorks())
        UpdateScientificWork(scientificWork);
}

EducationType *ServerController::GetEducationType(int idEducationType)
{
    auto str = QString("SELECT id, value FROM education_type WHERE id = %0;").arg(idEducationType);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;
    EducationType* educationType= new EducationType(idEducationType, svalue(1));
    return educationType;
}

int ServerController::AddEducationType(EducationType *educationType)
{
    Insert("education_type", {"value"},{educationType->getValue()});

    int id = getLastId("education_type");
    educationType->setId(id);

    return 0;
}

int ServerController::RemoveEducationType(EducationType *educationType)
{
    return Delete("education_type",educationType->getId());
}

int ServerController::RemoveEducationType(int id)
{
    return Delete("education_type", id);
}

int ServerController::UpdateEducationType(EducationType *educationType)
{
    return Update("education_type", {"value"},{educationType->getValue()}, educationType->getId());
}

QVector<EducationType *> ServerController::GetAllEducationTypes()
{
    auto str = QString("SELECT id FROM education_type");
    QSqlQuery query(str);

    QVector<EducationType*> educationTypes;

    while(query.next())
    {
        int educationType_id = ivalue(0);
        EducationType* educationType=GetEducationType(educationType_id);
        educationTypes.append(educationType);
    }

    return educationTypes;
}

Education *ServerController::GetEducation(int idEducation)
{
    auto str = QString("SELECT id, education_type_id, specialization, date_graduate, mark,theme, university_name, additional_info_human_id  "
                    "FROM education WHERE id = %0;").arg(idEducation);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;

    int education_type_id = ivalue(1);
    EducationType* educationType = GetEducationType(education_type_id);
    QString specialization = svalue(2);
    QDate date_graduate = Instruments::getDate(svalue(3));
    double mark = query.value(4).toDouble();
    QString theme = svalue(5);
    QString university_name = svalue(6);
    int additional_info_human_id = ivalue(7);

    Education* education= new Education(idEducation, educationType, specialization, date_graduate, mark,theme,university_name);
    return education;
}

int ServerController::AddEducation(Education *education, int idHuman)
{
    Insert("education", {"education_type_id", "specialization", "date_graduate", "mark", "theme", "university_name", "additional_info_human_id"},
           {QString::number(education->getEducationType()->getId()), education->getSpecialization(), education->getDateGraduate().toString(),
            QString::number(education->getMark()), education->getTheme(), education->getUniversityName(), QString::number(idHuman)});

    int id = getLastId("education");
    education->setId(id);

    return 0;
}

int ServerController::RemoveEducation(Education *education)
{
    return Delete("education",education->getId());
}

int ServerController::RemoveEducation(int id)
{
    return Delete("education",id);
}

int ServerController::UpdateEducation(Education *education)
{
    return Update("education", {"education_type_id", "specialization", "date_graduate", "mark", "theme", "university_name"},
                  {QString::number(education->getEducationType()->getId()), education->getSpecialization(), education->getDateGraduate().toString(),
                   QString::number(education->getMark()), education->getTheme(), education->getUniversityName()}, education->getId());
}

QVector<Education *> ServerController::GetEducations(int idHuman)
{
    auto str = QString("SELECT id FROM education WHERE additional_info_human_id = %0;").arg(idHuman);
    QSqlQuery query(str);

    QVector<Education*> educations;

    while(query.next())
    {
        int education_id = ivalue(0);
        Education* education=GetEducation(education_id);
        educations.append(education);
    }

    return educations;
}

Human *ServerController::GetHuman(int idHuman)
{
    auto str = QString("SELECT id, name_first, name_second, patronymic, birthdate, phone_number  "
                    "FROM human WHERE id = %0;").arg(idHuman);
    QSqlQuery query(str);
    if(!query.first())
        return nullptr;

    QString name_first = svalue(1);
    QString name_second = svalue(2);
    QString patronymic = svalue(3);
    QDate birthdate = Instruments::getDate(svalue(4));
    QString phone_number = svalue(5);

    Human* human= new Human(idHuman, name_first, name_second, patronymic, birthdate,phone_number);

    AddirionalInfo* additionalInfo = GetAddirionalInfo(idHuman);
    QVector<Human*> family = GetFamily(idHuman);
    QVector<Address*> address = GeAllAddress(idHuman);
    QVector<Workplace*> workplaces = GetWorkplaces(idHuman);

    human->setAddirionalInfo(additionalInfo);
    human->setFamily(family);
    human->setAddresss(address);
    human->setWorkplaces(workplaces);

    return human;
}

int ServerController::AddHuman(Human *human)
{
    return Insert("human", {"name_first", "name_second", "patronymic", "birthdate", "phone_number"},
                  {human->getName_first(), human->getName_second(),human->getPatronymic(),human->getBirthdate().toString(), human->getPhonenumber()});;

    int idHuman = getLastId("human","id");
    human->setId(idHuman);

    AddAddirionalInfo(human->getAddirionalInfo());

    foreach(auto family, human->getFamily())
        AddHuman(family);

    foreach(auto address, human->getAddresss())
        AddAddress(address, human->getId());

    foreach(auto workplace, human->getWorkplaces())
        AddWorkplace(workplace,human->getId());
}

int ServerController::RemoveHuman(Human *human)
{
    RemoveAddirionalInfo(human->getAddirionalInfo());

    foreach(auto family, human->getFamily())
        RemoveHuman(family);

    foreach(auto address, human->getAddresss())
        RemoveAddress(address, human->getId());

    foreach(auto workplace, human->getWorkplaces())
        RemoveWorkplace(workplace);

    return Delete("human", human->getId());
}

int ServerController::UpdateHuman(Human *human)
{
    UpdateAddirionalInfo(human->getAddirionalInfo());

    foreach(auto family, human->getFamily())
        UpdateHuman(family);

    foreach(auto address, human->getAddresss())
        UpdateAddress(address, human->getId());

    foreach(auto workplace, human->getWorkplaces())
        UpdateWorkplace(workplace);

    return Update("human", {"name_first", "name_second", "patronymic", "birthdate", "phone_number"},
                  {human->getName_first(), human->getName_second(),human->getPatronymic(),human->getBirthdate().toString(), human->getPhonenumber()}, human->getId());;
}

QVector<Human *> ServerController::GetAllHumans()
{
    auto str = QString("SELECT id FROM human h JOIN relatives r ON h.id != r.relative_id;"); //Может не сработать надо проверить на больших данных
    QSqlQuery query(str);

    QVector<Human*> humans;

    while(query.next())
    {
        int human_id = ivalue(0);
        Human* human=GetHuman(human_id);
        humans.append(human);
    }

    return humans;
}

QVector<Human *> ServerController::GetFamily(int idHuman)
{
    auto str = QString("SELECT relative_id, type FROM relatives WHERE human_id = %0;").arg(idHuman);
    QSqlQuery query(str);

    QVector<Human*> humans;

    while(query.next())
    {
        int human_id = ivalue(0);
        QString relatives = svalue(1);
        Human* human = GetHuman(human_id);
        human->setTypeFamily(relatives);
        humans.append(human);
    }

    return humans;
}

int ServerController::AddFamily(Human *family, int idHuman)
{
    AddHuman(family);
    return Insert("relatives", {"human_id", "relative_id", "type"}, {QString::number(idHuman), QString::number(family->getId()), family->getTypeFamily()});
}

int ServerController::RemoveFamily(Human *family, int idHuman)
{
    Delete("relatives", {"human_id", "relative_id"}, {QString::number(idHuman), QString::number(family->getId())});
    return RemoveHuman(family);
}

int ServerController::UpdateFamily(Human *family, int idHuman)
{
    return Update("relatives", {"type"}, {family->getTypeFamily()}, QString("human_id = %0 AND relative_id = %1").arg(idHuman).arg(family->getId()));
}
