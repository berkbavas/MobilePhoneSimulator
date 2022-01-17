import QtQuick 2.0

Item {
    width: 230
    height: 168

    property string title: ""

    CustomText {
        text: title
    }

    CustomText {
        x: 0
        y: 10
        text: "▬".repeat(20)
    }
}
