#ifndef CONTACTSCONTROLLER_H
#define CONTACTSCONTROLLER_H

#include "Contact.h"
#include "Controller.h"
#include "ScrollHandler.h"

#include <QStack>

class ContactsController : public Controller
{
    Q_OBJECT
    Q_PROPERTY(int currentDisplay READ currentDisplay WRITE setCurrentDisplay NOTIFY currentDisplayChanged)
    Q_PROPERTY(ScrollHandler *scrollHandler READ scrollHandler WRITE setScrollHandler NOTIFY scrollHandlerChanged)
    Q_PROPERTY(QList<Contact *> contacts READ contacts WRITE setContacts NOTIFY contactsChanged)

public:
    enum class Display : int { //
        List,
        Show,
        Call,
        Add,
        Edit,
        Delete
    };

    enum class Mode : int { //
        Show,
        Call,
        Add,
        Edit,
        Delete
    };

    explicit ContactsController(QObject *parent = nullptr);

    // Controller interface
public:
    virtual void init() override;
    virtual void onAction(Action *action) override;

    int currentDisplay() const;
    void setCurrentDisplay(int newCurrentDisplay);

    ScrollHandler *scrollHandler() const;
    void setScrollHandler(ScrollHandler *newScrollHandler);

    const QList<Contact *> &contacts() const;
    void setContacts(const QList<Contact *> &newContacts);

signals:
    void currentDisplayChanged();
    void scrollHandlerChanged();
    void contactsChanged();

private:
    QStack<Display> mVisitedDisplays;

    QList<Contact *> mContacts;
    ScrollHandler *mScrollHandler;
    int mCurrentDisplay;
};

#endif // CONTACTSCONTROLLER_H
