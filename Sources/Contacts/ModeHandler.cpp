#include "ModeHandler.h"

ModeHandler::ModeHandler(QObject *parent)
    : QObject{parent}
    , mContactList(nullptr)
    , mLineEditor(nullptr)
    , mActive(false)
{}

void ModeHandler::update(quint64 milisecondsElapsed) {}

bool ModeHandler::active() const
{
    return mActive;
}

void ModeHandler::setActive(bool newActive)
{
    if (mActive == newActive)
        return;
    mActive = newActive;
    emit activeChanged();
}

void ModeHandler::setLineEditor(LineEditor *newLineEditor)
{
    mLineEditor = newLineEditor;
}

void ModeHandler::setContacts(QList<Contact *> *newContacts)
{
    mContacts = newContacts;
}

void ModeHandler::setContactList(SimpleMenu *newContactList)
{
    mContactList = newContactList;
}
