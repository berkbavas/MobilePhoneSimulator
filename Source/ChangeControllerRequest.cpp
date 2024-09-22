#include "ChangeControllerRequest.h"

ChangeControllerRequest::ChangeControllerRequest(QObject *parent)
    : Request(parent)
{}

const QString &ChangeControllerRequest::controllerName() const
{
    return mControllerName;
}

void ChangeControllerRequest::setControllerName(const QString &newControllerName)
{
    mControllerName = newControllerName;
}

int ChangeControllerRequest::controllerMode() const
{
    return mControllerMode;
}

void ChangeControllerRequest::setControllerMode(int newControllerMode)
{
    mControllerMode = newControllerMode;
}
