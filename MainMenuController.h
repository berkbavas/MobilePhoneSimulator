#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H

#include "Controller.h"
#include "Menu.h"

#include <QStack>

class MainMenuController : public Controller
{
    Q_OBJECT

public:
    explicit MainMenuController(QObject *parent = nullptr);

public:
    virtual void init() override;
    virtual void onAction(Action *action) override;

signals:
    void controllerChanged(QString controllerName, int controllerMode);

private:
    Menu *mActiveMenu;
    Menu *mMainMenu;
    QStack<Menu *> mVisitedMenus;
};

#endif // MAINMENUCONTROLLER_H
