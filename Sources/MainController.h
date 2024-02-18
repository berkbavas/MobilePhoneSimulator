#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "Controller.h"
#include "MainMenuController.h"

#include <QMap>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QTimer>

class MainController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Item *activeItem READ activeItem WRITE setActiveItem NOTIFY activeItemChanged)

public:
    explicit MainController(QObject *parent = nullptr);

    Controller *activeController() const;
    void setActiveController(Controller *newActiveController);

    Item *activeItem() const;
    void setActiveItem(Item *newActiveItem);

public slots:
    void init(QQmlApplicationEngine *engine);
    void onAction(int button, int actionType = -1);
    void update();

private slots:
    void onRequestCreated(Request *request);

signals:
    void activeItemChanged();

private:
    Controller *mActiveController;
    Controller *mDefaultDisplayController;
    Controller *mMainDisplayController;
    Controller *mContactsDisplayController;
    MainMenuController *mMainMenuController;

    Item *mActiveItem; // C++ -> QML

    QQmlApplicationEngine *mEngine;
    QMap<QString, Controller *> mControllers;

    QTimer mTimer;
    quint64 mCurrentTime;
    quint64 mPreviousTime;
    quint64 mSimulationTime;

    LineEditor *mLineEditor;
};

#endif // MAINCONTROLLER_H
