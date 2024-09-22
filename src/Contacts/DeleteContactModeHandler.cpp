#include "DeleteContactModeHandler.h"

DeleteContactModeHandler::DeleteContactModeHandler(QObject *parent)
    : ModeHandler{parent}
{
    mConfirmationDisplay.setTitle("Delete Contact");
    mConfirmationDisplay.setRow(3, "Do you want to delete");
    mConfirmationDisplay.setRow(4, "this contact?");
    mConfirmationDisplay.setRow(6, "Cancel   Delete");

    mContactDeletedDisplay.setTitle("Delete Contact");
    mContactDeletedDisplay.setRow(3, "Contact is deleted", Display::Alignment::Center);

    connect(this, &ModeHandler::activeChanged, this, [=]() {
        if (mActive)
        {
            mContactList->setTitle("Delete Contact");
            setCurrentDisplay(DisplayType::ContactList);
        }
        else
        {
            mContactList->reset();
            setCurrentDisplay(DisplayType::None);
        }
    });
}

void DeleteContactModeHandler::onAction(Action *action)
{
    switch (mCurrentDisplay)
    {
    case DisplayType::ContactList:
        switch (action->button())
        {
        case Enums::Button::Clear:
            emit finished();
            action->setConsumed(true);
            break;
        case Enums::Button::Up:
            mContactList->decrement();
            action->setConsumed(true);
            break;
        case Enums::Button::Down:
            mContactList->increment();
            action->setConsumed(true);
            break;
        case Enums::Button::Enter:
            mConfirmationDisplay.setRow(0,
                                        "Name: "
                                            + mContacts->at(mContactList->currentIndex())->name());
            mConfirmationDisplay
                .setRow(1, "Number: " + mContacts->at(mContactList->currentIndex())->phoneNumber());
            setCurrentDisplay(DisplayType::ConfirmationDisplay);
            action->setConsumed(true);
            break;
        default:
            break;
        }
        break;
    case DisplayType::ConfirmationDisplay:
        switch (action->button())
        {
        case Enums::Button::Clear:
            setCurrentDisplay(DisplayType::ContactList);
            action->setConsumed(true);
        case Enums::Button::Enter:
            if (!mContacts->isEmpty())
            {
                Contact *contact = mContacts->at(mContactList->currentIndex());
                contact->deleteLater();
                mContacts->removeAt(mContactList->currentIndex());
                mElapsedTime = 0;
                setCurrentDisplay(DisplayType::ContactDeletedDisplay);
                action->setConsumed(true);
            }
            break;
        default:
            break;
        }
        break;
    case DisplayType::ContactDeletedDisplay:
        action->setConsumed(true);
        break;
    default:
        break;
    }
}

void DeleteContactModeHandler::update(quint64 milisecondsElapsed)
{
    switch (mCurrentDisplay)
    {
    case DisplayType::ContactDeletedDisplay:
        if (mElapsedTime > 2000)
        {
            mElapsedTime = 0;
            emit updateContactList();

            if (mContacts->isEmpty())
                emit finished();
            else
                setCurrentDisplay(DisplayType::ContactList);
        }
        break;

    default:
        break;
    }

    mElapsedTime += milisecondsElapsed;
}

void DeleteContactModeHandler::setCurrentDisplay(DisplayType newDisplay)
{
    mCurrentDisplay = newDisplay;

    switch (mCurrentDisplay)
    {
    case DisplayType::None:
        emit activeItemChanged(nullptr);
        break;
    case DisplayType::ContactList:
        emit activeItemChanged(mContactList);
        break;
    case DisplayType::ConfirmationDisplay:
        emit activeItemChanged(&mConfirmationDisplay);
        break;
    case DisplayType::ContactDeletedDisplay:
        emit activeItemChanged(&mContactDeletedDisplay);
        break;
    }
}
