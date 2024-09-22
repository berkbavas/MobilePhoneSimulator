#include "ShowContactModeHandler.h"

ShowContactModeHandler::ShowContactModeHandler(QObject *parent)
    : ModeHandler{parent}
{
    mContactDetails.setTitle("Show Contact");

    connect(this, &ModeHandler::activeChanged, this, [=]() {
        if (mActive)
        {
            mContactList->setTitle("Show Contact");
            setCurrentDisplay(DisplayType::ContactList);
        }
        else
        {
            mContactList->reset();
            setCurrentDisplay(DisplayType::None);
        }
    });
}

void ShowContactModeHandler::onAction(Action *action)
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
            mContactDetails.setRow(0, "Name:");
            mContactDetails.setRow(1, mContacts->at(mContactList->currentIndex())->name());
            mContactDetails.setRow(3, "Phone Number:");
            mContactDetails.setRow(4, mContacts->at(mContactList->currentIndex())->phoneNumber());
            setCurrentDisplay(DisplayType::ContactDetails);
            action->setConsumed(true);
            break;
        default:
            break;
        }
        break;
    case DisplayType::ContactDetails:
        switch (action->button())
        {
        case Enums::Button::Clear:
        case Enums::Button::Enter:
            setCurrentDisplay(DisplayType::ContactList);
            action->setConsumed(true);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void ShowContactModeHandler::setCurrentDisplay(DisplayType newDisplay)
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
    case DisplayType::ContactDetails:
        emit activeItemChanged(&mContactDetails);
        break;
    }
}
