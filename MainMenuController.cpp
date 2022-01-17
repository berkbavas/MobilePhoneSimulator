#include "MainMenuController.h"
#include "Helper.h"

MainMenuController::MainMenuController(QObject *parent)
    : Controller{parent}
    , mActiveMenu(nullptr)
    , mMainMenu(nullptr)
{}

void MainMenuController::init()
{
    mMainMenu = Helper::parseMenus(":/Data/Menus.json");

    connect(this, &Controller::activeChanged, this, [=]() {
        if (mActive) {
            if (mVisitedMenus.isEmpty())
                mActiveMenu = mMainMenu;
            else
                mActiveMenu = mVisitedMenus.pop();

            emit activeItemChanged(mActiveMenu);
        }
    });
}

void MainMenuController::onAction(Action *action)
{
    switch (action->button()) {
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
        if (mActiveMenu == mMainMenu) {
            mMainMenu->reset();
            emit controllerChanged("MainDisplayController", -1);
        } else {
            mActiveMenu = mVisitedMenus.pop();
            emit activeItemChanged(mActiveMenu);
        }
        break;
    case Enums::Button::Space:
        if (mActiveMenu) {
            mVisitedMenus << mActiveMenu;
            Menu *selected = mActiveMenu->selected();

            if (selected->children().size() != 0) {
                mActiveMenu = selected;
                emit activeItemChanged(selected);
            } else {
                emit controllerChanged(selected->controllerName(), selected->controllerMode());
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
    }

    action->setConsumed(true);
}
