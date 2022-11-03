#include "excelrotapassport.h"

ExcelRotaPassport::ExcelRotaPassport()
{
    ExcelRotaPassport::setColumnsInfo();
    controller = ServerController::getInstance();
}

void ExcelRotaPassport::insertValues(QVector<Human *> humans)
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
            document.write(i + 2, columns["full_name_number"].number,
                    fullName + ", " + humans[i]->getPhonenumber());
            document.write(i + 2, columns["birthdate"].number, humans[i]->getBirthdate());
        }

        /// Дополнительная информация
        AddirionalInfo *addInfo = humans[i]->getAddirionalInfo();
        {
            document.write(i + 2, columns["birthplace"].number, addInfo->getBirthplace());
            document.write(i + 2, columns["marital_status"].number, addInfo->getMaritalStatus());
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
        }

        /// Документы
        {
            document.write(i + 2, columns["doc_passport"].number, getDocument(addInfo, ePassport));
            document.write(i + 2, columns["doc_snils"].number, getDocument(addInfo, eSnils));
            document.write(i + 2, columns["doc_inn"].number, getDocument(addInfo, eInn));
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
//            QVector<EducationType *> types = controller->GetAllEducationTypes();
//            foreach (auto type, types)
//                qDebug() << "type: " << type->getId() << " - " << type->getValue();
            document.write(i + 2, columns["educations"].number, getEducations(addInfo));
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
            document.write(i + 2, columns["practics"].number, getPractices(addInfo, ehome));
        }

        /// Наука
        {
            document.write(i + 2, columns["science"].number, getScience(addInfo));
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
                document.write(i + 2, columns["work_activity"].number, workplace->getActivity());

            }
        }

        /// Разное
        {
            document.write(i + 2, columns["foreign_languages"].number, addInfo->getLanguages());
            document.write(i + 2, columns["foreign_trips"].number, addInfo->getOverseasTrips());
            document.write(i + 2, columns["software"].number, addInfo->getSoftware());
            document.write(i + 2, columns["programm_languages"].number, addInfo->getProgrammingLanguages());
            document.write(i + 2, columns["other_info"].number, addInfo->getOtherInfo());
        }

        /// Одежда
        {
            document.write(i + 2, columns["cloth_size_start"].number, addInfo->getClothesSizeStart());
            document.write(i + 2, columns["cloth_size_personal"].number, addInfo->getClothesSizeStart());
            document.write(i + 2, columns["shoes_size"].number, addInfo->getSizeShoes());
            document.write(i + 2, columns["hat_size"].number, addInfo->getHatSize());
        }

        break;
    }
}

void ExcelRotaPassport::setColumnsInfo()
{
    //    columns[""] = {, ""};
        columns["№"]                    = {1, "№"};
        columns["full_name_number"]     = {2, "ФИО (Номер телефона)"};
        columns["birthdate"]            = {3, "Дата рождения"};
        columns["birthplace"]           = {4, "Место рождения"};
        columns["address_registration"] = {5, "Адрес прописки"};
        columns["address_living"]       = {6, "Адрес проживания (по факту)"};
        columns["marital_status"]       = {7, "Семейное положение"};

        columns["family"]               = {8, "Состав семьи (тип, ФИО, число месяц год рождения, место работы, должность, номер телефона)"};

        columns["nationality"]          = {9, "Национальность"};

        columns["doc_inn"]              = {10, "ИНН"};
        columns["doc_snils"]            = {11, "СНИЛС"};
        columns["doc_passport"]         = {12, "Паспортные данные (серия, номер, кем и когда выдан, код подразделения)"};
        columns["doc_foreign_passport"] = {13, "Наличие загранпаспорта (серия, номер, кем и когда выдан)"};

        columns["military_department"]  = {14, "Наименование отдела военного комиссариата"};
        columns["departure_date"]       = {15, "Дата убытия из пункта распределения ВС РФ"};
        columns["doc_military"]         = {16, "Военный билет (серия, номер, кем и когда выдан)"};
        columns["personal_number"]      = {17, "Личный номер"};

        columns["educations"]           = {18, "Образование (название ВУЗа, специальность, год окончания)"};
        columns["university_name"]      = {19, "Наименование учебного заведения"};
        columns["specialization"]       = {20, "Наименование специального высшего профессионального образования (специальность по диплому)"};
        columns["mark_bac"]             = {21, "Средний балл бакалавр"};
        columns["mark_mag"]             = {22, "Средний балл магистратура"};
        columns["mark_spec"]            = {23, "Средний балл специалитет"};
        columns["diploma_theme"]        = {24, "Тема диплома"};

        columns["practics"]             = {25, "Практика во время учебы"};

        columns["science"]              = {26, "Опыт научной работы (публикации, выступления) до призыва в ВС РФ"};

        columns["workplace"]            = {27, "Место работы (адрес и дата)"};
        columns["work_position"]        = {28, "Должность"};
        columns["work_experience"]      = {29, "Опыт работы"};
        columns["work_activity"]        = {30, "Направление деятельности на работе"};

        columns["foreign_languages"]    = {31, "Владение иностранными языками"};
        columns["foreign_trips"]        = {32, "Заграничные поездки"};
        columns["software"]             = {33, "Знание программных продуктов"};
        columns["programm_languages"]   = {34, "Знание языков программирования"};
        columns["other_info"]           = {35, "Дополнительные сведения (хобби, достижения в спорте, умения и тд)"};

        columns["cloth_size_start"]     = {36, "Размер офисной формы во время прибытия"};
        columns["cloth_size_personal"]  = {37, "Точная форма одежды"};
        columns["shoes_size"]           = {38, "Размер обуви"};
        columns["hat_size"]             = {39, "Размер головного убора"};


//        columns["foreign_practics"]     = {33, "Заграничная практика во время учебы"};
//        columns["soldier_date"]         = {22, "Дата присвоения воинского звания «рядовой»"};
//        columns["squad"]                = {3, "Взвод"};
//        columns["summon"]               = {4, "Призыв"};
//        columns["full_name"]            = {5, "Фамилия, Имя, Отчество"} ;
//        columns["phone"]                = {6, "Номер телефона"};
//        columns["religion"]             = {12, "Вероисповедание"};
//        columns["address_family"]       = {15, "Адрес проживания родителей"};
//        columns["link_inst"]            = {49, "Инстаграмм"};
//        columns["email"]                = {50, "Электронная почта"};
//        columns["link_vk"]              = {48, "Вконтакте"};

}

