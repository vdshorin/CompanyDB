#ifndef EXCELFSB_H
#define EXCELFSB_H

#include "excelbase.h"
#include <QObject>

class ExcelFSB : public ExcelBase
{
    Q_OBJECT
public:
    ExcelFSB();

protected:
    void setColumnsInfo() override;
    void insertValues(QVector<Human*> humans) override;
};

#endif // EXCELFSB_H
