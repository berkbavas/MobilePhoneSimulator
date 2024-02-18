#include "Request.h"

Request::Request(QObject *parent)
    : QObject(parent)
    , mStatus(Request::Status::Created)
{}

Request::Status Request::status() const
{
    return mStatus;
}

void Request::setStatus(Status newStatus)
{
    mStatus = newStatus;
}
