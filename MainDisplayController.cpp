#include "MainDisplayController.h"
#include "Enums.h"

#include <QDateTime>
#include <QDebug>

MainDisplayController::MainDisplayController(QObject *parent)
    : Controller{parent}
{
    mDisplay.setRow0("                         ");
    mDisplay.setRow1("     ╔══════════════╗    ");
    mDisplay.setRow2("     ║ Main Display ║    ");
    mDisplay.setRow3("     ╚══════════════╝    ");
    mDisplay.setRow4("                         ");
    mDisplay.setRow5("                         ");
    mDisplay.setRow6("           Menu          ");

    connect(this, &Controller::activeChanged, this, [=]() {
        if (mActive) {
            emit activeItemChanged(&mDisplay);
        }
    });
}

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

void MainDisplayController::update(quint64 milisecondsElapesed)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString date = dateTime.toString("dd.MM.yyyy");
    QString time = dateTime.toString("hh:mm:ss");
    mDisplay.setTitle(date + "      " + time);
}
