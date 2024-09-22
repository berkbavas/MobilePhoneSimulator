import QtQuick 2.0

DisplayContainer {

    property string title: " "
    property var rows: []

    CustomText {
        text: title
    }

    CustomText {
        x: 0
        y: 10
        text: title.length === 0 ? "" : "▬".repeat(25)
    }

    Column {
        x: 0
        y: 25

        Repeater {
            model: rows

            CustomText {
                text: modelData
            }
        }
    }
}
