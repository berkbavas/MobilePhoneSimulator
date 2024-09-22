#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>

class Contact : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString phoneNumber READ phoneNumber WRITE setPhoneNumber NOTIFY phoneNumberChanged)

public:
    explicit Contact(QObject *parent = nullptr);

    const QString &name() const;
    void setName(const QString &newName);

    const QString &phoneNumber() const;
    void setPhoneNumber(const QString &newPhoneNumber);

signals:
    void nameChanged();
    void phoneNumberChanged();

private:
    QString mName;
    QString mPhoneNumber;
};

#endif // CONTACT_H
