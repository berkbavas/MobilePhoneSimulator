#include "Action.h"

Action::Action(int button, int actionType)
    : mButton((Enums::Button) button)
    , mActionType((Enums::ActionType) actionType)
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

Enums::ActionType Action::actionType() const
{
    return mActionType;
}

void Action::setActionType(Enums::ActionType newActionType)
{
    mActionType = newActionType;
}

bool Action::consumed() const
{
    return mConsumed;
}

void Action::setConsumed(bool newConsumed)
{
    mConsumed = newConsumed;
}
