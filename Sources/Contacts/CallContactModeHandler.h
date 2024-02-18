#ifndef CALLCONTACTMODEHANDLER_H
#define CALLCONTACTMODEHANDLER_H

#include "ModeHandler.h"
#include "Display.h"

#include <QObject>

class CallContactModeHandler : public ModeHandler
{
public:
    explicit CallContactModeHandler(QObject *parent = nullptr);

    virtual void onAction(Action *action) override;

private:
    enum class DisplayType { //
        None,
        ContactList,
        ContactDetails
    };

    void setCurrentDisplay(DisplayType newDisplay);

private:
    Display mContactDetails;
    DisplayType mCurrentDisplay;
};

#endif // CALLCONTACTMODEHANDLER_H
