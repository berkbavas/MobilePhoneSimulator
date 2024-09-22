#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H

#include "ChangeControllerRequest.h"
#include "Controller.h"
#include "Menu.h"

#include <QStack>

class MainMenuController : public Controller
{
    Q_OBJECT
public:
    explicit MainMenuController(QObject *parent = nullptr);

public:
    virtual void onAction(Action *action) override;

private:
    Menu *mActiveMenu;
    Menu *mMainMenu;
    QStack<Menu *> mVisitedMenus;
    ChangeControllerRequest mRequest;
};

#endif // MAINMENUCONTROLLER_H
