QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Sources/Action.cpp \
        Sources/ChangeControllerRequest.cpp \
        Sources/Contacts/AddContactModeHandler.cpp \
        Sources/Contacts/CallContactModeHandler.cpp \
        Sources/Contacts/Contact.cpp \
        Sources/Contacts/ContactsDisplayController.cpp \
        Sources/Contacts/DeleteContactModeHandler.cpp \
        Sources/Contacts/EditContactModeHandler.cpp \
        Sources/Contacts/ModeHandler.cpp \
        Sources/Contacts/ShowContactModeHandler.cpp \
        Sources/Controller.cpp \
        Sources/DefaultDisplayController.cpp \
        Sources/Display.cpp \
        Sources/Helper.cpp \
        Sources/Item.cpp \
        Sources/LineEditor/Charset.cpp \
        Sources/LineEditor/LineEditor.cpp \
        Sources/MainController.cpp \
        Sources/MainDisplayController.cpp \
        Sources/MainMenuController.cpp \
        Sources/Menu.cpp \
        Sources/Main.cpp \
        Sources/Request.cpp \
        Sources/SimpleMenu.cpp

RESOURCES += Resources.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += Sources

HEADERS += \
    Sources/Action.h \
    Sources/ChangeControllerRequest.h \
    Sources/Contacts/AddContactModeHandler.h \
    Sources/Contacts/CallContactModeHandler.h \
    Sources/Contacts/Contact.h \
    Sources/Contacts/ContactsDisplayController.h \
    Sources/Contacts/DeleteContactModeHandler.h \
    Sources/Contacts/EditContactModeHandler.h \
    Sources/Contacts/ModeHandler.h \
    Sources/Contacts/ShowContactModeHandler.h \
    Sources/Controller.h \
    Sources/DefaultDisplayController.h \
    Sources/Display.h \
    Sources/Enums.h \
    Sources/Helper.h \
    Sources/Item.h \
    Sources/LineEditor/Charset.h \
    Sources/LineEditor/LineEditor.h \
    Sources/MainController.h \
    Sources/MainDisplayController.h \
    Sources/MainMenuController.h \
    Sources/Menu.h \
    Sources/Request.h \
    Sources/SimpleMenu.h
