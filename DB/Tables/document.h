#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>
#include "documenttype.h"

class Document : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString series READ getSeries WRITE setSeries NOTIFY seriesChanged)
    Q_PROPERTY(QString number READ getNumber WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(QString issuePlace READ getIssuePlace WRITE setIssuePlace NOTIFY issuePlaceChanged)
    Q_PROPERTY(QDate issueDate READ getIssueDate WRITE setIssueDate NOTIFY issueDateChanged)
    Q_PROPERTY(QString additionalNumber READ getAdditionalNumber WRITE setAdditionalNumber NOTIFY additionalNumberChanged)
    Q_PROPERTY(DocumentType* focumentType READ getDocumentType WRITE setDocumentType NOTIFY documentTypeChanged)
//    Q_PROPERTY(int idAdditionalInfoHumanId READ getIdAdditionalInfoHumanId WRITE setIdAdditionalInfoHumanId NOTIFY idAdditionalInfoHumanIdChanged)
public:
    explicit Document(QObject *parent = nullptr);
    Document(int _idDocument, QString _series, QString _number, QString _issue_place, QDate _issue_date,QString _additional_number,DocumentType* _documentType):
        id(_idDocument), series(_series), number(_number), issuePlace(_issue_place), issueDate(_issue_date),additionalNumber(_additional_number),documentType(_documentType) {}

    int getId() const;
    void setId(int value);

    QString getSeries() const;
    void setSeries(const QString &value);

    QString getNumber() const;
    void setNumber(const QString &value);

    QString getIssuePlace() const;
    void setIssuePlace(const QString &value);

    QDate getIssueDate() const;
    void setIssueDate(const QDate &value);

    QString getAdditionalNumber() const;
    void setAdditionalNumber(const QString &value);

    DocumentType* getDocumentType() const;
    void setDocumentType(DocumentType* value);

    int getIdAdditionalInfoHumanId() const;
    void setIdAdditionalInfoHumanId(int value);

    void Print();
private:
    int id;
    QString series;
    QString number;
    QString issuePlace;
    QDate issueDate;
    QString additionalNumber;
    DocumentType* documentType;
//    int idAdditionalInfoHumanId;

signals:
    void idChanged();
    void seriesChanged();
    void numberChanged();
    void issuePlaceChanged();
    void issueDateChanged();
    void additionalNumberChanged();
    void documentTypeChanged();
//    void idAdditionalInfoHumanIdChanged();
};

#endif // DOCUMENT_H
