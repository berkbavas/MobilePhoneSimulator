import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: button
    property string source

    background: Image {
        anchors.fill: button
        source: button.source
        fillMode: Image.PreserveAspectCrop
    }

    onPressed: {
        scaleDownAnimator.running = true
        scaleUpAnimator.running = false
    }

    onReleased: {
        scaleDownAnimator.running = false
        scaleUpAnimator.running = true
    }

    ScaleAnimator {
        id: scaleUpAnimator
        target: button
        from: button.scale
        to: 1
        duration: 50
        running: false
    }

    ScaleAnimator {
        id: scaleDownAnimator
        target: button
        from: button.scale
        to: 0.9
        duration: 50
        running: false
    }
}
