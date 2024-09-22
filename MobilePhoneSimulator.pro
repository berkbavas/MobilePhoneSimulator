QT += quick

SOURCES += \
        Source/Action.cpp \
        Source/ChangeControllerRequest.cpp \
        Source/Contacts/AddContactModeHandler.cpp \
        Source/Contacts/CallContactModeHandler.cpp \
        Source/Contacts/Contact.cpp \
        Source/Contacts/ContactsDisplayController.cpp \
        Source/Contacts/DeleteContactModeHandler.cpp \
        Source/Contacts/EditContactModeHandler.cpp \
        Source/Contacts/ModeHandler.cpp \
        Source/Contacts/ShowContactModeHandler.cpp \
        Source/Controller.cpp \
        Source/DefaultDisplayController.cpp \
        Source/Display.cpp \
        Source/Helper.cpp \
        Source/Item.cpp \
        Source/LineEditor/Charset.cpp \
        Source/LineEditor/LineEditor.cpp \
        Source/MainController.cpp \
        Source/MainDisplayController.cpp \
        Source/MainMenuController.cpp \
        Source/Menu.cpp \
        Source/Main.cpp \
        Source/Request.cpp \
        Source/SimpleMenu.cpp

RESOURCES += MobilePhoneSimulator.qrc

INCLUDEPATH += Source

HEADERS += \
    Source/Action.h \
    Source/ChangeControllerRequest.h \
    Source/Contacts/AddContactModeHandler.h \
    Source/Contacts/CallContactModeHandler.h \
    Source/Contacts/Contact.h \
    Source/Contacts/ContactsDisplayController.h \
    Source/Contacts/DeleteContactModeHandler.h \
    Source/Contacts/EditContactModeHandler.h \
    Source/Contacts/ModeHandler.h \
    Source/Contacts/ShowContactModeHandler.h \
    Source/Controller.h \
    Source/DefaultDisplayController.h \
    Source/Display.h \
    Source/Enums.h \
    Source/Helper.h \
    Source/Item.h \
    Source/LineEditor/Charset.h \
    Source/LineEditor/LineEditor.h \
    Source/MainController.h \
    Source/MainDisplayController.h \
    Source/MainMenuController.h \
    Source/Menu.h \
    Source/Request.h \
    Source/SimpleMenu.h
