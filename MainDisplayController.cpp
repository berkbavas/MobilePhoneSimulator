#include "MainDisplayController.h"
#include "Enums.h"

MainDisplayController::MainDisplayController(QObject *parent)
    : Controller{parent}
{}

void MainDisplayController::init() {}

void MainDisplayController::onAction(Action *action)
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
        action->setConsumed(true);
        break;
    case Enums::Button::Space:
        break;
    case Enums::Button::Up:
        break;
    case Enums::Button::Down:
        break;
    }
}
