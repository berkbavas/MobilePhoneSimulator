#ifndef ACTION_H
#define ACTION_H

#include "Enums.h"

class Action
{
public:
    Action(int button, int action);

    Enums::Button button() const;
    void setButton(Enums::Button newButton);

    Enums::Action action() const;
    void setAction(Enums::Action newAction);

    bool consumed() const;
    void setConsumed(bool newConsumed);

private:
    Enums::Button mButton;
    Enums::Action mAction;
    bool mConsumed;
};

#endif // ACTION_H
