#ifndef EXCELROTAPASSPORT_H
#define EXCELROTAPASSPORT_H

#include "excelbase.h"

class ExcelRotaPassport : public ExcelBase
{
public:
    ExcelRotaPassport();

protected:
    void setColumnsInfo() override;
    void insertValues(QVector<Human*> humans) override;
};

#endif // EXCELROTAPASSPORT_H
