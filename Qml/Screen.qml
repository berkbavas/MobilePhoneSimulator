import QtQuick 2.0

Item {
    width: 230
    height: 168

    GenericMenu {
        title: menuController.activeMenu !== null ? menuController.activeMenu.title : ""
        menuId: menuController.activeMenu !== null ? menuController.activeMenu.id : ""
        menuItems: menuController.activeMenu !== null ? menuController.activeMenu.children : []
        currentIndex: menuController.activeMenu !== null ? menuController.activeMenu.scrollHandler.currentIndex : 0
        firstVisibleIndex: menuController.activeMenu !== null ? menuController.activeMenu.scrollHandler.firstVisibleIndex : 0
        lastVisibleIndex: menuController.activeMenu !== null ? menuController.activeMenu.scrollHandler.lastVisibleIndex : 0
        visible: menuController.active
    }

    MainDisplay {
        visible: mainDisplayController.active
    }

    DefaultDisplay {
        visible: defaultDisplayController.active
    }

    ContactsDisplay {
        visible: contactsController.active
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.5;height:480;width:640}D{i:2}D{i:3}D{i:4}D{i:5}
D{i:1}
}
##^##*/
