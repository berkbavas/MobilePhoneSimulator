#include "Charset.h"

Charset::Charset(const QString &chars, const QString &hint)
    : mCurrentIndex(0)
    , mChars(chars)
    , mHint(hint)

{}

int Charset::currentIndex() const
{
    return mCurrentIndex;
}

const QString &Charset::chars() const
{
    return mChars;
}

const QString &Charset::hint() const
{
    return mHint.isEmpty() ? mChars : mHint;
}

QString Charset::next()
{
    return mChars.isEmpty() ? QString("") : mChars.at(mCurrentIndex++ % mChars.length());
}

void Charset::reset()
{
    mCurrentIndex = 0;
}
