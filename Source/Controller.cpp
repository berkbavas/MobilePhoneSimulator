#include "Controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
    , mActive(false)
{}

void Controller::init() {}

void Controller::onAction(Action *action) {}

void Controller::update(quint64) {}

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

void Controller::setLineEditor(LineEditor *newLineEditor)
{
    mLineEditor = newLineEditor;
}
