#ifndef MENU_H
#define MENU_H
#include "ScrollHandler.h"
#include <QObject>

class Menu : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ScrollHandler *scrollHandler READ scrollHandler WRITE setScrollHandler NOTIFY scrollHandlerChanged)
    Q_PROPERTY(QList<Menu *> children READ children WRITE setChildren NOTIFY childrenChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString namePrefix READ namePrefix WRITE setNamePrefix NOTIFY namePrefixChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString controllerName READ controllerName WRITE setControllerName NOTIFY controllerNameChanged)
    Q_PROPERTY(int controllerMode READ controllerMode WRITE setControllerMode NOTIFY controllerModeChanged)

public:
    explicit Menu(QObject *parent = nullptr);

    ScrollHandler *scrollHandler() const;
    void setScrollHandler(ScrollHandler *newScrollHandler);

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

public slots:
    void addChild(Menu *child);
    bool increment();
    bool decrement();
    void reset();
    Menu *selected();

signals:
    void scrollHandlerChanged();
    void childrenChanged();
    void nameChanged();
    void namePrefixChanged();
    void titleChanged();
    void idChanged();

    void controllerNameChanged();

    void controllerModeChanged();

private:
    ScrollHandler *mScrollHandler;
    QList<Menu *> mChildren;
    QString mName;
    QString mNamePrefix;
    QString mTitle;
    QString mId;
    QString mControllerName;
    int mControllerMode;
};

#endif // MENU_H
