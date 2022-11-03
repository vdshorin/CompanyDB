#include "excelfsb.h"

ExcelFSB::ExcelFSB()
{
    ExcelFSB::setColumnsInfo();
    controller = ServerController::getInstance();
}

void ExcelFSB::insertValues(QVector<Human *> humans)
{
    for (int i = 0; i < humans.count(); i++)
    {
        {
            document.write(i + 2, columns["№"].number, i + 1);
        }
        /// Личная информация
        {
            QString fullName = "";
            fullName = humans[i]->getName_second() + " "
                                + humans[i]->getName_first() + " "
                                + humans[i]->getPatronymic()
                                ;
            document.write(i + 2, columns["full_name"].number, fullName);
            document.write(i + 2, columns["phone"].number, humans[i]->getPhonenumber());
            document.write(i + 2, columns["birthdate"].number, humans[i]->getBirthdate());
        }

        /// Дополнительная информация
        AddirionalInfo *addInfo = humans[i]->getAddirionalInfo();
        {

            document.write(i + 2, columns["rank"].number, addInfo->getRank()->getValue());
            document.write(i + 2, columns["rota"].number, addInfo->getRota()->getValue());
            document.write(i + 2, columns["squad"].number, addInfo->getSquad()->getValue());
            document.write(i + 2, columns["birthplace"].number, addInfo->getBirthplace());

            document.write(i + 2, columns["marital_status"].number, addInfo->getMaritalStatus());
            document.write(i + 2, columns["religion"].number, addInfo->getReligion());
            document.write(i + 2, columns["nationality"].number, addInfo->getNationality());
        }

        /// Адреса
        {
            QVector<Address*> addresses = humans[i]->getAddresss();
            foreach (auto address, addresses) {
                if (address->getType() == addressTypeRegistration)
                    document.write(i + 2, columns["address_registration"].number, address->getAddress());
                else if (address->getType() == addressTypeLiving)
                    document.write(i + 2, columns["address_living"].number, address->getAddress());
            }
        }

        /// Семья
        {
            QString family = addInfo->getFamilyType() + " \n";
            family += getFamily(humans[i]);
            document.write(i + 2, columns["family"].number, family);

            QString addressFamily = getFamilyAddress(humans[i]);
            document.write(i + 2, columns["address_family"].number, addressFamily);
        }

        /// Документы
        {
            document.write(i + 2, columns["doc_passport"].number, getDocument(addInfo, ePassport));
            document.write(i + 2, columns["doc_foreign_passport"].number, getDocument(addInfo, eForeignPassport));
            document.write(i + 2, columns["doc_military"].number, eMilitary);

        }

        /// Информация о призыве
        {
            document.write(i + 2, columns["military_department"].number, addInfo->getMilitaryDepartament() == nullptr ? "-" : addInfo->getMilitaryDepartament());
            document.write(i + 2, columns["departure_date"].number, addInfo->getDepartureDate());
            document.write(i + 2, columns["personal_number"].number, addInfo->getPersonalNumber());
        }

        /// Образование
        /// Выбрать документ, который используется для поступления
        {
            Education *edu = getLastEducation(addInfo);
            document.write(i + 2, columns["university_name"].number, edu->getUniversityName());
            document.write(i + 2, columns["specialization"].number, edu->getSpecialization());
            document.write(i + 2, columns["mark_bac"].number, getMark(addInfo, eEduBac));
            document.write(i + 2, columns["mark_mag"].number, getMark(addInfo, eEduMag));
            document.write(i + 2, columns["mark_spec"].number, getMark(addInfo, eEduSpec));
            document.write(i + 2, columns["diploma_theme"].number, edu->getTheme());
        }

        /// Практика
        /// Тип практики установить
        {
            document.write(i + 2, columns["foreign_practics"].number, getPractices(addInfo, eforeign));
        }

        /// Работа
        /// Выбрать последнее место работы
        {
            foreach(auto workplace, humans[i]->getWorkplaces())
            {
                document.write(i + 2, columns["workplace"].number,
                        workplace->getName() + ", " + workplace->getDateStart().toString("dd-MM-yyyy") + " - " + workplace->getDateEnd().toString("dd-MM-yyyy"));
                document.write(i + 2, columns["work_position"].number, workplace->getPosition());
                document.write(i + 2, columns["work_experience"].number, getWorkExperience(workplace->getDateStart().daysTo(workplace->getDateEnd())));
            }
        }

        /// Разное
        {
            document.write(i + 2, columns["software"].number, addInfo->getSoftware());
            document.write(i + 2, columns["programm_languages"].number, addInfo->getProgrammingLanguages());

            document.write(i + 2, columns["foreign_languages"].number, addInfo->getLanguages());
            document.write(i + 2, columns["foreign_trips"].number, addInfo->getOverseasTrips());
        }

        /// Одежда
        {
            document.write(i + 2, columns["shoes_size"].number, addInfo->getSizeShoes());
            document.write(i + 2, columns["hat_size"].number, addInfo->getHatSize());
        }

        /// Ссылки
        {
            document.write(i + 2, columns["link_vk"].number, addInfo->getLinkVK());
            document.write(i + 2, columns["link_inst"].number, addInfo->getLinkInstagramm());
            document.write(i + 2, columns["email"].number, addInfo->getEmail());
        }

        break;
    }
}

void ExcelFSB::setColumnsInfo()
{
    columns["№"]                    = {1, "№"};
    columns["rank"]                 = {2, "Звание"};
    columns["full_name"]            = {3, "ФИО"} ;
    columns["phone"]                = {4, "Номер телефона"};
    columns["birthdate"]            = {5, "Дата рождения"};
    columns["birthplace"]           = {6, "Место рождения"};

    columns["address_registration"] = {7, "Адрес прописки"};
    columns["address_living"]       = {8, "Адрес проживания по факту"};

    columns["marital_status"]       = {9, "Семейное положение"};
    columns["religion"]             = {10, "Вероисповедание"};

    columns["family"]               = {11, "Состав семьи, ФИО, число месяц год рождения, место рождения, место работы (номер телефона)"};
    columns["address_family"]       = {12, "Адрес проживания родителей"};
    columns["nationality"]          = {13, "Национальность"};
    columns["autobiography"]        = {14, "Автобиография"};

    columns["doc_passport"]         = {15, "Паспортные данные (серия, номер, кем и когда выдан, код подразделения)"};
    columns["doc_foreign_passport"] = {16, "Наличие загранпаспорта (серия, номер, кем и когда выдан)"};

    columns["military_department"]  = {17, "Наименование отдела военного комиссариата"};
    columns["departure_date"]       = {18, "Дата убытия из пункта распределения ВС РФ"};
    columns["doc_military"]         = {19, "Военный билет (серия, номер, кем и когда выдан)"};
    columns["personal_number"]      = {20, "Личный номер"};

    columns["university_name"]      = {21, "Наименование учебного заведения"};
    columns["specialization"]       = {22, "Наименование специального высшего профессионального образования (специальность по диплому)"};
    columns["mark_bac"]             = {23, "Средний балл (Бакалавр)"};
    columns["mark_mag"]             = {24, "Средний балл (Магистратура)"};
    columns["mark_spec"]            = {25, "Средний балл (Специалитет)"};
    columns["diploma_theme"]        = {26, "Тема диплома"};
    columns["foreign_practics"]     = {27, "Заграничная практика во время учебы"};
    columns["software"]             = {28, "Знание программных продуктов"};

    columns["programm_languages"]   = {29, "Знание языков программирования"};
    columns["workplace"]            = {30, "Место работы (адрес и дата)"};
    columns["work_position"]        = {31, "Должность"};
    columns["work_experience"]      = {32, "Опыт работы"};

    columns["foreign_languages"]    = {33, "Владение иностранными языками"};
    columns["foreign_trips"]        = {34, "Заграничные поездки"};
    columns["shoes_size"]           = {35, "Размер обуви"};
    columns["hat_size"]             = {36, "Размер головного убора"};
    columns["squad"]                = {37, "Взвод"};
    columns["rota"]                 = {38, "Рота"};
    columns["link_vk"]              = {39, "Вконтакте"};
    columns["link_inst"]            = {40, "Инстаграмм"};
    columns["email"]                = {41, "Электронная почта"};
}
