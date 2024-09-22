#include "MainDisplayController.h"
#include "Enums.h"

#include <QDateTime>
#include <QDebug>

MainDisplayController::MainDisplayController(QObject *parent)
    : Controller{parent}
{
    mMainDisplay.setRow(0, "                         ");
    mMainDisplay.setRow(1, "     ╔══════════════╗    ");
    mMainDisplay.setRow(2, "     ║ Main Display ║    ");
    mMainDisplay.setRow(3, "     ╚══════════════╝    ");
    mMainDisplay.setRow(4, "                         ");
    mMainDisplay.setRow(5, "                         ");
    mMainDisplay.setRow(6, "           Menu          ");

    connect(this, &Controller::activeChanged, this, [=]() {
        if (mActive)
        {
            mLineEditor->reset();
            emit activeItemChanged(&mMainDisplay);
        }
    });
}

void MainDisplayController::init() {}

void MainDisplayController::onAction(Action *action)
{
    switch (action->button())
    {
    case Enums::Button::Zero:
    case Enums::Button::One:
    case Enums::Button::Two:
    case Enums::Button::Three:
    case Enums::Button::Four:
    case Enums::Button::Five:
    case Enums::Button::Six:
    case Enums::Button::Seven:
    case Enums::Button::Eight:
    case Enums::Button::Nine:
    case Enums::Button::Square:
    case Enums::Button::Star:
        break;
    case Enums::Button::Clear:
        action->setConsumed(true);
        break;
    case Enums::Button::Enter:
        break;
    case Enums::Button::Up:
        break;
    case Enums::Button::Down:
        break;
    case Enums::Button::None:
        break;
    }
}

void MainDisplayController::update(quint64)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString date = dateTime.toString("dd.MM.yyyy");
    QString time = dateTime.toString("hh:mm:ss");
    mMainDisplay.setTitle(date + "       " + time);
}
