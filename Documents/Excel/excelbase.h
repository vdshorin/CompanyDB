#ifndef EXCELBASEH_H
#define EXCELBASEH_H

#include <QObject>
//#include "QXlsx-master/QXlsx/header/
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include "servercontroller.h"
#include <xlsxformat.h>

#include "human.h"


class ExcelBase : public QObject
{
    Q_OBJECT
public:
    explicit ExcelBase(QObject *parent = nullptr);

    void createExcelTable(QVector<Human*> humans, QString path);

protected:
    struct Variable
    {
        int number;
        QString name;
    };

    enum documentType {ePassport = 1, eSnils, eInn, eMilitary, eForeignPassport} docType;
    enum practices {ehome = 1, eforeign} ePractices;
    enum educations {eEduBac = 1, eEduMag, eEduSpec} eduTypes;

    QMap<QString, Variable> columns;
    QVector<QString> headers;
    QXlsx::Document document;

    const QString addressTypeRegistration = "Зарегистрирован";
    const QString addressTypeLiving = "Проживает";

    ServerController* controller;

    virtual void setColumnsInfo() = 0;
    virtual void insertValues(QVector<Human*> humans) = 0;
    void insertHeadersToTable();

    virtual QString getFamily(Human* human);
    virtual QString getFamilyAddress(Human* human);
    virtual QString getDocument(AddirionalInfo* addInfo, documentType type);
    virtual QString getEducations(AddirionalInfo* addInfo);
    virtual QString getPractices(AddirionalInfo* addInfo, practices type);
    virtual QString getWorkplaces(AddirionalInfo* addInfo);
    virtual QString getScience(AddirionalInfo* addInfo);
    virtual Education* getLastEducation(AddirionalInfo* addInfo);
    virtual double getMark(AddirionalInfo* addInfo, educations eduType);
    virtual QString getWorkExperience(int days);

signals:

};

#endif // EXCELBASEH_H
