#include "Action.h"

Action::Action(int button, int action)
    : mButton((Enums::Button) button)
    , mAction((Enums::Action) action)
    , mConsumed(false)
{}

Enums::Button Action::button() const
{
    return mButton;
}

void Action::setButton(Enums::Button newButton)
{
    mButton = newButton;
}

Enums::Action Action::action() const
{
    return mAction;
}

void Action::setAction(Enums::Action newAction)
{
    mAction = newAction;
}

bool Action::consumed() const
{
    return mConsumed;
}

void Action::setConsumed(bool newConsumed)
{
    mConsumed = newConsumed;
}
