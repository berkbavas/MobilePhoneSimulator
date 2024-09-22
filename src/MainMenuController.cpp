#include "MainMenuController.h"
#include "Helper.h"

MainMenuController::MainMenuController(QObject *parent)
    : Controller{parent}
    , mActiveMenu(nullptr)
    , mMainMenu(nullptr)
{
    mMainMenu = Helper::parseMenus(":/resources/Data/Menus.json");

    connect(this, &Controller::activeChanged, this, [=]() {
        if (mActive)
        {
            if (mVisitedMenus.isEmpty())
                mActiveMenu = mMainMenu;
            else
                mActiveMenu = mVisitedMenus.pop();

            emit activeItemChanged(mActiveMenu);
        }
        else
        {
            emit activeItemChanged(nullptr);
        }
    });
}

void MainMenuController::onAction(Action *action)
{
    switch (action->button())
    {
    case Enums::Button::Clear:
        if (mActiveMenu == mMainMenu)
        {
            mMainMenu->reset();
            mRequest.setStatus(Request::Status::Created);
            mRequest.setControllerName("MainDisplayController");
            emit requestCreated(&mRequest);
        }
        else
        {
            mActiveMenu = mVisitedMenus.pop();
            emit activeItemChanged(mActiveMenu);
        }
        break;
    case Enums::Button::Enter:
        if (mActiveMenu)
        {
            mVisitedMenus << mActiveMenu;
            Menu *selected = mActiveMenu->selected();

            if (selected->children().size() != 0)
            {
                mActiveMenu = selected;
                emit activeItemChanged(selected);
            }
            else
            {
                mRequest.setStatus(Request::Status::Created);
                mRequest.setControllerName(selected->controllerName());
                mRequest.setControllerMode(selected->controllerMode());
                emit requestCreated(&mRequest);
            }
        }
        break;
    case Enums::Button::Up:
        if (mActiveMenu)
            mActiveMenu->decrement();
        break;
    case Enums::Button::Down:
        if (mActiveMenu)
            mActiveMenu->increment();
        break;
    default:
        break;
    }

    action->setConsumed(true);
}
