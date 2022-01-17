#include "ContactsController.h"
#include "Helper.h"

ContactsController::ContactsController(QObject *parent)
    : Controller{parent}
    , mCurrentDisplay(-1)
{
    connect(this, &Controller::activeChanged, this, [=]() {
        if (mActive) {
            mScrollHandler->reset();
            setCurrentDisplay((int) Display::List);
        }
    });
}

void ContactsController::init()
{
    mScrollHandler = new ScrollHandler;
    mContacts = Helper::parseContacts(":/Data/Contacts.json");
    mScrollHandler->setMenuSize(mContacts.size());
}

void ContactsController::onAction(Action *action)
{
    switch (action->button()) {
    case Enums::Button::Zero:
        break;
    case Enums::Button::One:
        break;
    case Enums::Button::Two:
        break;
    case Enums::Button::Three:
        break;
    case Enums::Button::Four:
        break;
    case Enums::Button::Five:
        break;
    case Enums::Button::Six:
        break;
    case Enums::Button::Seven:
        break;
    case Enums::Button::Eight:
        break;
    case Enums::Button::Nine:
        break;
    case Enums::Button::Star:
        break;
    case Enums::Button::Square:
        break;
    case Enums::Button::Clear:
        if (!mVisitedDisplays.isEmpty()) {
            setCurrentDisplay((int) mVisitedDisplays.pop());
            action->setConsumed(true);
        }
        break;
    case Enums::Button::Space:
        if (mMode == (int) Mode::Show) {
            if (mCurrentDisplay == (int) Display::List) {
                mVisitedDisplays << Display::List;
                setCurrentDisplay((int) Display::Show);
            }

        } else if (mMode == (int) Mode::Call) {
            if (mCurrentDisplay == (int) Display::List) {
                mVisitedDisplays << Display::List;
                setCurrentDisplay((int) Display::Call);
            }
        } else if (mMode == (int) Mode::Add) {
            if (mCurrentDisplay == (int) Display::List) {
                mVisitedDisplays << Display::List;
                setCurrentDisplay((int) Display::Add);
            }
        } else if (mMode == (int) Mode::Edit) {
            if (mCurrentDisplay == (int) Display::List) {
                mVisitedDisplays << Display::List;
                setCurrentDisplay((int) Display::Edit);
            }
        } else if (mMode == (int) Mode::Delete) {
            if (mCurrentDisplay == (int) Display::List) {
                mVisitedDisplays << Display::List;
                setCurrentDisplay((int) Display::Delete);
            }
        }

        action->setConsumed(true);
        break;
    case Enums::Button::Up:
        if (mCurrentDisplay == (int) Display::List)
            mScrollHandler->decrement();
        break;
    case Enums::Button::Down:
        if (mCurrentDisplay == (int) Display::List)
            mScrollHandler->increment();
        break;
    }
}

int ContactsController::currentDisplay() const
{
    return mCurrentDisplay;
}

void ContactsController::setCurrentDisplay(int newCurrentDisplay)
{
    if (mCurrentDisplay == newCurrentDisplay)
        return;

    mCurrentDisplay = newCurrentDisplay;
    emit currentDisplayChanged();
}

ScrollHandler *ContactsController::scrollHandler() const
{
    return mScrollHandler;
}

void ContactsController::setScrollHandler(ScrollHandler *newScrollHandler)
{
    if (mScrollHandler == newScrollHandler)
        return;
    mScrollHandler = newScrollHandler;
    emit scrollHandlerChanged();
}

const QList<Contact *> &ContactsController::contacts() const
{
    return mContacts;
}

void ContactsController::setContacts(const QList<Contact *> &newContacts)
{
    if (mContacts == newContacts)
        return;
    mContacts = newContacts;
    emit contactsChanged();
}
