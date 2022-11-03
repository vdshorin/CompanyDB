#ifndef EDUCATION_H
#define EDUCATION_H

#include "instruments.h"
#include <QObject>
#include "educationtype.h"

class Education : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(EducationType* educationType READ getEducationType WRITE setEducationType NOTIFY educationTypeChanged)
//    Q_PROPERTY(int idAdditionalInfoHumanId READ getIdAdditionalInfoHumanId WRITE setIdAdditionalInfoHumanId NOTIFY idAdditionalInfoHumanIdChanged)
    Q_PROPERTY(QDate dateGraduate READ getDateGraduate WRITE setDateGraduate NOTIFY dateGraduateChanged)
    Q_PROPERTY(double mark READ getMark WRITE setMark NOTIFY markChanged)
    Q_PROPERTY(QString specialization READ getSpecialization WRITE setSpecialization NOTIFY specializationChanged)
    Q_PROPERTY(QString theme READ getTheme WRITE setTheme NOTIFY themeChanged)
    Q_PROPERTY(QString universityName READ getUniversityName WRITE setUniversityName NOTIFY universityNameChanged)


public:
    explicit Education(QObject *parent = nullptr);
    Education(int _id, EducationType* _educationType, QString _specialization, QDate _date_graduate, double _mark, QString _theme, QString _university_name):
        id(_id), educationType(_educationType), specialization(_specialization), dateGraduate(_date_graduate), mark(_mark), theme(_theme), universityName(_university_name) {}

    int getId() const;
    void setId(int value);

    EducationType* getEducationType() const;
    void setEducationType(EducationType* value);

    QString getSpecialization() const;
    void setSpecialization(const QString &value);

    QDate getDateGraduate() const;
    void setDateGraduate(const QDate &value);

    double getMark() const;
    void setMark(double value);

    QString getTheme() const;
    void setTheme(const QString &value);

    QString getUniversityName() const;
    void setUniversityName(const QString &value);

    void Print();

//    int getIdAdditionalInfoHumanId() const;
//    void setIdAdditionalInfoHumanId(int value);

private:
    int id;
    EducationType* educationType;
//    int idAdditionalInfoHumanId;
    QDate dateGraduate;
    double mark;
    QString specialization;
    QString theme;
    QString universityName;

signals:
    void idChanged();
    void educationTypeChanged();
//    void idAdditionalInfoHumanIdChanged();
    void dateGraduateChanged();
    void markChanged();
    void specializationChanged();
    void themeChanged();
    void universityNameChanged();

};

#endif // EDUCATION_H
