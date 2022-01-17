#include "MainController.h"
#include "Action.h"
#include "ContactsController.h"
#include "DefaultController.h"
#include "Enums.h"
#include "Helper.h"
#include "MainDisplayController.h"

#include <QQmlContext>

MainController::MainController(QObject *parent)
    : QObject{parent}
    , mActiveController(nullptr)
    , mDefaultController(nullptr)
    , mEngine(nullptr)
{}

void MainController::init(QQmlApplicationEngine *engine)
{
    mEngine = engine;
    mEngine->rootContext()->setContextProperty("controller", this);

    mMenuController = new MenuController;
    mMenuController->init();
    mControllers.insert("MenuController", mMenuController);
    mEngine->rootContext()->setContextProperty("menuController", mMenuController);

    mDefaultController = new DefaultController;
    mDefaultController->init();
    mControllers.insert("DefaultController", mDefaultController);
    mEngine->rootContext()->setContextProperty("defaultDisplayController", mDefaultController);

    mMainDisplayController = new MainDisplayController;
    mMainDisplayController->init();
    mControllers.insert("MainDisplayController", mMainDisplayController);
    mEngine->rootContext()->setContextProperty("mainDisplayController", mMainDisplayController);

    mContactsController = new ContactsController;
    mContactsController->init();
    mControllers.insert("ContactsController", mContactsController);
    mEngine->rootContext()->setContextProperty("contactsController", mContactsController);

    setActiveController(mMainDisplayController);

    // Connections
    connect(mMenuController, &MenuController::controllerChanged, this, [=](QString controllerName, int controllerMode) {
        Controller *controller = mControllers.value(controllerName, mDefaultController);
        controller->setMode(controllerMode);
        setActiveController(controller);
    });
}

void MainController::onAction(int button, int actionType)
{
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
            setActiveController(mMenuController);
        break;
    case Enums::Button::Space:
        setActiveController(mMenuController);
        break;
    case Enums::Button::Up:
        break;
    case Enums::Button::Down:
        break;
    }
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
