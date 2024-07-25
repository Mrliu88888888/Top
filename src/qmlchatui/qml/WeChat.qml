import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import Qt.labs.platform 1.1

Window {
    id: root
    width: 1250
    height: 800
    minimumWidth: chatMenu.width + chatSearch.width + 500
    minimumHeight: chatSearch.height + 550
    visible: true
    flags: Qt.Window | Qt.FramelessWindowHint

    property int dragX: 0
    property int dragY: 0
    property bool dragging: false

    Rectangle {
        id: chatMenu
        width: 75
        height: parent.height
        x: 0
        y: 0
        color: "#27292D"

        MouseArea {
            anchors.fill: parent
            onPressed: {
                root.dragX = mouseX
                root.dragY = mouseY
                root.dragging = true
            }
            onReleased: root.dragging = false
            onPositionChanged: {
                if (root.dragging) {
                    root.x += mouseX - root.dragX
                    root.y += mouseY - root.dragY
                }
            }
        }
        Column {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            spacing: 15

            MyToolButton {
                width: 45
                height: 45
                base: 1
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/sd.png"
                onMyClicked: {
                    popupAvatar.x = x
                    popupAvatar.y = y
                    popupAvatar.opened ? popupAvatar.close() : popupAvatar.open()
                }

                Popup {
                    id: popupAvatar
                    width: 370
                    height: 300
                    padding: 0
                    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

                    ChatAvatar {
                        anchors.fill: parent
                    }
                }
            }
            MyToolButton {
                width: 45
                height: 45
                base: 0.7
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/chat.png"
            }
            MyToolButton {
                width: 45
                height: 45
                base: 0.7
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/friend.png"
            }
            MyToolButton {
                width: 45
                height: 45
                base: 0.7
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/collect.png"
            }
            MyToolButton {
                width: 45
                height: 45
                base: 0.7
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/wfile.png"
            }
            MyToolButton {
                width: 45
                height: 45
                base: 0.7
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/look.png"
            }
        }
        Column {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            spacing: 15

            MyToolButton {
                width: 45
                height: 45
                base: 0.7
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/applets.png"
            }
            MyToolButton {
                width: 45
                height: 45
                base: 0.7
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/phone.png"
            }
            MyToolButton {
                width: 45
                height: 45
                base: 0.7
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/more.png"
                onMyClicked: popupMore.opened ? popupMore.close() : popupMore.open()

                Popup {
                    id: popupMore
                    x: parent.width + (chatMenu.width - parent.width) / 2 + 1
                    y: parent.height - height
                    width: 170
                    height: 180
                    padding: 0
                    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

                    Column {
                        width: parent.width

                        MyToolButton {
                            width: parent.width
                            height: 60
                            enteredColor: "#2F2F33"
                            exitedColor: "#2A2A2A"
                            Text {
                                anchors.left: parent.left
                                anchors.leftMargin: 5
                                anchors.verticalCenter: parent.verticalCenter
                                text: "迁移与备份"
                                color: "#8C8C8C"
                                font.pointSize: 10
                            }
                        }
                        MyToolButton {
                            width: parent.width
                            height: 60
                            enteredColor: "#2F2F33"
                            exitedColor: "#2A2A2A"
                            Text {
                                anchors.left: parent.left
                                anchors.leftMargin: 5
                                anchors.verticalCenter: parent.verticalCenter
                                text: "意见反馈"
                                color: "#8C8C8C"
                                font.pointSize: 10
                            }
                        }
                        MyToolButton {
                            width: parent.width
                            height: 60
                            enteredColor: "#2F2F33"
                            exitedColor: "#2A2A2A"
                            Text {
                                anchors.left: parent.left
                                anchors.leftMargin: 5
                                anchors.verticalCenter: parent.verticalCenter
                                text: "设置"
                                color: "#8C8C8C"
                                font.pointSize: 10
                            }
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: chatSearch
        width: 315
        height: 80
        anchors.left: chatMenu.right
        anchors.top: chatMenu.top
        color: "#ECE9E8"

        Row {
            anchors.centerIn: parent
            spacing: 5

            TextField {
                width: 240
                height: 30
                leftPadding: 30
                placeholderText: "搜索"

                Image {
                    width: 20
                    height: 20
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    source: "qrc:/chat/res/chat/search.png"
                }
            }
            Image {
                width: 30
                height: 30
                source: "qrc:/chat/res/chat/add.png"
            }
        }
    }

    ListView {
        id: listView
        anchors.left: chatMenu.right
        anchors.top: chatSearch.bottom
        anchors.bottom: parent.bottom
        width: chatSearch.width
        clip: true

        delegate: Rectangle {
            property bool isHover: false
            width: parent.width
            height: 80
            color: {
                if (listView.currentIndex === index)
                    return "#C3C3C5"
                if (isHover)
                    return "#DBD9D9"
                return "#E7E6E5"
            }

            Image {
                id: img
                width: 50
                height: 50
                x: 15
                y: 15
                source: model.img
            }
            Text {
                anchors.top: img.top
                anchors.left: img.right
                anchors.leftMargin: 15
                text: model.name
            }
            Text {
                anchors.bottom: img.bottom
                anchors.left: img.right
                anchors.leftMargin: 15
                text: model.msg
            }
            Text {
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.rightMargin: 15
                anchors.topMargin: 15
                text: model.time
            }
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: isHover = true
                onExited: isHover = false
                onClicked: listView.currentIndex = index
            }
        }

        model: ListModel {
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
            ListElement { img: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "now" }
        }
    }

    Rectangle {
        id: chatTool
        anchors.left: chatSearch.right
        anchors.top: chatSearch.top
        anchors.right: parent.right
        anchors.bottom: chatSearch.bottom
        color: "#F5F5F5"
        border.width: 1
        border.color: "#E7E7E7"

        MouseArea {
            anchors.fill: parent
            onPressed: {
                root.dragX = mouseX
                root.dragY = mouseY
                root.dragging = true
            }
            onReleased: root.dragging = false
            onPositionChanged: {
                if (root.dragging) {
                    root.x += mouseX - root.dragX
                    root.y += mouseY - root.dragY
                }
            }
        }
        Text {
            id: chatCurrentName
            x: 40
            y: 30
            text: "小孟同学"
            font.pointSize: 15
        }
        MyToolButton {
            id: btnPin
            width: 40
            height: 35
            anchors.top: parent.top
            anchors.right: btnMin.left
            iconImage: "qrc:/chat/res/chat/pin.png"
            onMyClicked: {
                if ((root.flags & Qt.WindowStaysOnTopHint) === 0) {
                    root.flags |= Qt.WindowStaysOnTopHint
                    color = "#E9E9E9"
                    exitedColor = "#E9E9E9"
                } else {
                    root.flags &= ~Qt.WindowStaysOnTopHint
                    color = "#00000000"
                    exitedColor = "#00000000"
                }
            }
        }
        MyToolButton {
            id: btnMin
            width: 40
            height: 35
            anchors.top: parent.top
            anchors.right: btnMax.left
            iconImage: "qrc:/chat/res/chat/min.png"
            onMyClicked: root.showMinimized()
        }
        MyToolButton {
            id: btnMax
            width: 40
            height: 35
            anchors.top: parent.top
            anchors.right: btnClose.left
            iconImage: Window.Maximized === root.visibility ? "qrc:/chat/res/chat/max2.png" : "qrc:/chat/res/chat/max.png"
            onMyClicked: Window.Maximized === root.visibility ? root.showNormal() : root.showMaximized()
        }
        MyToolButton {
            id: btnClose
            width: 40
            height: 35
            anchors.top: parent.top
            anchors.right: parent.right
            iconImage: "qrc:/chat/res/chat/close.png"
            enteredColor: "#FA5151"
            onMyClicked: Qt.quit()
        }
    }

    Rectangle {
        id: chatWin
        width: chatTool.width
        anchors.top: chatTool.bottom
        anchors.right: parent.right
        anchors.bottom: chatInput.top
        color: "#F5F5F5"
    }

    Rectangle {
        id: chatInput
        width: chatTool.width
        height: 150
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        border.color: "#D9D9D9"
        border.width: 1

        Button {
            id: send
            width: 85
            height: 35
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 50
            anchors.bottomMargin: 5
            text: "发送(S)"
            font.pointSize: 10

            Rectangle {
                anchors.fill: parent
                color: "#F5F5F5"

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: parent.color = "#129611"
                    onExited: parent.color = "#F5F5F5"
                }
            }
        }

        TextArea {
            anchors.top: inputBar.bottom
            anchors.bottom: send.top
            anchors.left: inputBar.left
            anchors.right: send.right
            anchors.topMargin: 5
            anchors.bottomMargin: 5
        }

        Row {
            id: inputBar
            x: 30
            y: 15
            height: 30
            spacing: 10

            MyToolButton {
                width: parent.height
                height: parent.height
                base: 0.9
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/emj.png"
            }
            MyToolButton {
                width: parent.height
                height: parent.height
                base: 0.9
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/file.png"
            }
            MyToolButton {
                width: parent.height
                height: parent.height
                base: 0.9
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/screenshot.png"
            }
            MyToolButton {
                width: parent.height
                height: parent.height
                base: 0.9
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/record.png"
            }
        }
    }

    Rectangle {
        width: 10
        height: 10
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 1
        anchors.bottomMargin: 1
        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.SizeFDiagCursor
            onPositionChanged: {
                const newWidth = root.width + mouseX
                if (newWidth >= root.minimumWidth)
                    root.width = newWidth
                const newHeight = root.height + mouseY
                if (newHeight >= root.minimumHeight)
                    root.height = newHeight
            }
        }
    }

    SystemTrayIcon {
        visible: true
        iconSource: "qrc:/chat/res/chat/chat.png"
        tooltip: "WeChat"
        menu: Menu {
            MenuItem {
                text: "退出"
                onTriggered: Qt.quit()
            }
        }
        onActivated: (reason)=> {
            if(reason === SystemTrayIcon.Trigger){
                root.show()
                root.raise()
                root.requestActivate()
            }
        }
    }
}
