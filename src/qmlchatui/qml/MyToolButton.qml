import QtQuick 2.12
import QtQuick.Controls 2.5

Rectangle {
    property color enteredColor: "#E5E5E5"
    property color exitedColor: "#00000000"
    property url iconImage: ""
    property real base: 0.5
    signal myClicked(real x, real y)

    color: exitedColor

    Image {
        anchors.centerIn: parent
        width: parent.width * base
        height: parent.height * base
        source: iconImage
    }
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: parent.color = enteredColor
        onExited: parent.color = exitedColor
        onClicked: {
            myClicked(mouseX, mouseY)
        }
    }
}
