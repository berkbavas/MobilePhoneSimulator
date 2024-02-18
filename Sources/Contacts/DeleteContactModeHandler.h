#ifndef DELETECONTACTMODEHANDLER_H
#define DELETECONTACTMODEHANDLER_H

#include "ModeHandler.h"
#include "Display.h"

#include <QObject>

class DeleteContactModeHandler : public ModeHandler
{
public:
    explicit DeleteContactModeHandler(QObject *parent = nullptr);

    virtual void onAction(Action *action) override;
    virtual void update(quint64 milisecondsElapsed) override;

private:
    enum class DisplayType { //
        None,
        ContactList,
        ConfirmationDisplay,
        ContactDeletedDisplay
    };

    void setCurrentDisplay(DisplayType newDisplay);

private:
    Display mConfirmationDisplay;
    Display mContactDeletedDisplay;

    DisplayType mCurrentDisplay;
    quint64 mElapsedTime;
};

#endif // DELETECONTACTMODEHANDLER_H
