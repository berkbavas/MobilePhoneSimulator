#ifndef CONTACTSDISPLAYCONTROLLER_H
#define CONTACTSDISPLAYCONTROLLER_H

#include "AddContactModeHandler.h"
#include "CallContactModeHandler.h"
#include "Contact.h"
#include "Controller.h"
#include "DeleteContactModeHandler.h"
#include "EditContactModeHandler.h"
#include "ModeHandler.h"
#include "ShowContactModeHandler.h"
#include "SimpleMenu.h"
#include "ChangeControllerRequest.h"

#include <QMap>
#include <QStack>

class ContactsDisplayController : public Controller
{
public:
    enum class Mode : int { //
        Call,
        Show,
        Add,
        Edit,
        Delete
    };

    explicit ContactsDisplayController(QObject *parent = nullptr);

    virtual void init() override;
    virtual void onAction(Action *action) override;
    virtual void update(quint64 milisecondsElapsed) override;

private slots:
    void updateContactList();
    void setActiveModeHandler(ModeHandler *newActiveModeHandler);

private:
    QMap<Mode, ModeHandler *> mModeHandlers;
    ModeHandler *mActiveModeHandler;
    CallContactModeHandler *mCallContactModeHandler;
    ShowContactModeHandler *mShowContactModeHandler;
    AddContactModeHandler *mAddContactModeHandler;
    EditContactModeHandler *mEditContactModeHandler;
    DeleteContactModeHandler *mDeleteContactModeHandler;

    QList<Contact *> mContacts;
    SimpleMenu *mContactList;

    ChangeControllerRequest mChangeControllerRequest;
};

#endif // CONTACTSDISPLAYCONTROLLER_H
