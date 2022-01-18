import QtQuick 2.0

Item {
    width: 230
    height: 168

    function getItemType() {
        if(controller.activeItem  === null)
            return -1
        else
            return controller.activeItem.type
    }

    MainMenu {
        title:  getItemType() === 0 ?  controller.activeItem.title : ""
        menuId: getItemType() === 0 ?  controller.activeItem.id : ""
        rows:  getItemType() === 0 ?  controller.activeItem.children : []
        currentIndex: getItemType() === 0 ?  controller.activeItem.currentIndex : 0
        firstVisibleIndex: getItemType() === 0 ?  controller.activeItem.firstVisibleIndex : 0
        lastVisibleIndex: getItemType() === 0 ?  controller.activeItem.lastVisibleIndex : 0
        visible: getItemType() === 0
    }

    SimpleMenu {
        title:  getItemType() === 1 ?  controller.activeItem.title : ""
        rows:  getItemType() === 1 ?  controller.activeItem.rows : []
        currentIndex: getItemType() === 1 ?  controller.activeItem.currentIndex : 0
        firstVisibleIndex: getItemType() === 1 ?  controller.activeItem.firstVisibleIndex : 0
        lastVisibleIndex: getItemType() === 1 ?  controller.activeItem.lastVisibleIndex : 0
        visible: getItemType() === 1
    }

    Display {
        title: getItemType() === 2 ?  controller.activeItem.title : ""
        row0: getItemType() === 2 ?  controller.activeItem.row0 : " "
        row1: getItemType() === 2 ?  controller.activeItem.row1 : " "
        row2: getItemType() === 2 ?  controller.activeItem.row2 : " "
        row3: getItemType() === 2 ?  controller.activeItem.row3 : " "
        row4: getItemType() === 2 ?  controller.activeItem.row4 : " "
        row5: getItemType() === 2 ?  controller.activeItem.row5 : " "
        row6: getItemType() === 2 ?  controller.activeItem.row6 : " "
        visible: getItemType() === 2
    }
}
