#include "DefaultDisplayController.h"

DefaultDisplayController::DefaultDisplayController(QObject *parent)
    : Controller{parent}
{}

void DefaultDisplayController::init()
{
    mDisplay.setTitle("");
    mDisplay.setRow0("This display is");
    mDisplay.setRow1("not implemented yet.");
    mDisplay.setRow2("Press 'c' in order");
    mDisplay.setRow3("to return.");
    mDisplay.setRow4(" ");

    connect(this, &Controller::activeChanged, this, [=]() {
        if (mActive) {
            emit activeItemChanged(&mDisplay);
        }
    });
}

void DefaultDisplayController::onAction(Action *action) {}
