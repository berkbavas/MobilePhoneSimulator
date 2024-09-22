import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    visibility: Window.Maximized
    color:  "#ffffff"

    FontLoader {
        source: "qrc:/Resources/Fonts/JetBrains/JetBrainsMono-Regular.ttf"
    }

    Container {
        anchors.centerIn: parent
        scale: 0.9 * Math.min(parent.width / 350, parent.height / 828);
    }
}
