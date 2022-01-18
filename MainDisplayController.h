#ifndef MAINDISPLAYCONTROLLER_H
#define MAINDISPLAYCONTROLLER_H

#include "Controller.h"
#include "Display.h"

class MainDisplayController : public Controller
{
    Q_OBJECT
public:
    explicit MainDisplayController(QObject *parent = nullptr);

public:
    virtual void init() override;
    virtual void onAction(Action *action) override;
    virtual void update(quint64 milisecondsElapesed) override;

private:
    enum class DisplayType {
        Main,
        Call,
    };

    Display mMainDisplay;
    Display mCallDisplay;

    DisplayType mCurrentDisplay;
};

#endif // MAINDISPLAYCONTROLLER_H
