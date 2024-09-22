#include "MainController.h"
#include "Action.h"
#include "DefaultDisplayController.h"
#include "Enums.h"
#include "MainDisplayController.h"

#include "Contacts/ContactsDisplayController.h"

#include <QDateTime>
#include <QQmlContext>

MainController::MainController(QObject *parent)
    : QObject{parent}
    , mActiveController(nullptr)
    , mActiveItem(nullptr)
    , mEngine(nullptr)
{
    mLineEditor = new LineEditor;
    connect(&mTimer, &QTimer::timeout, this, &MainController::update);
}

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

    for (const auto &controller : qAsConst(mControllers))
    {
        connect(controller, &Controller::requestCreated, this, &MainController::onRequestCreated);
        connect(controller, &Controller::activeItemChanged, this, &MainController::setActiveItem);
        controller->setLineEditor(mLineEditor);
        controller->init();
    }

    setActiveController(mMainDisplayController);
    mCurrentTime = QDateTime::currentMSecsSinceEpoch();
    mPreviousTime = mCurrentTime;
    mSimulationTime = 0;
    mTimer.start(20);
}

void MainController::onAction(int button, int actionType)
{
    qDebug() << Q_FUNC_INFO << button << actionType;

    Action action(button, actionType);

    if (mActiveController)
        mActiveController->onAction(&action);

    if (action.consumed())
        return;

    switch (action.button())
    {
    case Enums::Button::Clear:
        if (mActiveController != mMainDisplayController)
            setActiveController(mMainMenuController);
        break;
    case Enums::Button::Enter:
        setActiveController(mMainMenuController);
        break;
    default:
        break;
    }
}

void MainController::update()
{
    mPreviousTime = mCurrentTime;
    mCurrentTime = QDateTime::currentMSecsSinceEpoch();
    mSimulationTime += mCurrentTime - mPreviousTime;

    mLineEditor->update(mCurrentTime - mPreviousTime);

    if (mActiveController)
        mActiveController->update(mCurrentTime - mPreviousTime);
}

void MainController::onRequestCreated(Request *request)
{
    ChangeControllerRequest *changeControllerRequest = dynamic_cast<ChangeControllerRequest *>(
        request);

    if (changeControllerRequest)
    {
        Controller *controller = mControllers.value(changeControllerRequest->controllerName(),
                                                    nullptr);
        if (controller)
        {
            controller->setMode(changeControllerRequest->controllerMode());
            setActiveController(controller);
        }
    }
}

Item *MainController::activeItem() const
{
    return mActiveItem;
}

void MainController::setActiveItem(Item *newActiveItem)
{
    qDebug() << "Receiver:" << Q_FUNC_INFO << "Sender:" << QObject::sender() << newActiveItem;

    if (mActiveItem == newActiveItem)
        return;

    mActiveItem = newActiveItem;
    emit activeItemChanged();
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
