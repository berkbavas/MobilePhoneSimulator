#include "MainController.h"
#include "Action.h"
#include "ContactsDisplayController.h"
#include "DefaultDisplayController.h"
#include "Enums.h"
#include "Helper.h"
#include "MainDisplayController.h"

#include <QQmlContext>

MainController::MainController(QObject *parent)
    : QObject{parent}
    , mActiveController(nullptr)
    , mActiveItem(nullptr)
    , mEngine(nullptr)
{}

void MainController::init(QQmlApplicationEngine *engine)
{
    mEngine = engine;
    mEngine->rootContext()->setContextProperty("controller", this);

    mMainMenuController = new MainMenuController;
    mControllers.insert("MainMenuController", mMainMenuController);

    mDefaultDisplayController = new DefaultDisplayController;
    mControllers.insert("DefaultDisplayController", mDefaultDisplayController);

    mMainDisplayController = new MainDisplayController;
    mControllers.insert("MainDisplayController", mMainDisplayController);

    mContactsDisplayController = new ContactsDisplayController;
    mControllers.insert("ContactsDisplayController", mContactsDisplayController);

    QMap<QString, Controller *>::iterator it;

    for (it = mControllers.begin(); it != mControllers.end(); it++) {
        connect(it.value(), &Controller::activeItemChanged, this, &MainController::onActiveItemChanged);
        it.value()->init();
    }

    // Connections
    connect(mMainMenuController, &MainMenuController::controllerChanged, this, [=](QString controllerName, int controllerMode) {
        Controller *controller = mControllers.value(controllerName, mDefaultDisplayController);
        controller->setMode(controllerMode);
        setActiveController(controller);
    });

    setActiveController(mMainDisplayController);
}

void MainController::onAction(int button, int actionType)
{
    qDebug() << "MainController::onAction" << button << actionType;

    Action action(button, actionType);

    if (mActiveController)
        mActiveController->onAction(&action);

    if (action.consumed())
        return;

    switch (action.button()) {
    case Enums::Button::Zero:
        break;
    case Enums::Button::One:
        break;
    case Enums::Button::Two:
        break;
    case Enums::Button::Three:
        break;
    case Enums::Button::Four:
        break;
    case Enums::Button::Five:
        break;
    case Enums::Button::Six:
        break;
    case Enums::Button::Seven:
        break;
    case Enums::Button::Eight:
        break;
    case Enums::Button::Nine:
        break;
    case Enums::Button::Star:
        break;
    case Enums::Button::Square:
        break;
    case Enums::Button::Clear:
        if (mActiveController != mMainDisplayController)
            setActiveController(mMainMenuController);
        break;
    case Enums::Button::Space:
        setActiveController(mMainMenuController);
        break;
    case Enums::Button::Up:
        break;
    case Enums::Button::Down:
        break;
    }
}

void MainController::onActiveItemChanged(Item *activeItem)
{
    qDebug() << "MainController::onActiveItemChanged" << activeItem;

    setActiveItem(activeItem);

    if (activeItem->type() == 0)
        setMainMenu(dynamic_cast<Menu *>(activeItem));
    else if (activeItem->type() == 1)
        setSimpleMenu(dynamic_cast<SimpleMenu *>(activeItem));
    else if (activeItem->type() == 2)
        setDisplay(dynamic_cast<Display *>(activeItem));
}

Item *MainController::activeItem() const
{
    return mActiveItem;
}

void MainController::setActiveItem(Item *newActiveItem)
{
    if (mActiveItem == newActiveItem)
        return;

    mActiveItem = newActiveItem;
    emit activeItemChanged();
}

Display *MainController::display() const
{
    return mDisplay;
}

void MainController::setDisplay(Display *newDisplay)
{
    if (mDisplay == newDisplay)
        return;
    mDisplay = newDisplay;
    emit displayChanged();
}

Menu *MainController::mainMenu() const
{
    return mMainMenu;
}

void MainController::setMainMenu(Menu *newMainMenu)
{
    if (mMainMenu == newMainMenu)
        return;
    mMainMenu = newMainMenu;
    emit mainMenuChanged();
}

SimpleMenu *MainController::simpleMenu() const
{
    return mSimpleMenu;
}

void MainController::setSimpleMenu(SimpleMenu *newSimpleMenu)
{
    if (mSimpleMenu == newSimpleMenu)
        return;
    mSimpleMenu = newSimpleMenu;
    emit simpleMenuChanged();
}

Controller *MainController::activeController() const
{
    return mActiveController;
}

void MainController::setActiveController(Controller *newActiveController)
{
    if (mActiveController == newActiveController)
        return;

    if (mActiveController)
        mActiveController->setActive(false);

    if (newActiveController)
        newActiveController->setActive(true);

    mActiveController = newActiveController;
}
