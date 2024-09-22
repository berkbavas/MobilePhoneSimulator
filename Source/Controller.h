#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Action.h"
#include "Item.h"
#include "Request.h"

#include "LineEditor/LineEditor.h"

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

    virtual void init();
    virtual void onAction(Action *action);
    virtual void update(quint64 milisecondsElapsed);

    int mode() const;
    void setMode(int newMode);

    bool active() const;
    void setActive(bool newActive);

    void setLineEditor(LineEditor *newLineEditor);

signals:
    void modeChanged();
    void activeChanged();
    void activeItemChanged(Item *activeItem);
    void requestCreated(Request *request);

protected:
    int mMode;
    bool mActive;
    LineEditor *mLineEditor;
};

#endif // CONTROLLER_H
