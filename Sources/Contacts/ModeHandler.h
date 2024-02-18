#ifndef MODEHANDLER_H
#define MODEHANDLER_H

#include "Contact.h"
#include "LineEditor/LineEditor.h"
#include "Request.h"
#include "SimpleMenu.h"

#include <QObject>

class ModeHandler : public QObject
{
    Q_OBJECT
public:
    explicit ModeHandler(QObject *parent = nullptr);

    virtual void onAction(Action *action) = 0;
    virtual void update(quint64 milisecondsElapsed);

    bool active() const;
    void setActive(bool newActive);
    void setContacts(QList<Contact *> *newContacts);
    void setContactList(SimpleMenu *newContactList);
    void setLineEditor(LineEditor *newLineEditor);

signals:
    void activeItemChanged(Item *item);
    void activeChanged();
    void finished();
    void requestCreated(Request *request);
    void updateContactList();

protected:
    QList<Contact *> *mContacts;
    SimpleMenu *mContactList;
    LineEditor *mLineEditor;
    bool mActive;
};

#endif // MODEHANDLER_H
