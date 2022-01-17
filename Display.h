#ifndef DISPLAY_H
#define DISPLAY_H

#include "Item.h"

class Display : public Item
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString row0 READ row0 WRITE setRow0 NOTIFY row0Changed)
    Q_PROPERTY(QString row1 READ row1 WRITE setRow1 NOTIFY row1Changed)
    Q_PROPERTY(QString row2 READ row2 WRITE setRow2 NOTIFY row2Changed)
    Q_PROPERTY(QString row3 READ row3 WRITE setRow3 NOTIFY row3Changed)
    Q_PROPERTY(QString row4 READ row4 WRITE setRow4 NOTIFY row4Changed)

public:
    explicit Display(QObject *parent = nullptr);

    const QString &title() const;
    void setTitle(const QString &newTitle);

    const QString &row0() const;
    void setRow0(const QString &newRow0);

    const QString &row1() const;
    void setRow1(const QString &newRow1);

    const QString &row2() const;
    void setRow2(const QString &newRow2);

    const QString &row3() const;
    void setRow3(const QString &newRow3);

    const QString &row4() const;
    void setRow4(const QString &newRow4);

signals:
    void titleChanged();
    void row0Changed();
    void row1Changed();
    void row2Changed();
    void row3Changed();
    void row4Changed();

protected:
    QString mTitle;
    QString mRow0;
    QString mRow1;
    QString mRow2;
    QString mRow3;
    QString mRow4;
};

#endif // DISPLAY_H
