#include "Display.h"

const int Display::NUMBER_OF_ROWS = 7;
const int Display::NUMBER_OF_CHARS = 25;

Display::Display(QObject *parent)
    : Item{parent}
{
    setType((int) Item::Type::Display);
    clearAll();
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

const QStringList &Display::rows() const
{
    return mRows;
}

void Display::setRow(int index, const QString &row, Alignment alignment)
{
    if (index < NUMBER_OF_ROWS)
    {
        switch (alignment)
        {
        case Display::Alignment::Left:
            mRows.removeAt(index);
            mRows.insert(index, row.leftJustified(NUMBER_OF_CHARS, ' '));
            break;
        case Display::Alignment::Center:
        {
            int left = (NUMBER_OF_CHARS - row.length()) / 2.0;
            int right = NUMBER_OF_CHARS - left;
            mRows.removeAt(index);
            mRows.insert(index, QString(" ").repeated(left) + row + QString(" ").repeated(right));
            break;
        }

        case Display::Alignment::Right:
            mRows.removeAt(index);
            mRows.insert(index, row.leftJustified(NUMBER_OF_CHARS, ' '));
            break;
        }

        emit rowsChanged();
    }
}

void Display::setRow(int index, const QString &left, const QString &right)
{
    if (index < NUMBER_OF_ROWS)
    {
        mRows.removeAt(index);
        mRows.insert(index,
                     left + QString(" ").repeated(NUMBER_OF_CHARS - left.length() - right.length())
                         + right);
        emit rowsChanged();
    }
}

void Display::clearAll()
{
    setTitle(" ");
    clearRows();
}

void Display::clearRows()
{
    mRows.clear();

    for (int i = 0; i < NUMBER_OF_ROWS; ++i)
        mRows << " ";

    emit rowsChanged();
}
