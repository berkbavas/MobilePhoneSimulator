#ifndef ITEM_H
#define ITEM_H

#include <QObject>

class Item : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)

public:
    explicit Item(QObject *parent = nullptr);

    enum class Type : int { //
        MainMenu,
        SimpleMenu,
        Display
    };

    int type() const;
    void setType(int newType);

signals:
    void typeChanged();

protected:
    int mType;
};

#endif // ITEM_H
