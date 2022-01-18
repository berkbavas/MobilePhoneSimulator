#include "ContactsDisplayController.h"
#include "Helper.h"

ContactsDisplayController::ContactsDisplayController(QObject *parent)
    : Controller{parent}
{
    mContacts = Helper::parseContacts(":/Data/Contacts.json");

    for (int i = 0; i < mContacts.size(); i++) {
        mContactsList.addRow(mContacts.at(i)->name());
    }

    connect(this, &Controller::activeChanged, this, [=]() {
        if (mActive) {
            mContactsList.reset();
            mCurrentDisplay = DisplayType::List;
            mContactsList.setTitle(getTitle());
            mContactDetails.setTitle(getTitle());
            emit activeItemChanged(&mContactsList);
        }
    });
}

void ContactsDisplayController::onAction(Action *action)
{
    switch (action->button()) {
    case Enums::Button::Clear:
        if (mVisitedDisplays.isEmpty()) {
        } else if (mVisitedDisplays.pop() == DisplayType::List) {
            mCurrentDisplay = DisplayType::List;
            emit activeItemChanged(&mContactsList);
            action->setConsumed(true);
        }
        break;
    case Enums::Button::Space:
        if (mCurrentDisplay == DisplayType::List) {
            mVisitedDisplays << DisplayType::List;
            mCurrentDisplay = DisplayType::Details;
            mContactDetails.setRow0("Name: ");
            mContactDetails.setRow1(mContacts.at(mContactsList.currentIndex())->name());
            mContactDetails.setRow3("Phone Number:");
            mContactDetails.setRow4(mContacts.at(mContactsList.currentIndex())->phoneNumber());
            emit activeItemChanged(&mContactDetails);

            action->setConsumed(true);
        } else {
            action->setConsumed(true);
        }
        break;
    case Enums::Button::Up:
        if (mCurrentDisplay == DisplayType::List) {
            mContactsList.decrement();
            action->setConsumed(true);
        }
        break;
    case Enums::Button::Down:
        if (mCurrentDisplay == DisplayType::List) {
            mContactsList.increment();
            action->setConsumed(true);
        }
        break;
    default:
        break;
    }
}

QString ContactsDisplayController::getTitle()
{
    switch ((Mode) mMode) {
    case ContactsDisplayController::Mode::Show:
        return "Show Contact";
    case ContactsDisplayController::Mode::Call:
        return "Call Contact";
    case ContactsDisplayController::Mode::Add:
        return "Add Contact";
    case ContactsDisplayController::Mode::Edit:
        return "Edit Contact";
    case ContactsDisplayController::Mode::Delete:
        return "Delete Contact";
    default:
        return " ";
    }
}
