import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    visibility: Window.Maximized
    color:  "#ffffff"

    FontLoader {
        source: "../Resources/Fonts/JetBrainsMono-Regular.ttf"
    }

    Container {
        anchors.centerIn: parent
    }
}
