#ifndef HELPER_H
#define HELPER_H

#include "Menu.h"
#include "Contacts/Contact.h"

#include <QObject>

class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = nullptr);
    static Menu *parseMenus(const QString &path);
    static QList<Contact *> parseContacts(const QString &path);

private:
    static bool parseJson(const QString &path, QJsonDocument &doc);
    static Menu *parseMenus(QJsonObject object, Menu *parent, int index);
};

#endif // HELPER_H
