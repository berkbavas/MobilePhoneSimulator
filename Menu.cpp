#include "Menu.h"

Menu::Menu(QObject *parent)
    : QObject{parent}
    , mScrollHandler(nullptr)
    , mName()
    , mNamePrefix()
    , mTitle()
    , mId()
{
    mScrollHandler = new ScrollHandler;
}

bool Menu::increment()
{
    return mScrollHandler->increment();
}

bool Menu::decrement()
{
    return mScrollHandler->decrement();
}

void Menu::reset()
{
    mScrollHandler->reset();
}

Menu *Menu::selected()
{
    return mChildren.at(mScrollHandler->currentIndex());
}

int Menu::controllerMode() const
{
    return mControllerMode;
}

void Menu::setControllerMode(int newControllerMode)
{
    if (mControllerMode == newControllerMode)
        return;
    mControllerMode = newControllerMode;
    emit controllerModeChanged();
}

const QString &Menu::controllerName() const
{
    return mControllerName;
}

void Menu::setControllerName(const QString &newControllerName)
{
    if (mControllerName == newControllerName)
        return;
    mControllerName = newControllerName;
    emit controllerNameChanged();
}

void Menu::addChild(Menu *child)
{
    if (child) {
        mChildren << child;
        mScrollHandler->setMenuSize(mScrollHandler->menuSize() + 1);
    }
}

ScrollHandler *Menu::scrollHandler() const
{
    return mScrollHandler;
}

void Menu::setScrollHandler(ScrollHandler *newScrollHandler)
{
    if (mScrollHandler == newScrollHandler)
        return;
    mScrollHandler = newScrollHandler;
    emit scrollHandlerChanged();
}

const QList<Menu *> &Menu::children() const
{
    return mChildren;
}

void Menu::setChildren(const QList<Menu *> &newChildren)
{
    if (mChildren == newChildren)
        return;
    mChildren = newChildren;
    emit childrenChanged();
}

const QString &Menu::name() const
{
    return mName;
}

void Menu::setName(const QString &newName)
{
    if (mName == newName)
        return;
    mName = newName;
    emit nameChanged();
}

const QString &Menu::namePrefix() const
{
    return mNamePrefix;
}

void Menu::setNamePrefix(const QString &newNamePrefix)
{
    if (mNamePrefix == newNamePrefix)
        return;
    mNamePrefix = newNamePrefix;
    emit namePrefixChanged();
}

const QString &Menu::title() const
{
    return mTitle;
}

void Menu::setTitle(const QString &newTitle)
{
    if (mTitle == newTitle)
        return;
    mTitle = newTitle;
    emit titleChanged();
}

const QString &Menu::id() const
{
    return mId;
}

void Menu::setId(const QString &newId)
{
    if (mId == newId)
        return;
    mId = newId;
    emit idChanged();
}
