QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Action.cpp \
        Contact.cpp \
        ContactsDisplayController.cpp \
        Controller.cpp \
        DefaultDisplayController.cpp \
        Display.cpp \
        Helper.cpp \
        Item.cpp \
        MainController.cpp \
        MainDisplayController.cpp \
        MainMenuController.cpp \
        Menu.cpp \
        Main.cpp \
        SimpleMenu.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Action.h \
    Contact.h \
    ContactsDisplayController.h \
    Controller.h \
    DefaultDisplayController.h \
    Display.h \
    Enums.h \
    Helper.h \
    Item.h \
    MainController.h \
    MainDisplayController.h \
    MainMenuController.h \
    Menu.h \
    SimpleMenu.h
