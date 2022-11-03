#include "excelbase.h"

#include <relatives.h>


ExcelBase::ExcelBase(QObject *parent) : QObject(parent)
{}

void ExcelBase::createExcelTable(QVector<Human*> humans, QString path)
//void ExcelRota::createExcelTable()
{
    insertHeadersToTable();
    insertValues(humans);

    document.saveAs(path);
}


void ExcelBase::insertHeadersToTable()
{
    QXlsx::Format formatHeader;
    formatHeader.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    formatHeader.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    formatHeader.setPatternBackgroundColor(QColor(Qt::yellow));
    formatHeader.setBorderStyle(QXlsx::Format::BorderMedium);

    for (auto i = columns.begin(); i != columns.end(); i++)
    {
//        qDebug() << "I: " << i->number;    || 1, 2, ....
        document.write(1, i.value().number, i.value().name, formatHeader);
    }


    document.autosizeColumnWidth(1, columns.count());
}


QString ExcelBase::getFamily(Human *human)
{
    QString result;
    QVector<Human*> relatives = human->getFamily();
    foreach (auto relative, relatives)
    {
        qDebug() << "_______Relative:____________________________: " << relative->getName_second();
//
//            Relatives* relative = new Relatives();
//            QString relativeType = Relatives
        /// ФИО
        QString relativeFullName = relative->getName_second() + " "
                            + relative->getName_first() + " "
                            + relative->getPatronymic()
                            ;
        result += relativeFullName + ", " + relative->getBirthdate().toString("dd-MM-yyyy") + "; \n";;

        /// Место работы
        QVector<Workplace*> workplaces = relative->getWorkplaces();
        foreach(auto workplace, workplaces)
        {
            qDebug() << "_________________workplace__________________: " << workplace->getName();
            QString work = workplace->getName() + ", " \
                            + workplace->getWorkplaceType()->getValue() + ", " \
                            + workplace->getPosition() + "; ";
            result += work;
        }

        ///Телефон
        result += relative->getPhonenumber() + ";\n ";

    }
    return result;
}

QString ExcelBase::getFamilyAddress(Human *human)
{
    QString res;
    foreach(auto addr, human->getFamily()[0]->getAddresss())
    {
     if (addr->getType() == addressTypeLiving)
     {
         res = addr->getRegion() + ", " \
                        + addr->getSity() + ", " \
                        + addr->getStreet() + ", " \
                        + addr->getBuilding() + ", " \
                        + addr->getFlat();
         break;
     }

    }
    return res;

}

QString ExcelBase::getDocument(AddirionalInfo *addInfo, documentType type)
{
    QVector<Document*> documents = addInfo->getDocuments();

    bool isForeignPassportExists = false;
    foreach(auto doc, documents)
    {
        if (doc->getDocumentType()->getId() == ePassport)
        {
            QString passport = doc->getSeries() + " " \
                                + doc->getNumber() + " " \
                                + doc->getIssuePlace() + " " \
                                + doc->getIssueDate().toString("dd-MM-yyyy") + " " \
                                + doc->getAdditionalNumber() + " " \
                                ;
            return passport;
        }
        else if (doc->getDocumentType()->getId() == eSnils)
        {
            QString snils = doc->getAdditionalNumber();
            return snils;
        }
        else if (doc->getDocumentType()->getId() == eInn)
        {
            QString inn = doc->getAdditionalNumber();
            return inn;
        }
        else if (doc->getDocumentType()->getId() == eForeignPassport)
        {
            isForeignPassportExists = true;
            QString passport = doc->getSeries() + " " \
                                + doc->getNumber() + " " \
                                + doc->getIssuePlace() + " " \
                                + doc->getIssueDate().toString("dd-MM-yyyy") + " " \
                                + doc->getAdditionalNumber() + " " \
                                ;
            return passport;
        }
        else if (doc->getDocumentType()->getId() == eMilitary)
        {
            isForeignPassportExists = true;
            QString passport = doc->getSeries() + " " \
                                + doc->getNumber() + " " \
                                + doc->getIssuePlace() + " " \
                                + doc->getIssueDate().toString("dd-MM-yyyy") + " " \
                                + doc->getAdditionalNumber() + " " \
                                ;
            return passport;
        }

        if (!isForeignPassportExists)
            return "-";

    }
}

QString ExcelBase::getEducations(AddirionalInfo *addInfo)
{
    QString result;

    QVector<Education*> educations = addInfo->getEducations();
    foreach(auto edu, educations)
    {
        result += edu->getEducationType()->getValue() + ": " \
                + edu->getUniversityName() + ", " \
                + edu->getSpecialization() + ", " \
                + edu->getDateGraduate().toString("dd-MM-yyyy") + ";\n"
                ;
    }

    return result;
}

QString ExcelBase::getPractices(AddirionalInfo *addInfo, practices type)
{
    QVector<Practice*> practices = addInfo->getPractices();
    QString result;
    foreach(auto practice, practices)
    {
        if (practice->getType() == "Университет" && type == ehome) {
            result += practice->getCompanyName() + ", " \
                        + practice->getDateStart().toString("dd-MM-yyyy") + " - " + practice->getDateEnd().toString("dd-MM-yyyy") + ";";
        }
        else if (practice->getType() == "Заграничная" && type == eforeign) {
            result += practice->getCompanyName() + ", " \
                        + practice->getDateStart().toString("dd-MM-yyyy") + " - " + practice->getDateEnd().toString("dd-MM-yyyy") + ";";
        }

//        qDebug() << "pr: " << practice->getType();
    }
    return result;
}

QString ExcelBase::getWorkplaces(AddirionalInfo *addInfo)
{
    QString result;
    return result;
}

QString ExcelBase::getScience(AddirionalInfo *addInfo)
{
    QString result;
    QVector<ScientificWork*> sciences = addInfo->getScientificWorks();

    foreach(auto science, sciences)
        result += science->getScientificWorkType()->getValue() + ": " + science->getInformation() + ";\n";

    return result;
}

Education *ExcelBase::getLastEducation(AddirionalInfo *addInfo)
{
    Education *lastEdu = addInfo->getEducations()[0];
    foreach (auto edu, addInfo->getEducations())
    {
        if (edu->getDateGraduate() > lastEdu->getDateGraduate())
            lastEdu = edu;
    }

    return lastEdu;

}

double ExcelBase::getMark(AddirionalInfo* addInfo, ExcelBase::educations eduType)
{
    double result;
    foreach (auto edu, addInfo->getEducations())
    {
        if (edu->getEducationType()->getId() == eduType)
            result = edu->getMark();
    }
    return result;
}

QString ExcelBase::getWorkExperience(int days)
{
    QString res;
    int years = days / 365;
    if (years > 0)
        res += "Лет: " + QString::number(years) + " ";

    days -= years * 365;
    int months = days / 30;
    if (months > 0)
        res += "Месяцев: " + QString::number(months) + " ";

    days -= months * 30;
    res += "Дней: " + QString::number(days);
    return res;
}

//    columns[""] = {, ""};
//    columns["rank"]                 = {1, "Звание"};
//    columns["rota"]                 = {2, "Рота"};
//    columns["squad"]                = {3, "Взвод"};
//    columns["summon"]               = {4, "Призыв"};
//    columns["full_name"]            = {5, "Фамилия, Имя, Отчество"} ;
//    columns["phone"]                = {6, "Номер телефона"};
//    columns["birthdate"]            = {7, "Дата рождения"};
//    columns["birthplace"]           = {8, "Место рождения"};
//    columns["address_registration"] = {9, "Адрес прописки"};
//    columns["address_living"]       = {10, "Адрес проживания по факту"};
//    columns["marital_status"]       = {11, "Семейное положение"};
//    columns["religion"]             = {12, "Вероисповедание"};
//    columns["nationality"]          = {13, "Национальность"};
//    columns["family"]               = {14, "Состав семьи (тип, ФИО, число месяц год рождения, место работы, должность, номер телефона)"};
//    columns["address_family"]       = {15, "Адрес проживания родителей"};
//    columns["doc_inn"]              = {16, "ИНН"};
//    columns["doc_snils"]            = {17, "СНИЛС"};
//    columns["doc_passport"]         = {18, "Паспортные данные (серия, номер, кем и когда выдан, код подразделения)"};
//    columns["doc_foreign_passport"] = {19, "Наличие загранпаспорта (серия, номер, кем и когда выдан)"};
//    columns["military_department"]  = {20, "Наименование отдела ВК"};
//    columns["departure_date"]       = {21, "Дата убытия из пункта распределения ВС РФ"};
//    columns["soldier_date"]         = {22, "Дата присвоения воинского звания «рядовой»"};
//    columns["doc_military"]         = {23, "Военный билет (серия, номер, кем и когда выдан)"};
//    columns["personal_number"]      = {24, "Личный номер"};
//    columns["educations"]           = {25, "Образование (название ВУЗа, специальность, год окончания)"};
//    columns["university_name"]      = {26, "Наименование учебного заведения"};
//    columns["specialization"]       = {27, "Наименование специального высшего профессионального образования (специальность по диплому)"};
//    columns["mark_bac"]             = {28, "Средний балл бакалавр"};
//    columns["mark_mag"]             = {30, "Средний балл магистратура"};
//    columns["mark_spec"]            = {29, "Средний балл специалитет"};
//    columns["diploma_theme"]        = {31, "Тема диплома"};
//    columns["practics"]             = {32, "Практика во время учебы"};
//    columns["foreign_practics"]     = {33, "Заграничная практика во время учебы"};
//    columns["science"]              = {34, "Опыт научной работы (публикации, выступления) до призыва в ВС РФ"};
//    columns["workplace"]            = {35, "Место работы (адрес и дата)"};
//    columns["work_position"]        = {36, "Должность"};
//    columns["work_experience"]      = {37, "Опыт работы"};
//    columns["work_activity"]        = {38, "Направление деятельности на работе"};
//    columns["foreign_languages"]    = {39, "Владение иностранными языками"};
//    columns["foreign_trips"]        = {40, "Заграничные поездки"};
//    columns["software"]             = {41, "Знание программных продуктов"};
//    columns["programm_languages"]   = {42, "Знание языков программирования"};
//    columns["other_info"]           = {43, "Дополнительные сведения (хобби, достижения в спорте, умения и тд)"};
//    columns["cloth_size_start"]     = {44, "Размер офисной формы во время прибытия"};
//    columns["cloth_size_personal"]  = {45, "Точная форма одежды"};
//    columns["shoes_size"]           = {46, "Размер обуви"};
//    columns["hat_size"]             = {47, "Размер головного убора"};
//    columns["link_vk"]              = {48, "Вконтакте"};
//    columns["link_inst"]            = {49, "Инстаграмм"};
//    columns["email"]                = {50, "Электронная почта"};

//void ExcelRotaPassport::insertValues(QVector<Human *> humans)
//{
//    for (int i = 0; i < humans.count(); i++)
//    {
//        {
//            document.write(i + 2, columns["№"].number, i + 1);
//        }
//        /// Личная информация
//        {
//            QString fullName = "";
//            fullName = humans[i]->getName_second() + " "
//                                + humans[i]->getName_first() + " "
//                                + humans[i]->getPatronymic()
//                                ;
//            document.write(i + 2, columns["full_name_number"].number,
//                    fullName + ", " + );
//            document.write(i + 2, columns["phone"].number, humans[i]->getPhonenumber());
//            document.write(i + 2, columns["birthdate"].number, humans[i]->getBirthdate());
//        }

//        /// Дополнительная информация
//        AddirionalInfo *addInfo = humans[i]->getAddirionalInfo();
//        {

//            document.write(i + 2, columns["rota"].number, addInfo->getRota()->getValue());
//            document.write(i + 2, columns["squad"].number, addInfo->getSquad()->getValue());
//            document.write(i + 2, columns["rank"].number, addInfo->getRank()->getValue());
//            document.write(i + 2, columns["summon"].number, addInfo->getSummon()->getValue());
//            document.write(i + 2, columns["birthplace"].number, addInfo->getBirthplace());
//            document.write(i + 2, columns["marital_status"].number, addInfo->getMaritalStatus());
//            document.write(i + 2, columns["religion"].number, addInfo->getReligion());
//            document.write(i + 2, columns["nationality"].number, addInfo->getNationality());
//        }

//        /// Адреса
//        {
//            QVector<Address*> addresses = humans[i]->getAddresss();
//            foreach (auto address, addresses) {
//                if (address->getType() == addressTypeRegistration)
//                    document.write(i + 2, columns["address_registration"].number, address->getAddress());
//                else if (address->getType() == addressTypeLiving)
//                    document.write(i + 2, columns["address_living"].number, address->getAddress());
//            }
//        }

//        /// Семья
//        {
//            QString family = addInfo->getFamilyType() + " \n";
//            family += getFamily(humans[i]);
//            document.write(i + 2, columns["family"].number, family);

//            QString addressFamily = getFamilyAddress(humans[i]);
//            document.write(i + 2, columns["address_family"].number, addressFamily);
//        }

//        /// Документы
//        {
//            document.write(i + 2, columns["doc_passport"].number, getDocument(addInfo, ePassport));
//            document.write(i + 2, columns["doc_snils"].number, getDocument(addInfo, eSnils));
//            document.write(i + 2, columns["doc_inn"].number, getDocument(addInfo, eInn));
//            document.write(i + 2, columns["doc_foreign_passport"].number, getDocument(addInfo, eForeignPassport));
//            document.write(i + 2, columns["doc_military"].number, eMilitary);

//        }

//        /// Информация о призыве
//        {
//            document.write(i + 2, columns["military_department"].number, addInfo->getMilitaryDepartament() == nullptr ? "-" : addInfo->getMilitaryDepartament());
//            document.write(i + 2, columns["departure_date"].number, addInfo->getDepartureDate());
//            document.write(i + 2, columns["soldier_date"].number, addInfo->getSoldierDate());
//            document.write(i + 2, columns["personal_number"].number, addInfo->getPersonalNumber());
//        }

//        /// Образование
//        /// Выбрать документ, который используется для поступления
//        {
////            QVector<EducationType *> types = controller->GetAllEducationTypes();
////            foreach (auto type, types)
////                qDebug() << "type: " << type->getId() << " - " << type->getValue();
//            document.write(i + 2, columns["educations"].number, getEducations(addInfo));
//            Education *edu = getLastEducation(addInfo);
//            document.write(i + 2, columns["university_name"].number, edu->getUniversityName());
//            document.write(i + 2, columns["specialization"].number, edu->getSpecialization());
//            document.write(i + 2, columns["mark_bac"].number, getMark(addInfo, eEduBac));
//            document.write(i + 2, columns["mark_mag"].number, getMark(addInfo, eEduMag));
//            document.write(i + 2, columns["mark_spec"].number, getMark(addInfo, eEduSpec));
//            document.write(i + 2, columns["diploma_theme"].number, edu->getTheme());
//        }

//        /// Практика
//        /// Тип практики установить
//        {
//            document.write(i + 2, columns["practics"].number, getPractices(addInfo, ehome));
//            document.write(i + 2, columns["foreign_practics"].number, getPractices(addInfo, eforeign));
//        }

//        /// Наука
//        {
//            document.write(i + 2, columns["science"].number, getScience(addInfo));
//        }

//        /// Работа
//        /// Выбрать последнее место работы
//        {
//            foreach(auto workplace, humans[i]->getWorkplaces())
//            {
//                document.write(i + 2, columns["workplace"].number,
//                        workplace->getName() + ", " + workplace->getDateStart().toString("dd-MM-yyyy") + " - " + workplace->getDateEnd().toString("dd-MM-yyyy"));
//                document.write(i + 2, columns["work_position"].number, workplace->getPosition());
//                document.write(i + 2, columns["work_experience"].number, getWorkExperience(workplace->getDateStart().daysTo(workplace->getDateEnd())));
//                document.write(i + 2, columns["work_activity"].number, workplace->getActivity());

//            }
//        }

//        /// Разное
//        {
//            document.write(i + 2, columns["foreign_languages"].number, addInfo->getLanguages());
//            document.write(i + 2, columns["foreign_trips"].number, addInfo->getOverseasTrips());
//            document.write(i + 2, columns["software"].number, addInfo->getSoftware());
//            document.write(i + 2, columns["programm_languages"].number, addInfo->getProgrammingLanguages());
//            document.write(i + 2, columns["other_info"].number, addInfo->getOtherInfo());
//        }

//        /// Одежда
//        {
//            document.write(i + 2, columns["cloth_size_start"].number, addInfo->getClothesSizeStart());
//            document.write(i + 2, columns["cloth_size_personal"].number, addInfo->getClothesSizeStart());
//            document.write(i + 2, columns["shoes_size"].number, addInfo->getSizeShoes());
//            document.write(i + 2, columns["hat_size"].number, addInfo->getHatSize());
//        }

//        /// Ссылки
//        {
//            document.write(i + 2, columns["link_vk"].number, addInfo->getLinkVK());
//            document.write(i + 2, columns["link_inst"].number, addInfo->getLinkInstagramm());
//            document.write(i + 2, columns["email"].number, addInfo->getEmail());
//        }

//        break;
//    }
//}
