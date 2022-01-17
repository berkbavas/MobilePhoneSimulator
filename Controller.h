#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Action.h"

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int mode READ mode WRITE setMode NOTIFY modeChanged)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)

public:
    explicit Controller(QObject *parent = nullptr);
    virtual void init() = 0;
    virtual void onAction(Action *action) = 0;

    int mode() const;
    void setMode(int newMode);

    bool active() const;
    void setActive(bool newActive);

signals:
    void modeChanged();
    void activeChanged();

protected:
    int mMode;
    bool mActive;
};

#endif // CONTROLLER_H
