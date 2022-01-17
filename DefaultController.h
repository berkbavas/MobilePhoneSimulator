#ifndef DEFAULTCONTROLLER_H
#define DEFAULTCONTROLLER_H

#include "Controller.h"

class DefaultController : public Controller
{
    Q_OBJECT
public:
    explicit DefaultController(QObject *parent = nullptr);

    // Controller interface
public:
    virtual void init() override;
    virtual void onAction(Action *action) override;
};

#endif // DEFAULTCONTROLLER_H
