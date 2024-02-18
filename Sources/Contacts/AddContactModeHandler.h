#ifndef ADDCONTACTMODEHANDLER_H
#define ADDCONTACTMODEHANDLER_H

#include "ModeHandler.h"
#include "Display.h"

#include <QObject>

class AddContactModeHandler : public ModeHandler
{
public:
    explicit AddContactModeHandler(QObject *parent = nullptr);

    virtual void onAction(Action *action) override;
    virtual void update(quint64 milisecondsElapsed) override;

private:
    enum class DisplayType { //
        None,
        Menu,
        Edit,
        Saved,
    };

    void setCurrentDisplay(DisplayType newDisplay);

private:
    SimpleMenu mMenu;
    Display mEditDisplay;
    Display mSavedDisplay;

    DisplayType mCurrentDisplay;

    QString mName;
    QString mNumber;

    quint64 mElapsedTime;
};

#endif // ADDCONTACTMODEHANDLER_H
