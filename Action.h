#ifndef ACTION_H
#define ACTION_H

#include "Enums.h"

class Action
{
public:
    Action(int button, int action);

    Enums::Button button() const;
    Enums::Action action() const;

    bool consumed() const;
    void setConsumed(bool newConsumed);

private:
    Enums::Button mButton;
    Enums::Action mAction;
    bool mConsumed;
};

#endif // ACTION_H
