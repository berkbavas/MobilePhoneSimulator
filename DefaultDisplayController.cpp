#include "DefaultDisplayController.h"

DefaultDisplayController::DefaultDisplayController(QObject *parent)
    : Controller{parent}
{
    mDisplay.setTitle("");
    mDisplay.setRow0("This display is not");
    mDisplay.setRow1("implemented yet.");
    mDisplay.setRow2(" ");
    mDisplay.setRow3("Press 'c' in order");
    mDisplay.setRow4("to return.");
    mDisplay.setRow5(" ");
    mDisplay.setRow6(" ");

    connect(this, &Controller::activeChanged, this, [=]() {
        if (mActive) {
            emit activeItemChanged(&mDisplay);
        }
    });
}
