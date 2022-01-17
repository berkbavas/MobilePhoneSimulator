#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "Controller.h"
#include "Menu.h"

#include <QStack>

class MenuController : public Controller
{
    Q_OBJECT
    Q_PROPERTY(Menu *activeMenu READ activeMenu WRITE setActiveMenu NOTIFY activeMenuChanged)

public:
    explicit MenuController(QObject *parent = nullptr);

    // Controller interface
public:
    virtual void init() override;
    virtual void onAction(Action *action) override;

    Menu *activeMenu() const;
    void setActiveMenu(Menu *newActiveMenu);

signals:
    void activeMenuChanged();
    void controllerChanged(QString controllerName, int controllerMode);

private:
    Menu *mActiveMenu; // C++ -> QML
    Menu *mMainMenu;
    QStack<Menu *> mVisitedMenus;
};

#endif // MENUCONTROLLER_H
