#include "Controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
    , mActive(false)
{}

int Controller::mode() const
{
    return mMode;
}

void Controller::setMode(int newMode)
{
    if (mMode == newMode)
        return;
    mMode = newMode;
    emit modeChanged();
}

bool Controller::active() const
{
    return mActive;
}

void Controller::setActive(bool newActive)
{
    if (mActive == newActive)
        return;
    mActive = newActive;
    emit activeChanged();
}
