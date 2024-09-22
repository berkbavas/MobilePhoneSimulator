#ifndef CHARSET_H
#define CHARSET_H

#include <QObject>

class Charset
{
public:
    Charset(const QString &chars, const QString &hint = QString());

    int currentIndex() const;
    const QString &chars() const;
    const QString &hint() const;

    QString next();
    void reset();

private:
    int mCurrentIndex;
    QString mChars;
    QString mHint;
};

#endif // CHARSET_H
