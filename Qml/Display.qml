import QtQuick 2.0

DisplayContainer {

    property string title: " "
    property string row0: " "
    property string row1: " "
    property string row2: " "
    property string row3: " "
    property string row4: " "

    CustomText {
        text: title
    }

    CustomText {
        x: 0
        y: 10
        text: title.length === 0 ? "" : "▬".repeat(20)
    }

    Column {
        x: 0
        y: 25

        CustomText {
            text: row0
        }

        CustomText {
            text: row1
        }

        CustomText {
            text: row2
        }

        CustomText {
            text: row3
        }

        CustomText {
            text: row4
        }
    }
}
