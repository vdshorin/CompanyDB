import QtQuick
import QtQuick.Controls
import QtQuick.Window
import Qt.labs.qmlmodels

import "Frontend"

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
