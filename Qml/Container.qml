import QtQuick 2.0

Item {
    width: 350
    height: 828

    Image {
        x: 0
        y: 0
        width: 350
        height: 828
        source: "qrc:/resources/images/Background.png"
        fillMode: Image.PreserveAspectCrop
    }

    Screen {
        x: 57
        y: 224
        width: 230
        height: 168
    }

    AnimatedButton {
        x: 49
        y: 449
        source: "qrc:/resources/images/C.png"
        onPressed: controller.onAction(12)
    }

    AnimatedButton {
        x: 99
        y: 432
        source: "qrc:/resources/images/Space.png"
        onPressed: controller.onAction(13)
    }

    AnimatedButton {
        x: 252
        y: 450
        source: "qrc:/resources/images/ArrowUp.png"
        onPressed: controller.onAction(14)
    }

    AnimatedButton {
        x: 191
        y: 474
        source: "qrc:/resources/images/ArrowDown.png"
        onPressed: controller.onAction(15)
    }

    AnimatedButton {
        x: 37
        y: 540
        source: "qrc:/resources/images/1.png"
        onPressed: controller.onAction(1)
    }

    AnimatedButton {
        x: 137
        y: 557
        source: "qrc:/resources/images/2.png"
        onPressed: controller.onAction(2)
    }

    AnimatedButton {
        x: 243
        y: 541
        source: "qrc:/resources/images/3.png"
        onPressed: controller.onAction(3)
    }

    AnimatedButton {
        x: 40
        y: 599
        source: "qrc:/resources/images/4.png"
        onPressed: controller.onAction(4)
    }

    AnimatedButton {
        x: 137
        y: 615
        source: "qrc:/resources/images/5.png"
        onPressed: controller.onAction(5)
    }

    AnimatedButton {
        x: 239
        y: 598
        source: "qrc:/resources/images/6.png"
        onPressed: controller.onAction(6)
    }

    AnimatedButton {
        x: 44
        y: 657
        source: "qrc:/resources/images/7.png"
        onPressed: controller.onAction(7)
    }

    AnimatedButton {
        x: 136
        y: 672
        source: "qrc:/resources/images/8.png"
        onPressed: controller.onAction(8)
    }

    AnimatedButton {
        x: 236
        y: 656
        source: "qrc:/resources/images/9.png"
        onPressed: controller.onAction(9)
    }

    AnimatedButton {
        x: 48
        y: 715
        source: "qrc:/resources/images/Star.png"
        onPressed: controller.onAction(10)
    }

    AnimatedButton {
        x: 136
        y: 731
        source: "qrc:/resources/images/0.png"
        onPressed: controller.onAction(0)
    }

    AnimatedButton {
        x: 232
        y: 714
        source: "qrc:/resources/images/Square.png"
        onPressed: controller.onAction(11)
    }
}
