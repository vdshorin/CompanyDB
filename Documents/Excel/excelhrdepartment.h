#ifndef EXCELHRDEPARTMENT_H
#define EXCELHRDEPARTMENT_H

#include "excelbase.h"
#include <QObject>

class ExcelHRDepartment : public ExcelBase
{
    Q_OBJECT
public:
    ExcelHRDepartment();

protected:
    void setColumnsInfo() override;
    void insertValues(QVector<Human*> humans) override;
};

#endif // EXCELHRDEPARTMENT_H
