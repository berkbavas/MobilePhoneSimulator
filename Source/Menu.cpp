#include "Menu.h"

Menu::Menu(QObject *parent)
    : Item{parent}
    , mName()
    , mNamePrefix()
    , mTitle()
    , mId()
    , mCurrentIndex(0)
    , mFirstVisibleIndex(0)
    , mLastVisibleIndex(6)
{
    setType((int) Item::Type::MainMenu);
}

void Menu::increment()
{
    setCurrentIndex((mCurrentIndex + 1) % mChildren.length());
    update();
}

void Menu::decrement()
{
    setCurrentIndex((mCurrentIndex - 1) < 0 ? (mCurrentIndex - 1) + mChildren.length()
                                            : (mCurrentIndex - 1) % mChildren.length());
    update();
}

void Menu::reset()
{
    setCurrentIndex(0);
    setFirstVisibleIndex(0);
    setLastVisibleIndex(6);
}

void Menu::update()
{
    while (mLastVisibleIndex < mCurrentIndex)
    {
        setFirstVisibleIndex(mFirstVisibleIndex + 1);
        setLastVisibleIndex(mLastVisibleIndex + 1);
    }

    while (mCurrentIndex < mFirstVisibleIndex)
    {
        setFirstVisibleIndex(mFirstVisibleIndex - 1);
        setLastVisibleIndex(mLastVisibleIndex - 1);
    }
}

Menu *Menu::selected()
{
    return mChildren.at(mCurrentIndex);
}

int Menu::lastVisibleIndex() const
{
    return mLastVisibleIndex;
}

void Menu::setLastVisibleIndex(int newLastVisibleIndex)
{
    if (mLastVisibleIndex == newLastVisibleIndex)
        return;
    mLastVisibleIndex = newLastVisibleIndex;
    emit lastVisibleIndexChanged();
}

int Menu::firstVisibleIndex() const
{
    return mFirstVisibleIndex;
}

void Menu::setFirstVisibleIndex(int newFirstVisibleIndex)
{
    if (mFirstVisibleIndex == newFirstVisibleIndex)
        return;
    mFirstVisibleIndex = newFirstVisibleIndex;
    emit firstVisibleIndexChanged();
}

int Menu::currentIndex() const
{
    return mCurrentIndex;
}

void Menu::setCurrentIndex(int newCurrentIndex)
{
    if (mCurrentIndex == newCurrentIndex)
        return;
    mCurrentIndex = newCurrentIndex;
    emit currentIndexChanged();
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
    if (child)
    {
        mChildren << child;
    }
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
