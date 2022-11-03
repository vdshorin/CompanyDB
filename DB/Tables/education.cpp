#include "education.h"

Education::Education(QObject *parent) : QObject(parent)
{

}

int Education::getId() const
{
    return id;
}

void Education::setId(int value)
{
    id = value;
    emit idChanged();
}

EducationType* Education::getEducationType() const
{
    return educationType;
}

void Education::setEducationType(EducationType* value)
{
    educationType = value;
    emit educationTypeChanged();
}

QString Education::getSpecialization() const
{
    return specialization;
}

void Education::setSpecialization(const QString &value)
{
    specialization = value;
    emit specializationChanged();
}

QDate Education::getDateGraduate() const
{
    return dateGraduate;
}

void Education::setDateGraduate(const QDate &value)
{
    dateGraduate = value;
    emit dateGraduateChanged();
}

double Education::getMark() const
{
    return mark;
}

void Education::setMark(double value)
{
    mark = value;
    emit markChanged();
}

QString Education::getTheme() const
{
    return theme;
}

void Education::setTheme(const QString &value)
{
    theme = value;
    emit themeChanged();
}

QString Education::getUniversityName() const
{
    return universityName;
}

void Education::setUniversityName(const QString &value)
{
    universityName = value;
    emit universityNameChanged();
}

void Education::Print()
{
    qDebug() <<"int id: " << getId();
    educationType->Print();
//    int idAdditionalInfoHumanId;
    qDebug() <<"QDate dateGraduate: " << getDateGraduate().toString();
    qDebug() <<"double mark: " << getMark();
    qDebug() <<"QString specialization: " + getSpecialization();
    qDebug() <<"QString theme: " + getTheme();
    qDebug() <<"QString universityName: " + getUniversityName();
}

//int Education::getIdAdditionalInfoHumanId() const
//{
//    return idAdditionalInfoHumanId;
//}

//void Education::setIdAdditionalInfoHumanId(int value)
//{
//    idAdditionalInfoHumanId = value;
//    emit idAdditionalInfoHumanIdChanged();
//}
