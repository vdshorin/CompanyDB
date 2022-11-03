#ifndef RELATIVES_H
#define RELATIVES_H

#include <QObject>

class relatives : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int idHuman READ getIdHuman WRITE setIdHuman NOTIFY idHumanChanged);
    Q_PROPERTY(int idRelative READ getIdRelative WRITE setIdRelative NOTIFY idRelativeChanged);
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY typeChanged);
public:
    explicit relatives(QObject *parent = nullptr);

    QString getType() const;
    void setType(const QString &value);

    int getIdHuman() const;
    void setIdHuman(int value);

    int getIdRelative() const;
    void setIdRelative(int value);

private:
    int idHuman;
    int idRelative;
    QString type;

signals:
    void idHumanChanged();
    void idRelativeChanged();
    void typeChanged();
};

#endif // RELATIVES_H
