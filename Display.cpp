#include "Display.h"

Display::Display(QObject *parent)
    : Item{parent}
{
    setType((int) Item::Type::Display);
}

const QString &Display::title() const
{
    return mTitle;
}

void Display::setTitle(const QString &newTitle)
{
    if (mTitle == newTitle)
        return;
    mTitle = newTitle;
    emit titleChanged();
}

const QString &Display::row0() const
{
    return mRow0;
}

void Display::setRow0(const QString &newRow0)
{
    if (mRow0 == newRow0)
        return;
    mRow0 = newRow0;
    emit row0Changed();
}

const QString &Display::row1() const
{
    return mRow1;
}

void Display::setRow1(const QString &newRow1)
{
    if (mRow1 == newRow1)
        return;
    mRow1 = newRow1;
    emit row1Changed();
}

const QString &Display::row2() const
{
    return mRow2;
}

void Display::setRow2(const QString &newRow2)
{
    if (mRow2 == newRow2)
        return;
    mRow2 = newRow2;
    emit row2Changed();
}

const QString &Display::row3() const
{
    return mRow3;
}

void Display::setRow3(const QString &newRow3)
{
    if (mRow3 == newRow3)
        return;
    mRow3 = newRow3;
    emit row3Changed();
}

const QString &Display::row4() const
{
    return mRow4;
}

void Display::setRow4(const QString &newRow4)
{
    if (mRow4 == newRow4)
        return;
    mRow4 = newRow4;
    emit row4Changed();
}
