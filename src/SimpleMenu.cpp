#include "SimpleMenu.h"

SimpleMenu::SimpleMenu(QObject *parent)
    : Item{parent}
{
    setType((int) Item::Type::SimpleMenu);
    reset();
}

void SimpleMenu::increment()
{
    setCurrentIndex((mCurrentIndex + 1) % mRows.length());
    update();
}

void SimpleMenu::decrement()
{
    setCurrentIndex((mCurrentIndex - 1) < 0 ? (mCurrentIndex - 1) + mRows.length()
                                            : (mCurrentIndex - 1) % mRows.length());
    update();
}

void SimpleMenu::reset()
{
    setCurrentIndex(0);
    setFirstVisibleIndex(0);
    setLastVisibleIndex(6);
}

void SimpleMenu::update()
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

const QString &SimpleMenu::title() const
{
    return mTitle;
}

void SimpleMenu::setTitle(const QString &newTitle)
{
    if (mTitle == newTitle)
        return;
    mTitle = newTitle;
    emit titleChanged();
}

const QStringList &SimpleMenu::rows() const
{
    return mRows;
}

void SimpleMenu::setRows(const QStringList &newRows)
{
    if (mRows == newRows)
        return;
    mRows = newRows;
    emit rowsChanged();
}

int SimpleMenu::currentIndex() const
{
    return mCurrentIndex;
}

void SimpleMenu::setCurrentIndex(int newCurrentIndex)
{
    if (mCurrentIndex == newCurrentIndex)
        return;
    mCurrentIndex = newCurrentIndex;
    emit currentIndexChanged();
}

int SimpleMenu::firstVisibleIndex() const
{
    return mFirstVisibleIndex;
}

void SimpleMenu::setFirstVisibleIndex(int newFirstVisibleIndex)
{
    if (mFirstVisibleIndex == newFirstVisibleIndex)
        return;
    mFirstVisibleIndex = newFirstVisibleIndex;
    emit firstVisibleIndexChanged();
}

int SimpleMenu::lastVisibleIndex() const
{
    return mLastVisibleIndex;
}

void SimpleMenu::setLastVisibleIndex(int newLastVisibleIndex)
{
    if (mLastVisibleIndex == newLastVisibleIndex)
        return;
    mLastVisibleIndex = newLastVisibleIndex;
    emit lastVisibleIndexChanged();
}

void SimpleMenu::addRow(const QString &row)
{
    mRows << row;
    emit rowsChanged();
}

void SimpleMenu::setRow(int index, const QString &row)
{
    mRows.removeAt(index);
    mRows.insert(index, row);
}

void SimpleMenu::clearAll()
{
    setTitle(" ");
    clearRows();
}

void SimpleMenu::clearRows()
{
    mRows.clear();
    emit rowsChanged();
}
