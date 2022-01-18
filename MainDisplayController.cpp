#include "MainDisplayController.h"
#include "Enums.h"

#include <QDateTime>
#include <QDebug>

MainDisplayController::MainDisplayController(QObject *parent)
    : Controller{parent}
{
    mCurrentDisplay = DisplayType::Main;

    mMainDisplay.setRow0("                         ");
    mMainDisplay.setRow1("     ╔══════════════╗    ");
    mMainDisplay.setRow2("     ║ Main Display ║    ");
    mMainDisplay.setRow3("     ╚══════════════╝    ");
    mMainDisplay.setRow4("                         ");
    mMainDisplay.setRow5("                         ");
    mMainDisplay.setRow6("           Menu          ");

    mCallDisplay.clearAll();

    connect(this, &Controller::activeChanged, this, [=]() {
        if (mActive) {
            mLineEditor->reset();
            emit activeItemChanged(&mMainDisplay);
        }
    });
}

void MainDisplayController::init()
{
    connect(mLineEditor, &LineEditor::finished, this, [=]() {
        if (mCurrentDisplay == DisplayType::Call) {
            mCurrentDisplay = DisplayType::Main;
            emit activeItemChanged(&mMainDisplay);
        }
    });
}

void MainDisplayController::onAction(Action *action)
{
    switch (action->button()) {
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
        if (mCurrentDisplay == DisplayType::Main) {
            mCurrentDisplay = DisplayType::Call;
            mLineEditor->reset();
            mLineEditor->setEditMode(LineEditor::EditMode::All);
            mLineEditor->setCharacterLimit(24);
            mLineEditor->onAction(action);
            emit activeItemChanged(&mCallDisplay);
        } else if (mCurrentDisplay == DisplayType::Call) {
            mLineEditor->onAction(action);
        }
    case Enums::Button::Star:
        break;
    case Enums::Button::Clear:
        if (mCurrentDisplay == DisplayType::Call) {
            mLineEditor->onAction(action);
        } else if (mCurrentDisplay == DisplayType::Main) {
            action->setConsumed(true);
        }
        break;
    case Enums::Button::Enter:
        if (mCurrentDisplay == DisplayType::Call) {
            action->setConsumed(true);
        }
        break;
    case Enums::Button::Up:
        break;
    case Enums::Button::Down:
        break;
    case Enums::Button::None:
        break;
    }
}

void MainDisplayController::update(quint64 milisecondsElapesed)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString date = dateTime.toString("dd.MM.yyyy");
    QString time = dateTime.toString("hh:mm:ss");
    mMainDisplay.setTitle(date + "      " + time);
    mCallDisplay.setTitle(date + "      " + time);

    if (mCurrentDisplay == DisplayType::Call) {
        mCallDisplay.setRow0(mLineEditor->getVisualLine());
        mCallDisplay.setRow6(mLineEditor->getHint().leftJustified(23) + QString::number(mLineEditor->getNumberOfRemainingCharacters()));
    }
}
