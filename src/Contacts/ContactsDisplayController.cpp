#include "ContactsDisplayController.h"
#include "Helper.h"

#include <QDebug>

ContactsDisplayController::ContactsDisplayController(QObject *parent)
    : Controller{parent}
    , mActiveModeHandler(nullptr)
{}

void ContactsDisplayController::init()
{
    mContacts = Helper::parseContacts(":/resources/data/contacts.json");
    mContactList = new SimpleMenu;

    updateContactList();

    mCallContactModeHandler = new CallContactModeHandler;
    mModeHandlers.insert(Mode::Call, mCallContactModeHandler);

    mShowContactModeHandler = new ShowContactModeHandler;
    mModeHandlers.insert(Mode::Show, mShowContactModeHandler);

    mAddContactModeHandler = new AddContactModeHandler;
    mModeHandlers.insert(Mode::Add, mAddContactModeHandler);

    mEditContactModeHandler = new EditContactModeHandler;
    mModeHandlers.insert(Mode::Edit, mEditContactModeHandler);

    mDeleteContactModeHandler = new DeleteContactModeHandler;
    mModeHandlers.insert(Mode::Delete, mDeleteContactModeHandler);

    for (auto &modeHandler : mModeHandlers)
    {
        connect(modeHandler, &ModeHandler::activeItemChanged, this, &Controller::activeItemChanged);
        connect(modeHandler, &ModeHandler::requestCreated, this, &Controller::requestCreated);
        connect(modeHandler,
                &ModeHandler::updateContactList,
                this,
                &ContactsDisplayController::updateContactList);
        connect(modeHandler, &ModeHandler::finished, this, [=]() {
            updateContactList();
            mChangeControllerRequest.setStatus(Request::Status::Created);
            mChangeControllerRequest.setControllerName("MainMenuController");
            emit requestCreated(&mChangeControllerRequest);
        });

        modeHandler->setContacts(&mContacts);
        modeHandler->setContactList(mContactList);
        modeHandler->setLineEditor(mLineEditor);
    };

    connect(this, &Controller::activeChanged, this, [=]() {
        qDebug() << mModeHandlers.value((Mode) mMode, nullptr);
        if (mActive)
            setActiveModeHandler(mModeHandlers.value((Mode) mMode, nullptr));
        else
            setActiveModeHandler(nullptr);
    });
}

void ContactsDisplayController::onAction(Action *action)
{
    if (mActiveModeHandler)
        mActiveModeHandler->onAction(action);
}

void ContactsDisplayController::update(quint64 milisecondsElapsed)
{
    if (mActiveModeHandler)
        mActiveModeHandler->update(milisecondsElapsed);
}

void ContactsDisplayController::updateContactList()
{
    mContactList->reset();
    mContactList->clearRows();

    for (int i = 0; i < mContacts.size(); i++)
        mContactList->addRow(mContacts.at(i)->name());
}

void ContactsDisplayController::setActiveModeHandler(ModeHandler *newActiveModeHandler)
{
    if (mActiveModeHandler == newActiveModeHandler)
        return;

    if (mActiveModeHandler)
        mActiveModeHandler->setActive(false);

    if (newActiveModeHandler)
        newActiveModeHandler->setActive(true);

    mActiveModeHandler = newActiveModeHandler;
}
