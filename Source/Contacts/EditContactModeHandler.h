#ifndef EDITCONTACTMODEHANDLER_H
#define EDITCONTACTMODEHANDLER_H

#include "ModeHandler.h"
#include "Display.h"

#include <QObject>

class EditContactModeHandler : public ModeHandler
{
public:
    explicit EditContactModeHandler(QObject *parent = nullptr);
    virtual void onAction(Action *action) override;
    virtual void update(quint64 milisecondsElapsed) override;

private:
    enum class DisplayType { //
        None,
        ContactList,
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

#endif // EDITCONTACTMODEHANDLER_H
