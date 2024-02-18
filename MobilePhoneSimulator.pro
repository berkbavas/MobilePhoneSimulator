QT += quick

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

RESOURCES += MobilePhoneSimulator.qrc

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