QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Action.cpp \
        Contact.cpp \
        ContactsController.cpp \
        Controller.cpp \
        DefaultController.cpp \
        Helper.cpp \
        MainController.cpp \
        MainDisplayController.cpp \
        Menu.cpp \
        MenuController.cpp \
        ScrollHandler.cpp \
        Main.cpp

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
    ContactsController.h \
    Controller.h \
    DefaultController.h \
    Enums.h \
    Helper.h \
    MainController.h \
    MainDisplayController.h \
    Menu.h \
    MenuController.h \
    ScrollHandler.h
