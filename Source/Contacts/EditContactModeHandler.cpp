#include "EditContactModeHandler.h"

EditContactModeHandler::EditContactModeHandler(QObject *parent)
    : ModeHandler{parent}
{
    mMenu.setTitle("Edit Contact");

    mEditDisplay.setTitle("Edit Contact");
    mSavedDisplay.setTitle("Edit Contact");

    mSavedDisplay.setRow(3, "Contact is saved", Display::Alignment::Center);

    connect(this, &ModeHandler::activeChanged, this, [=]() {
        if (mActive)
        {
            mContactList->setTitle("Edit Contact");
            mMenu.reset();
            mMenu.clearRows();
            mName.clear();
            mNumber.clear();
            setCurrentDisplay(DisplayType::ContactList);
        }
        else
        {
            mContactList->reset();
            setCurrentDisplay(DisplayType::None);
        }
    });
}

void EditContactModeHandler::onAction(Action *action)
{
    if (mCurrentDisplay == DisplayType::Edit)
        mLineEditor->onAction(action);

    if (action->consumed())
        return;

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
            mName = mContacts->at(mContactList->currentIndex())->name();
            mNumber = mContacts->at(mContactList->currentIndex())->phoneNumber();
            mMenu.setRow(0, "Name: " + mName);
            mMenu.setRow(1, "Number: " + mNumber);
            mMenu.setRow(2, "Save Contact");
            setCurrentDisplay(DisplayType::Menu);
            action->setConsumed(true);
            break;
        default:
            break;
        }
        break;
    case DisplayType::Menu:
        switch (action->button())
        {
        case Enums::Button::Clear:
            setCurrentDisplay(DisplayType::ContactList);
            break;
        case Enums::Button::Enter:
            if (mMenu.currentIndex() == 0)
            {
                mEditDisplay.clearRows();
                mEditDisplay.setRow(0, "Name:");
                mEditDisplay.setRow(1, mName);
                mLineEditor->reset();
                mLineEditor->setLine(mName);
                mLineEditor->setCharacterLimit(15);
                mLineEditor->setEditMode(LineEditor::EditMode::All);
                setCurrentDisplay(DisplayType::Edit);
            }
            else if (mMenu.currentIndex() == 1)
            {
                mEditDisplay.clearRows();
                mEditDisplay.setRow(0, "Number:");
                mEditDisplay.setRow(1, mNumber);
                mLineEditor->reset();
                mLineEditor->setLine(mNumber);
                mLineEditor->setCharacterLimit(11);
                mLineEditor->setEditMode(LineEditor::EditMode::OnlyNumbers);
                setCurrentDisplay(DisplayType::Edit);
            }
            else if (mMenu.currentIndex() == 2)
            {
                if (!mName.isEmpty() && !mNumber.isEmpty())
                {
                    Contact *contact = mContacts->at(mContactList->currentIndex());
                    contact->setName(mName);
                    contact->setPhoneNumber(mNumber);
                    mElapsedTime = 0;
                    setCurrentDisplay(DisplayType::Saved);
                }
            }
            action->setConsumed(true);
            break;
        case Enums::Button::Up:
            mMenu.decrement();
            action->setConsumed(true);
            break;
        case Enums::Button::Down:
            mMenu.increment();
            action->setConsumed(true);
            break;
        default:
            break;
        }
        break;
    case DisplayType::Edit:
        switch (action->button())
        {
        case Enums::Button::Clear:
            setCurrentDisplay(DisplayType::Menu);
            action->setConsumed(true);
            break;
        case Enums::Button::Enter:
            if (mMenu.currentIndex() == 0)
            {
                if (!mLineEditor->line().isEmpty())
                    mMenu.increment();
                mName = mLineEditor->line();
                mMenu.setRow(0, "Name " + mName);
                setCurrentDisplay(DisplayType::Menu);
                action->setConsumed(true);
            }
            else if (mMenu.currentIndex() == 1)
            {
                if (!mLineEditor->line().isEmpty())
                    mMenu.increment();
                mNumber = mLineEditor->line();
                mMenu.setRow(1, "Number " + mNumber);
                setCurrentDisplay(DisplayType::Menu);
                action->setConsumed(true);
            }
        default:
            break;
        }
    case DisplayType::Saved:
        action->setConsumed(true);
        break;
    default:
        break;
    }
}

void EditContactModeHandler::update(quint64 milisecondsElapsed)
{
    switch (mCurrentDisplay)
    {
    case DisplayType::Saved:
        if (mElapsedTime > 2000)
            emit finished();
        break;
    case DisplayType::Edit:
    {
        mEditDisplay.setRow(1, mLineEditor->getVisualLine());
        mEditDisplay.setRow(6,
                            mLineEditor->getHint(),
                            QString::number(mLineEditor->getNumberOfRemainingCharacters()));
        break;
    }
    default:
        break;
    }

    mElapsedTime += milisecondsElapsed;
}

void EditContactModeHandler::setCurrentDisplay(DisplayType newDisplay)
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
    case DisplayType::Menu:
        emit activeItemChanged(&mMenu);
        break;
    case DisplayType::Edit:
        emit activeItemChanged(&mEditDisplay);
        break;
    case DisplayType::Saved:
        emit activeItemChanged(&mSavedDisplay);
        break;
    }
}
