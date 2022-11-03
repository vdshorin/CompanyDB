#ifndef HUMANHASADDRESS_H
#define HUMANHASADDRESS_H

#include <QObject>

class humanHasAddress : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int idHuman READ getIdHuman WRITE setIdHuman NOTIFY idHumanChanged)
    Q_PROPERTY(int idAddress READ getIdAddress WRITE setIdAddress NOTIFY idAddressChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY typeChanged)
public:
    explicit humanHasAddress(QObject *parent = nullptr);

    int getIdHuman() const;
    void setIdHuman(int value);

    int getIdAddress() const;
    void setIdAddress(int value);

    QString getType() const;
    void setType(const QString &value);

private:
    int idHuman;
    int idAddress;
    QString type;

signals:
    void idHumanChanged();
    void idAddressChanged();
    void typeChanged();
};

#endif // HUMANHASADDRESS_H
