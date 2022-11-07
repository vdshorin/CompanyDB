import QtQuick
import QtQuick.Controls
import QtQuick.Window
import Qt.labs.qmlmodels

import "Frontend"

//Window {
//    id: screen
//    width: 800
//    height: 600
//    visible: true

//    Button {
//        anchors.centerIn: parent
//        text: qsTr("Button")
//        onClicked: {
//            console.log("Button was clicked");
//        }
//        z: 100
//        MouseArea {
//                anchors.fill: parent
////                acceptedButtons: Qt.RightButton
//                onClicked: {
//                    console.log("Button  button was clicked");
//                    mouse.accepted = true
//                }
//            }
//    }

//    MouseArea {
//            anchors.fill: parent
////            acceptedButtons: Qt.RightButton
//            propagateComposedEvents: true
//            onClicked: {
//                console.log("Window  button was clicked")
//            }
//            z: 99
//        }
//}

ApplicationWindow {
    id: appWindow
    width: 1280
    height: 720
    visible: true
    title: qsTr("Hello World")
    color: Qt.lighter("blue")

    AppHeader {
        id: appHeader
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
    }

    NavigationDrawer {
        id: navigationDrawer
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.top: appHeader.bottom
    }


//    Table {
//    }
}
