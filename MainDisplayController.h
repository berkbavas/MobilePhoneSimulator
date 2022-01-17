#ifndef MAINDISPLAYCONTROLLER_H
#define MAINDISPLAYCONTROLLER_H

#include "Controller.h"

class MainDisplayController : public Controller
{
    Q_OBJECT
public:
    explicit MainDisplayController(QObject *parent = nullptr);

    // Controller interface
public:
    virtual void init() override;
    virtual void onAction(Action *action) override;
};

#endif // MAINDISPLAYCONTROLLER_H
