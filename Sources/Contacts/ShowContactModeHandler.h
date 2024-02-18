#ifndef SHOWCONTACTMODEHANDLER_H
#define SHOWCONTACTMODEHANDLER_H

#include "ModeHandler.h"
#include "Display.h"

#include <QObject>

class ShowContactModeHandler : public ModeHandler
{
public:
    explicit ShowContactModeHandler(QObject *parent = nullptr);

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

#endif // SHOWCONTACTMODEHANDLER_H
