import QtQuick 2.0

Item {
    implicitWidth: background.paintedWidth
    implicitHeight: background.paintedHeight

    id: root
    property bool selected: false
    property string name: ""

    CustomText {
        id: background
        x: 0
        y: 0
        text: selected ? "█".repeat(20) : " "
        color: "#111111"
    }

    CustomText {
        x: 0
        y: 0
        text: name
        color: selected ? "#606853" : "#111111"
    }
}
