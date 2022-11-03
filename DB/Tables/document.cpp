#include "document.h"

Document::Document(QObject *parent) : QObject(parent)
{

}

int Document::getId() const
{
    return id;
}

void Document::setId(int value)
{
    id = value;
    emit idChanged();
}

QString Document::getSeries() const
{
    return series;
}

void Document::setSeries(const QString &value)
{
    series = value;
    emit seriesChanged();
}

QString Document::getNumber() const
{
    return number;
}

void Document::setNumber(const QString &value)
{
    number = value;
    emit numberChanged();
}

QString Document::getIssuePlace() const
{
    return issuePlace;
}

void Document::setIssuePlace(const QString &value)
{
    issuePlace = value;
    emit issuePlaceChanged();
}

QDate Document::getIssueDate() const
{
    return issueDate;
}

void Document::setIssueDate(const QDate &value)
{
    issueDate = value;
    emit issueDateChanged();
}

QString Document::getAdditionalNumber() const
{
    return additionalNumber;
}

void Document::setAdditionalNumber(const QString &value)
{
    additionalNumber = value;
    emit additionalNumberChanged();
}

DocumentType* Document::getDocumentType() const
{
    return documentType;
}

void Document::setDocumentType(DocumentType* value)
{
    documentType = value;
    emit documentTypeChanged();
}

void Document::Print()
{
    qDebug() <<"int id:" << getId();
    qDebug() <<"QString series:" << getSeries();
    qDebug() <<"QString number: " << getNumber();
    qDebug() <<"QString issuePlace: " << getIssuePlace();
    qDebug() <<"QDate issueDate: " + getIssueDate().toString();
    qDebug() <<"QString additionalNumber: " + getAdditionalNumber();
    getDocumentType()->Print();
}

//int Document::getIdAdditionalInfoHumanId() const
//{
//    return idAdditionalInfoHumanId;
//}

//void Document::setIdAdditionalInfoHumanId(int value)
//{
//    idAdditionalInfoHumanId = value;
//    emit idAdditionalInfoHumanIdChanged();
//}
