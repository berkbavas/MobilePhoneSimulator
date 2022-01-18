#ifndef DEFAULTDISPLAYCONTROLLER_H
#define DEFAULTDISPLAYCONTROLLER_H

#include "Controller.h"
#include "Display.h"

class DefaultDisplayController : public Controller
{
    Q_OBJECT
public:
    explicit DefaultDisplayController(QObject *parent = nullptr);

private:
    Display mDisplay;
};

#endif // DEFAULTDISPLAYCONTROLLER_H
