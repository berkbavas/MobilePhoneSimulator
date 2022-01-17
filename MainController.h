#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "Controller.h"
#include "Display.h"
#include "MainMenuController.h"
#include "SimpleMenu.h"

#include <QMap>
#include <QObject>
#include <QQmlApplicationEngine>

class MainController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(SimpleMenu *simpleMenu READ simpleMenu WRITE setSimpleMenu NOTIFY simpleMenuChanged)
    Q_PROPERTY(Menu *mainMenu READ mainMenu WRITE setMainMenu NOTIFY mainMenuChanged)
    Q_PROPERTY(Display *display READ display WRITE setDisplay NOTIFY displayChanged)

public:
    explicit MainController(QObject *parent = nullptr);

    SimpleMenu *simpleMenu() const;
    void setSimpleMenu(SimpleMenu *newSimpleMenu);

    Menu *mainMenu() const;
    void setMainMenu(Menu *newMainMenu);

    Display *display() const;
    void setDisplay(Display *newDisplay);

    Controller *activeController() const;
    void setActiveController(Controller *newActiveController);

    Item *activeItem() const;
    void setActiveItem(Item *newActiveItem);

public slots:
    void init(QQmlApplicationEngine *engine);
    void onAction(int button, int actionType = -1);
    void onActiveItemChanged(Item *activeItem);

signals:
    void simpleMenuChanged();
    void mainMenuChanged();
    void displayChanged();

    void activeItemChanged();

private:
    Controller *mActiveController;
    Controller *mDefaultDisplayController;
    Controller *mMainDisplayController;
    Controller *mContactsDisplayController;
    MainMenuController *mMainMenuController;

    // Items
    SimpleMenu *mSimpleMenu; // C++ -> QML
    Menu *mMainMenu;         // C++ -> QML
    Display *mDisplay;       // C+ -> QML
    Item *mActiveItem;

    QQmlApplicationEngine *mEngine;
    QMap<QString, Controller *> mControllers;
    Q_PROPERTY(Item *activeItem READ activeItem WRITE setActiveItem NOTIFY activeItemChanged)
};

#endif // MAINCONTROLLER_H
