#ifndef MENU_H
#define MENU_H

#include "Item.h"

#include <QObject>

class Menu : public Item
{
    Q_OBJECT
    Q_PROPERTY(QList<Menu *> children READ children WRITE setChildren NOTIFY childrenChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString namePrefix READ namePrefix WRITE setNamePrefix NOTIFY namePrefixChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(int firstVisibleIndex READ firstVisibleIndex WRITE setFirstVisibleIndex NOTIFY firstVisibleIndexChanged)
    Q_PROPERTY(int lastVisibleIndex READ lastVisibleIndex WRITE setLastVisibleIndex NOTIFY lastVisibleIndexChanged)

public:
    explicit Menu(QObject *parent = nullptr);

    const QList<Menu *> &children() const;
    void setChildren(const QList<Menu *> &newChildren);

    const QString &name() const;
    void setName(const QString &newName);

    const QString &namePrefix() const;
    void setNamePrefix(const QString &newNamePrefix);

    const QString &title() const;
    void setTitle(const QString &newTitle);

    const QString &id() const;
    void setId(const QString &newId);

    const QString &controllerName() const;
    void setControllerName(const QString &newControllerName);

    int controllerMode() const;
    void setControllerMode(int newControllerMode);

    int currentIndex() const;
    void setCurrentIndex(int newCurrentIndex);

    int firstVisibleIndex() const;
    void setFirstVisibleIndex(int newFirstVisibleIndex);

    int lastVisibleIndex() const;
    void setLastVisibleIndex(int newLastVisibleIndex);

public slots:
    void addChild(Menu *child);
    void increment();
    void decrement();
    void reset();
    void update();
    Menu *selected();

signals:
    void childrenChanged();
    void nameChanged();
    void namePrefixChanged();
    void titleChanged();
    void idChanged();
    void controllerNameChanged();
    void controllerModeChanged();
    void currentIndexChanged();
    void firstVisibleIndexChanged();
    void lastVisibleIndexChanged();

private:
    QList<Menu *> mChildren;
    QString mName;
    QString mNamePrefix;
    QString mTitle;
    QString mId;
    QString mControllerName;
    int mControllerMode;

    // Scroll
    int mCurrentIndex;
    int mFirstVisibleIndex;
    int mLastVisibleIndex;
};

#endif // MENU_H
