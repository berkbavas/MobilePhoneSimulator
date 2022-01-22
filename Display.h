#ifndef DISPLAY_H
#define DISPLAY_H

#include "Item.h"

class Display : public Item
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QStringList rows READ rows NOTIFY rowsChanged)

public:
    enum class Alignment { //
        Left,
        Center,
        Right
    };

    explicit Display(QObject *parent = nullptr);

    const QString &title() const;
    void setTitle(const QString &newTitle);

    const QStringList &rows() const;
    void setRow(int index, const QString &row, Alignment alignment = Alignment::Left);
    void setRow(int index, const QString &left, const QString &right);

    void clearAll();
    void clearRows();

signals:
    void titleChanged();
    void rowsChanged();

protected:
    QString mTitle;
    QStringList mRows;

    static const int NUMBER_OF_ROWS;
    static const int NUMBER_OF_CHARS;
};

#endif // DISPLAY_H
