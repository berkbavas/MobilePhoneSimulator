#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "Controller.h"
#include "MenuController.h"

#include <QMap>
#include <QObject>
#include <QQmlApplicationEngine>

class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);

    Controller *activeController() const;
    void setActiveController(Controller *newActiveController);

public slots:
    void init(QQmlApplicationEngine *engine);
    void onAction(int button, int actionType = -1);

private:
    Controller *mActiveController;
    Controller *mDefaultController;     // C++ -> QML
    Controller *mMainDisplayController; // C++ -> QML
    Controller *mContactsController;    // C++ -> QML
    MenuController *mMenuController;    // C++ -> QML

    QQmlApplicationEngine *mEngine;
    QMap<QString, Controller *> mControllers;
};

#endif // MAINCONTROLLER_H
