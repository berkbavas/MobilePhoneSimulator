#include "DefaultDisplayController.h"

DefaultDisplayController::DefaultDisplayController(QObject *parent)
    : Controller{parent}
{
    mDisplay.setTitle("");
    mDisplay.setRow(0, "This display is not");
    mDisplay.setRow(1, "implemented yet.");
    mDisplay.setRow(3, "Press 'c' in order");
    mDisplay.setRow(4, "to return.");

    connect(this, &Controller::activeChanged, this, [=]() {
        if (mActive)
        {
            emit activeItemChanged(&mDisplay);
        }
    });
}
