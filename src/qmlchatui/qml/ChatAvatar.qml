import QtQuick 2.12

Item {
    Item {
        anchors.fill: parent
        anchors.margins: 40

        Image {
            id: avatar
            anchors.right: parent.right
            anchors.top: parent.top
            width: 75
            height: 75
            source: "qrc:/chat/res/chat/sd.png"
        }

        Column {
            anchors.top: avatar.top
            anchors.left: parent.left
            spacing: 20

            Row {
                spacing: 3
                Text {
                    id: name
                    text: "lm"
                }
                Image {
                    width: name.width
                    height: name.height
                    source: "qrc:/chat/res/chat/man.png"
                }
            }

            Text {
                text: "微信号: HelloWorld"
            }
        }

        Rectangle {
            id: line
            anchors.centerIn: parent
            width: parent.width
            height: 1
            color: "#F4F4F4"
        }

        Row {
            anchors.top: line.bottom
            anchors.left: line.left
            anchors.topMargin: 30
            spacing: 10

            Text {
                text: "地区"
            }
            Text {
                text: "冰岛"
            }
        }

        Row {
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            spacing: 5

            Image {
                width: 45
                height: 45
                source: "qrc:/chat/res/chat/man.png"
            }
            Image {
                width: 45
                height: 45
                source: "qrc:/chat/res/chat/man.png"
            }
        }
    }
}
