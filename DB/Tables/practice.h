#ifndef PRACTICE_H
#define PRACTICE_H

#include "instruments.h"
#include <QObject>

class Practice : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString companyName READ getCompanyName WRITE setCompanyName NOTIFY companyNameChanged)
    Q_PROPERTY(QDate dateStart READ getDateStart WRITE setDateStart NOTIFY dateStartChanged)
    Q_PROPERTY(QDate dateEnd READ getDateEnd WRITE setDateEnd NOTIFY dateEndChanged)
//    Q_PROPERTY(int idAdditionalInfoHumanId READ getIdAdditionalInfoHumanId WRITE setIdAdditionalInfoHumanId NOTIFY idAdditionalInfoHumanIdChanged)
public:
    explicit Practice(QObject *parent = nullptr);
    Practice(int _idPractice, QString _type, QString _company_name, QDate _date_start, QDate _date_end):
    id(_idPractice), type(_type), companyName(_company_name), dateStart(_date_start), dateEnd(_date_end){}
    int getId() const;
    void setId(int value);

    QString getType() const;
    void setType(const QString &value);

    QString getCompanyName() const;
    void setCompanyName(const QString &value);

    QDate getDateStart() const;
    void setDateStart(const QDate &value);

    QDate getDateEnd() const;
    void setDateEnd(const QDate &value);

//    int getIdAdditionalInfoHumanId() const;
//    void setIdAdditionalInfoHumanId(int value);

private:
    int id;
    QString type;
    QString companyName;
    QDate dateStart;
    QDate dateEnd;
//    int idAdditionalInfoHumanId;

signals:
    void idChanged();
    void typeChanged();
    void companyNameChanged();
    void dateStartChanged();
    void dateEndChanged();
//    void idAdditionalInfoHumanIdChanged();
};

#endif // PRACTICE_H
