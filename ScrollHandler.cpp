#include "ScrollHandler.h"

ScrollHandler::ScrollHandler(QObject *parent)
    : QObject{parent}
    , mMenuSize(0)
    , mCurrentIndex(0)
    , mFirstVisibleIndex(0)
    , mLastVisibleIndex(5)
{}

bool ScrollHandler::increment()
{
    if (mCurrentIndex < mMenuSize - 1) {
        setCurrentIndex(mCurrentIndex + 1);
        update();
        return true;
    }

    return false;
}

bool ScrollHandler::decrement()
{
    if (0 < mCurrentIndex) {
        setCurrentIndex(mCurrentIndex - 1);
        update();
        return true;
    }

    return false;
}

void ScrollHandler::reset()
{
    setCurrentIndex(0);
    setFirstVisibleIndex(0);
    setLastVisibleIndex(5);
}

void ScrollHandler::update()
{
    while (mLastVisibleIndex < mCurrentIndex) {
        setFirstVisibleIndex(mFirstVisibleIndex + 1);
        setLastVisibleIndex(mLastVisibleIndex + 1);
    }

    while (mCurrentIndex < mFirstVisibleIndex) {
        setFirstVisibleIndex(mFirstVisibleIndex - 1);
        setLastVisibleIndex(mLastVisibleIndex - 1);
    }
}

int ScrollHandler::menuSize() const
{
    return mMenuSize;
}

void ScrollHandler::setMenuSize(int newMenuSize)
{
    if (mMenuSize == newMenuSize)
        return;
    mMenuSize = newMenuSize;
    emit menuSizeChanged();
}

int ScrollHandler::currentIndex() const
{
    return mCurrentIndex;
}

void ScrollHandler::setCurrentIndex(int newCurrentIndex)
{
    if (mCurrentIndex == newCurrentIndex)
        return;
    mCurrentIndex = newCurrentIndex;
    emit currentIndexChanged();
}

int ScrollHandler::firstVisibleIndex() const
{
    return mFirstVisibleIndex;
}

void ScrollHandler::setFirstVisibleIndex(int newFirstVisibleIndex)
{
    if (mFirstVisibleIndex == newFirstVisibleIndex)
        return;
    mFirstVisibleIndex = newFirstVisibleIndex;
    emit firstVisibleIndexChanged();
}

int ScrollHandler::lastVisibleIndex() const
{
    return mLastVisibleIndex;
}

void ScrollHandler::setLastVisibleIndex(int newLastVisibleIndex)
{
    if (mLastVisibleIndex == newLastVisibleIndex)
        return;
    mLastVisibleIndex = newLastVisibleIndex;
    emit lastVisibleIndexChanged();
}
