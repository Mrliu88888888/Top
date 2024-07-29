import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import Qt.labs.platform 1.1
import QtQuick.Dialogs 1.3
import QtQuick.Controls 1.4 as QCtl1
import QtQuick.Controls.Styles 1.4 as QCtlStyle1
import QtQml 2.12

import Top 1.0

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
            MyToolButton {
                width: 30
                height: 30
                iconImage: "qrc:/chat/res/chat/add.png"

                onMyClicked: {
                    chatListModel.addChat("qml", "hello")
                }
            }
            // MyToolButton {
            //     width: 30
            //     height: 30
            //     iconImage: "qrc:/chat/res/chat/min.png"
            //
            //     onMyClicked: {
            //         chatListModel.removeChat(listView.currentIndex)
            //     }
            // }
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
                source: model.avatar
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
        model: chatListModel
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
            onMyClicked: root.hide()
        }
    }

    Rectangle {
        id: chatWin
        width: chatTool.width
        anchors.top: chatTool.bottom
        anchors.right: parent.right
        anchors.bottom: chatInput.top
        color: "#F5F5F5"

        ListView {
            id: lvChatRecord
            anchors.fill: parent
            width: parent.width
            clip: true

            delegate: Rectangle {
                width: parent.width
                height: (msg.height < 50) ? 50 : msg.height + 20
                Image {
                    id: avatar
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.rightMargin: 5
                    width: 45
                    height: 45
                    source: model.avatar
                }
                Canvas {
                    anchors.right: avatar.left
                    anchors.verticalCenter: avatar.verticalCenter
                    width: msg.width + 20
                    height: parent.height - 5
                    onPaint: {
                        var p = getContext("2d")
                        p.beginPath()
                        p.moveTo(0, 0)
                        p.lineTo(width - 10, 0)
                        p.lineTo(width - 10, height / 2 - 5)
                        p.lineTo(width, height / 2)
                        p.lineTo(width - 10, height / 2 + 5)
                        p.lineTo(width - 10, height)
                        p.lineTo(0, height)
                        p.closePath()
                        p.fillStyle = "#9EEA6A"
                        p.fill()
                    }

                    Text {
                        id: msg
                        anchors.centerIn: parent
                        rightPadding: 10
                        text: model.msg
                    }
                }
            }

            model: ListModel {
                id: chatRecordModel
                ListElement { avatar: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello"; time: "20220709" }
                ListElement { avatar: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "hello world"; time: "20220709" }
                ListElement { avatar: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "你好啊 小孟"; time: "20220709" }
                ListElement { avatar: "qrc:/chat/res/chat/sd.png"; name: "jane"; msg: "居居 居居 居居！！！"; time: "20220709" }
            }

            function add(msg) {
                chatRecordModel.append(
                    { avatar: "qrc:/chat/res/chat/sd.png", name: "jane", msg: msg, time: "20220709" })
            }
        }
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

                Popup {
                    id: emptyMsgTips
                    x: -width / 2 + parent.width / 2
                    y: -height
                    width: 150
                    height: 45
                    padding: 0
                    bottomInset: 10
                    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

                    Canvas {
                        anchors.fill: parent
                        onPaint: {
                            var p = getContext("2d")
                            p.beginPath()
                            p.moveTo(0, 0)
                            p.lineTo(width, 0)
                            p.lineTo(width, height - 10)
                            p.lineTo(width / 2 + 5, height - 10)
                            p.lineTo(width / 2, height)
                            p.lineTo(width / 2 - 5, height - 10)
                            p.lineTo(0, height - 10)
                            p.closePath()
                            p.fillStyle = "#F5F5F5"
                            p.fill()
                        }

                        Text {
                            anchors.top: parent.top
                            anchors.topMargin: 10
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: "不能发送空白消息"
                            font.pointSize: 10
                        }
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: parent.color = "#129611"
                    onExited: parent.color = "#F5F5F5"
                    onClicked: {
                        if ("" === userInput.text) {
                            emptyMsgTips.open()
                            return
                        }
                        lvChatRecord.add(userInput.text)
                        userInput.text = ""
                        lvChatRecord.positionViewAtEnd()
                    }
                }
            }
        }

        TextArea {
            id: userInput
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
                onMyClicked: {
                    if (popupEmj.opened) {
                        popupEmj.close()
                    } else {
                        loadEmj.visible = true
                        tmr.start()
                    }
                }

                Timer {
                    id: tmr
                    interval: 3000
                    onTriggered: {
                        loadEmj.visible = false
                        popupEmj.open()
                    }
                }

                Image {
                    id: loadEmj
                    visible: false
                    anchors.centerIn: parent
                    source: "qrc:/chat/res/chat/emj.png"

                    RotationAnimation {
                        running: loadEmj.visible
                        target: loadEmj
                        from: 0
                        to: 360
                        loops: Animation.Infinite
                        duration: 1000
                    }

                    Text {
                        anchors.centerIn: parent
                        text: "加载中..."
                    }
                }

                Popup {
                    id: popupEmj
                    x: -width / 2 + parent.width / 2
                    y: -height
                    width: 470
                    height: 480
                    padding: 0
                    bottomInset: 10
                    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

                    Item {
                        anchors.fill: parent

                        Canvas {
                            anchors.fill: parent
                            onPaint: {
                                var p = getContext("2d")
                                p.beginPath()
                                p.moveTo(0, 0)
                                p.lineTo(width, 0)
                                p.lineTo(width, height - 10)
                                p.lineTo(width / 2 + 10, height - 10)
                                p.lineTo(width / 2, height)
                                p.lineTo(width / 2 - 10, height -10)
                                p.lineTo(0, height - 10)
                                p.closePath()
                                p.fillStyle = "#E8E8E8"
                                p.fill()
                            }

                            QCtl1.TabView {
                                anchors.fill: parent
                                anchors.bottomMargin: 10
                                tabPosition: Qt.BottomEdge
                                style: QCtlStyle1.TabViewStyle {
                                    tab: Rectangle {
                                        implicitWidth: 75
                                        implicitHeight: 50
                                        color: styleData.selected ? "#FFFFFF" : "#F5F5F5"
                                        Image {
                                            anchors.centerIn: parent
                                            width: 35
                                            height: 35
                                            source: styleData.title
                                        }
                                    }
                                }

                                QCtl1.Tab {
                                    title: "qrc:/chat/res/chat/emj1.png"
                                    Rectangle {
                                        color: "#FFFFFF"
                                        Flow {
                                            anchors.fill: parent
                                            anchors.margins: 10
                                            spacing: 1
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                            Image { width: 40; height: 40; source: "qrc:/chat/res/chat/emj1.png" }
                                        }
                                    }
                                }
                                QCtl1.Tab {
                                    title: "qrc:/chat/res/chat/emj2.png"
                                    Rectangle { color: "#FFFFFF" }
                                }
                                QCtl1.Tab {
                                    title: "qrc:/chat/res/chat/emj3.png"
                                    Rectangle { color: "#FFFFFF" }
                                }
                                QCtl1.Tab {
                                    title: "qrc:/chat/res/chat/emj3.png"
                                    Rectangle { color: "#FFFFFF" }
                                }
                            }
                        }
                    }
                }
            }
            MyToolButton {
                width: parent.height
                height: parent.height
                base: 0.9
                enteredColor: "#00000000"
                iconImage: "qrc:/chat/res/chat/file.png"
                onMyClicked: selectFile.open()

                FileDialog {
                    id: selectFile
                    folder: shortcuts.desktop
                }
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
                text: "重启"
                onTriggered: Qt.exit(100)
            }
            MenuItem {
                text: "退出"
                onTriggered: Qt.quit()
            }
        }
        onActivated: (reason)=> {
            if (reason === SystemTrayIcon.Trigger) {
                root.show()
                root.raise()
                root.requestActivate()
            }
        }
    }

    Text {
        anchors.left: parent.left
        anchors.top: parent.top
        text: "fps:%1".arg(fps_item.fps)
        color: "white"

        FpsItem {
            id: fps_item
        }
    }
}
