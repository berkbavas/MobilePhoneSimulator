import QtQuick 2.0

TitledDisplayContainer {
    property string name: ""
    property var contacts: []
    property int currentIndex: -1
    property int firstVisibleIndex: 0
    property int lastVisibleIndex: 6
    property double scrollIndicatorHeight: currentIndex / contacts.length

    Column {
        x: 0
        y: 25
        Repeater {
            model: contacts

            ContactsListItem {
                name: modelData.name
                selected: index === currentIndex
                visible: firstVisibleIndex <= index && index <= lastVisibleIndex
            }
        }
    }

    Item {
        x: 219
        y: 24
        CustomText {
            x: 0
            y: 0
            text: "▲"
        }

        CustomText {
            x: 0
            y: 24 + 78 * scrollIndicatorHeight
            text: "┃"
        }

        CustomText {
            x: 0
            y: 119
            text: "▼"
        }

        visible: contacts.length > 5
    }
}
