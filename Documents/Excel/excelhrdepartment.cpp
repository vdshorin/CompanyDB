#include "excelhrdepartment.h"

ExcelHRDepartment::ExcelHRDepartment()
{
    ExcelHRDepartment::setColumnsInfo();
    controller = ServerController::getInstance();
}

void ExcelHRDepartment::insertValues(QVector<Human *> humans)
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
            document.write(i + 2, columns["squad"].number, addInfo->getSquad()->getValue());
        }

        /// Документы
        {
            Document* passport;
            foreach (auto doc, addInfo->getDocuments())
            {
                if (doc->getDocumentType()->getId() == ePassport)
                {
                    passport = doc;
                    break;
                }
            }
            document.write(i + 2, columns["passport_number"].number, passport->getSeries() + " " + passport->getNumber());
            document.write(i + 2, columns["passport_issue_place"].number, passport->getIssuePlace());
            document.write(i + 2, columns["passport_issue_date"].number, passport->getIssueDate());
            document.write(i + 2, columns["passport_add_number"].number, passport->getAdditionalNumber());

            document.write(i + 2, columns["doc_snils"].number, getDocument(addInfo, eSnils));
            document.write(i + 2, columns["doc_inn"].number, getDocument(addInfo, eInn));
            document.write(i + 2, columns["doc_foreign_passport"].number, getDocument(addInfo, eForeignPassport));
        }

        /// Информация о призыве
        {
            document.write(i + 2, columns["personal_number"].number, addInfo->getPersonalNumber());
        }

        /// Образование
        /// Выбрать документ, который используется для поступления
        {
            document.write(i + 2, columns["educations"].number, getEducations(addInfo));
        }

        break;
    }
}

void ExcelHRDepartment::setColumnsInfo()
{
    columns["№"]                    = {1, "№ п/п"};
    columns["squad"]                = {2, "Взвод"};
    columns["full_name"]            = {3, "Фамилия, Имя, Отчество"} ;
    columns["birthdate"]            = {4, "Дата рождения"};
    columns["phone"]                = {5, "Номер телефона"};
    columns["educations"]           = {6, "Образование (название ВУЗа, специальность, год окончания)"};
    columns["passport_number"]      = {7, "Серия и номер паспорта"};
    columns["passport_issue_place"] = {8, "Кем выдан"};
    columns["passport_issue_date"]  = {9, "Когда выдан"};
    columns["passport_add_number"]  = {10, "Код подразделения"};
    columns["personal_number"]      = {11, "Личный номер"};
    columns["doc_inn"]              = {12, "ИНН"};
    columns["doc_snils"]            = {13, "СНИЛС"};
    columns["doc_foreign_passport"] = {14, "Наличие загранпаспорта (серия, номер, кем и когда выдан)"};

}
