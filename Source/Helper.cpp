#include "Helper.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

Helper::Helper(QObject *parent)
    : QObject{parent}
{}

Menu *Helper::parseMenus(const QString &path)
{
    QJsonDocument doc;

    if (parseJson(path, doc))
    {
        Menu *mainMenu = new Menu;
        QJsonObject json = doc.object();

        json["title"].isNull() ? mainMenu->setTitle("Main Menu")
                               : mainMenu->setTitle(json["title"].toString());
        json["controllerName"].isNull()
            ? mainMenu->setControllerName("DefaultController")
            : mainMenu->setControllerName(json["controllerName"].toString());
        json["controllerMode"].isNull()
            ? mainMenu->setControllerMode(-1)
            : mainMenu->setControllerMode(json["controllerMode"].toInt());

        QJsonArray children = json["children"].toArray();

        for (int i = 0; i < children.size(); i++)
        {
            Menu *child = parseMenus(children[i].toObject(), mainMenu, i);
            mainMenu->addChild(child);
        }

        return mainMenu;
    }

    return nullptr;
}

QList<Contact *> Helper::parseContacts(const QString &path)
{
    QJsonDocument doc;
    QList<Contact *> contacts;

    if (parseJson(path, doc))
    {
        QJsonArray array = doc.array();
        for (int i = 0; i < array.size(); i++)
        {
            Contact *contact = new Contact;
            QJsonObject object = array.at(i).toObject();
            object["name"].isNull() ? contact->setName("null")
                                    : contact->setName(object["name"].toString());
            object["phoneNumber"].isNull()
                ? contact->setPhoneNumber("null")
                : contact->setPhoneNumber(object["phoneNumber"].toString());
            contacts << contact;
        }
    }

    return contacts;
}

bool Helper::parseJson(const QString &path, QJsonDocument &doc)
{
    QFile file(path);
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray rawData = file.readAll();
        doc = QJsonDocument::fromJson(rawData);

        if (doc.isNull())
        {
            qCritical() << "Could not parse JSON file.";
            return false;
        }

        return true;
    }

    qCritical() << "Could not open JSON file.";
    return false;
}

Menu *Helper::parseMenus(QJsonObject object, Menu *parent, int index)
{
    Menu *menu = new Menu;

    object["name"].isNull() ? menu->setName("null") : menu->setName(object["name"].toString());
    object["title"].isNull() ? menu->setTitle(menu->name())
                             : menu->setTitle(object["title"].toString());
    object["namePrefix"].isNull() ? menu->setNamePrefix(QString::number(index + 1))
                                  : menu->setNamePrefix(object["namePrefix"].toString());
    parent->id().isEmpty() ? menu->setId(QString::number(index + 1))
                           : menu->setId(parent->id() + "." + QString::number(index + 1));
    object["controllerName"].isNull()
        ? menu->setControllerName(parent->controllerName())
        : menu->setControllerName(object["controllerName"].toString());
    object["controllerMode"].isNull() ? menu->setControllerMode(-1)
                                      : menu->setControllerMode(object["controllerMode"].toInt());

    QJsonArray children = object["children"].toArray();

    for (int i = 0; i < children.size(); i++)
    {
        Menu *child = parseMenus(children[i].toObject(), menu, i);
        menu->addChild(child);
    }

    return menu;
}
