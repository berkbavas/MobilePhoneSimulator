QT += quick

SOURCES += \
        src/Action.cpp \
        src/ChangeControllerRequest.cpp \
        src/Contacts/AddContactModeHandler.cpp \
        src/Contacts/CallContactModeHandler.cpp \
        src/Contacts/Contact.cpp \
        src/Contacts/ContactsDisplayController.cpp \
        src/Contacts/DeleteContactModeHandler.cpp \
        src/Contacts/EditContactModeHandler.cpp \
        src/Contacts/ModeHandler.cpp \
        src/Contacts/ShowContactModeHandler.cpp \
        src/Controller.cpp \
        src/DefaultDisplayController.cpp \
        src/Display.cpp \
        src/Helper.cpp \
        src/Item.cpp \
        src/LineEditor/Charset.cpp \
        src/LineEditor/LineEditor.cpp \
        src/MainController.cpp \
        src/MainDisplayController.cpp \
        src/MainMenuController.cpp \
        src/Menu.cpp \
        src/Main.cpp \
        src/Request.cpp \
        src/SimpleMenu.cpp

RESOURCES += MobilePhoneSimulator.qrc

INCLUDEPATH += src

HEADERS += \
    src/Action.h \
    src/ChangeControllerRequest.h \
    src/Contacts/AddContactModeHandler.h \
    src/Contacts/CallContactModeHandler.h \
    src/Contacts/Contact.h \
    src/Contacts/ContactsDisplayController.h \
    src/Contacts/DeleteContactModeHandler.h \
    src/Contacts/EditContactModeHandler.h \
    src/Contacts/ModeHandler.h \
    src/Contacts/ShowContactModeHandler.h \
    src/Controller.h \
    src/DefaultDisplayController.h \
    src/Display.h \
    src/Enums.h \
    src/Helper.h \
    src/Item.h \
    src/LineEditor/Charset.h \
    src/LineEditor/LineEditor.h \
    src/MainController.h \
    src/MainDisplayController.h \
    src/MainMenuController.h \
    src/Menu.h \
    src/Request.h \
    src/SimpleMenu.h
