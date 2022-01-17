#ifndef ACTION_H
#define ACTION_H

#include "Enums.h"

class Action
{
public:
    Action(int button, int actionType);

    Enums::Button button() const;
    void setButton(Enums::Button newButton);

    Enums::ActionType actionType() const;
    void setActionType(Enums::ActionType newActionType);

    bool consumed() const;
    void setConsumed(bool newConsumed);

private:
    Enums::Button mButton;
    Enums::ActionType mActionType;
    bool mConsumed;
};

#endif // ACTION_H
