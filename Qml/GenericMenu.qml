import QtQuick 2.0

TitledDisplayContainer {
    title: ""
    property string menuId: ""
    property var menuItems: []
    property int currentIndex: -1
    property int firstVisibleIndex: 0
    property int lastVisibleIndex: 6
    property double scrollIndicatorHeight: currentIndex / menuItems.length

    CustomText {
        x: 0
        y: 0
        width: 216
        height: 24
        text: menuId
        horizontalAlignment: Text.AlignRight
    }

    Column {
        x: 0
        y: 25
        Repeater {
            model: menuItems

            GenericMenuItem {
                name: modelData.namePrefix + " " + modelData.name
                selected: index === currentIndex
                visible: firstVisibleIndex <= index && index <= lastVisibleIndex
            }
        }
    }

    Item {
        x: 218
        y: 20
        CustomText {
            x: 0
            y: 0
            text: "▲"
        }

        CustomText {
            x: 0
            y: 24 + 82 * scrollIndicatorHeight
            text: "┃"
        }

        CustomText {
            x: 0
            y: 124
            text: "▼"
        }

        visible: menuItems.length > 5
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.75}D{i:1}D{i:2}D{i:3}D{i:6}D{i:5}D{i:4}D{i:8;locked:true}D{i:9}
D{i:10}D{i:11}D{i:7}
}
##^##*/
