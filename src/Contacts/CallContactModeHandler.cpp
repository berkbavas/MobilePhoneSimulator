#include "CallContactModeHandler.h"

CallContactModeHandler::CallContactModeHandler(QObject *parent)
    : ModeHandler{parent}
{
    mContactDetails.setTitle("Call Contact");

    connect(this, &ModeHandler::activeChanged, this, [=]() {
        if (mActive)
        {
            mContactList->setTitle("Call Contact");
            setCurrentDisplay(DisplayType::ContactList);
        }
        else
        {
            mContactList->reset();
            setCurrentDisplay(DisplayType::None);
        }
    });
}

void CallContactModeHandler::onAction(Action *action)
{
    switch (mCurrentDisplay)
    {
    case CallContactModeHandler::DisplayType::ContactList:
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
    case CallContactModeHandler::DisplayType::ContactDetails:
        switch (action->button())
        {
        case Enums::Button::Clear:
        case Enums::Button::Enter:
            emit finished(); // TODO
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

void CallContactModeHandler::setCurrentDisplay(DisplayType newDisplay)
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
