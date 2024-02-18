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

Enums::Action Action::action() const
{
    return mAction;
}

bool Action::consumed() const
{
    return mConsumed;
}

void Action::setConsumed(bool newConsumed)
{
    mConsumed = newConsumed;
}
