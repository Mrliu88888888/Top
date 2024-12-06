import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    title: Qt.application.name + ' ' + Qt.application.version
    visible: true
    width: 1400
    height: 800 

    Text {
        anchors.centerIn: parent
        text: "Hello World"
        font.pointSize: 20
        color: "lightgreen"
    }
}
