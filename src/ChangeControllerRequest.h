#ifndef CHANGECONTROLLERREQUEST_H
#define CHANGECONTROLLERREQUEST_H

#include "Request.h"

class ChangeControllerRequest : public Request
{
public:
    explicit ChangeControllerRequest(QObject *parent = nullptr);

    const QString &controllerName() const;
    void setControllerName(const QString &newControllerName);

    int controllerMode() const;
    void setControllerMode(int newControllerMode);

private:
    QString mControllerName;
    int mControllerMode;
};

#endif // CHANGECONTROLLERREQUEST_H
