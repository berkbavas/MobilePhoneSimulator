#include "MenuController.h"
#include "Helper.h"

MenuController::MenuController(QObject *parent)
    : Controller{parent}
    , mActiveMenu(nullptr)
    , mMainMenu(nullptr)
{
    connect(this, &Controller::activeChanged, this, [=]() {
        if (mActive) {
            if (mVisitedMenus.isEmpty())
                setActiveMenu(mMainMenu);
            else
                setActiveMenu(mVisitedMenus.pop());
        }
    });
}

void MenuController::init()
{
    mMainMenu = Helper::parseMenus(":/Data/Menus.json");
}

void MenuController::onAction(Action *action)
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
            setActiveMenu(nullptr);
            mMainMenu->scrollHandler()->reset();
            emit controllerChanged("MainDisplayController", -1);
        } else {
            setActiveMenu(mVisitedMenus.pop());
        }
        break;
    case Enums::Button::Space:
        if (mActiveMenu) {
            mVisitedMenus << mActiveMenu;
            Menu *selected = mActiveMenu->selected();

            if (selected->children().size() != 0) {
                setActiveMenu(selected);
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

Menu *MenuController::activeMenu() const
{
    return mActiveMenu;
}

void MenuController::setActiveMenu(Menu *newActiveMenu)
{
    if (mActiveMenu == newActiveMenu)
        return;
    mActiveMenu = newActiveMenu;
    emit activeMenuChanged();
}
