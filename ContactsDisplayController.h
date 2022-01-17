#ifndef CONTACTSDISPLAYCONTROLLER_H
#define CONTACTSDISPLAYCONTROLLER_H

#include "Contact.h"
#include "Controller.h"
#include "Display.h"
#include "SimpleMenu.h"

#include <QStack>

class ContactsDisplayController : public Controller
{
public:
    enum class DisplayType : int { //
        List,
        Details
    };

    enum class Mode : int { //
        Show,
        Call,
        Add,
        Edit,
        Delete
    };

    explicit ContactsDisplayController(QObject *parent = nullptr);

public:
    virtual void init() override;
    virtual void onAction(Action *action) override;

private slots:
    QString getTitle();

private:
    QList<Contact *> mContacts;
    SimpleMenu mContactsList;
    Display mContactDetails;

    QStack<DisplayType> mVisitedDisplays;
    DisplayType mCurrentDisplay;
};

#endif // CONTACTSDISPLAYCONTROLLER_H
