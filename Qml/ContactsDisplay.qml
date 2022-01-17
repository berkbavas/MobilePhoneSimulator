import QtQuick 2.0

Item {
    width: 230
    height: 168

    function getTitle(){
        if(contactsController.mode === 0)
            return "Show Contact"
        else if(contactsController.mode === 1)
            return "Call Contact"
        else if(contactsController.mode === 2)
            return "Add Contact"
        else if(contactsController.mode === 3)
            return "Edit Contact"
        else if(contactsController.mode === 4)
            return "Delete Contact"
        else
            return ""
    }

    ContactsList {
        title: getTitle()
        contacts: contactsController.contacts
        currentIndex: contactsController.scrollHandler.currentIndex
        firstVisibleIndex: contactsController.scrollHandler.firstVisibleIndex
        lastVisibleIndex: contactsController.scrollHandler.lastVisibleIndex
        visible: contactsController.currentDisplay === 0
    }

    TitledDisplayContainer {
        title: "Show Contact"

        Column {
            x: 0
            y: 36
            CustomText {
                text : "Name:"
            }

            CustomText {
                text : contactsController.contacts[contactsController.scrollHandler.currentIndex].name
            }

            CustomText {
                text : "Phone Number:"
            }

            CustomText {
                text : contactsController.contacts[contactsController.scrollHandler.currentIndex].phoneNumber
            }
        }

        visible: contactsController.currentDisplay === 1
    }

    TitledDisplayContainer {
        title: "Call Contact"
        visible: contactsController.currentDisplay === 2
    }

    TitledDisplayContainer {
        title: "Add Contact"
        visible: contactsController.currentDisplay === 3
    }

    TitledDisplayContainer {
        title: "Edit Contact"
        visible: contactsController.currentDisplay === 4
    }

    TitledDisplayContainer {
        title: "Delete Contact"
        visible: contactsController.currentDisplay === 5
    }
}
