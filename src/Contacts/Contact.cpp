#include "Contact.h"

Contact::Contact(QObject *parent)
    : QObject{parent}
{}

const QString &Contact::name() const
{
    return mName;
}

void Contact::setName(const QString &newName)
{
    if (mName == newName)
        return;
    mName = newName;
    emit nameChanged();
}

const QString &Contact::phoneNumber() const
{
    return mPhoneNumber;
}

void Contact::setPhoneNumber(const QString &newPhoneNumber)
{
    if (mPhoneNumber == newPhoneNumber)
        return;
    mPhoneNumber = newPhoneNumber;
    emit phoneNumberChanged();
}
