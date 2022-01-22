import QtQuick 2.0

DisplayContainer {
    property string title: " "
    property string menuId: " "
    property var rows: []
    property int currentIndex: 0
    property int firstVisibleIndex: 0
    property int lastVisibleIndex: 6
    property double scrollIndicatorHeight: currentIndex / (rows.length - 1.0)

    CustomText {
        text: title
    }

    CustomText {
        x: 0
        y: 10
        text: "▬".repeat(24)
    }

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
            model: rows

            Item {
                implicitWidth: background.paintedWidth
                implicitHeight: background.paintedHeight
                visible: firstVisibleIndex <= index && index <= lastVisibleIndex

                CustomText {
                    id: background
                    x: 0
                    y: 0
                    text: index === currentIndex ? "█".repeat(24) : " "
                    color: "#111111"
                }

                CustomText {
                    x: 0
                    y: 0
                    text: modelData.namePrefix + " " + modelData.name
                    color: index === currentIndex ? "#606853" : "#111111"
                }
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
            y: 20 + 84 * scrollIndicatorHeight
            text: "┃"
        }

        CustomText {
            x: 0
            y: 124
            text: "▼"
        }

        visible: rows.length > 5
    }
}
