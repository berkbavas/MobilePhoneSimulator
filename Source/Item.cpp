#include "Item.h"

Item::Item(QObject *parent)
    : QObject{parent}
{}

int Item::type() const
{
    return mType;
}

void Item::setType(int newType)
{
    if (mType == newType)
        return;
    mType = newType;
    emit typeChanged();
}
