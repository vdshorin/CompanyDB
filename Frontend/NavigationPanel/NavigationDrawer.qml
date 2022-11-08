import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Rectangle {
    id: root
//    width: parent.width / coefReduced
    height: parent.height
    color: Qt.darker("gray")

    property var listNames: ["Весь", "Постоянный", "Переменный"]
    property string yellow: "#eaff0d"

    property int coefReduced: 15
    property int coefExpanded: 5

    state: mouseAreaHover.hovered ? "expanded" : "reduced"

    Column {
        id: columnNav
        anchors.top: parent.top
        width: parent.width
        spacing: 5

        Text {
            width: parent.width
            color: yellow
            text: qsTr("Личный состав")
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Separator {
        }

        Repeater{
            model: listNames.length

            Structure {

            }
        }

        Separator{
        }
    }

    Rectangle{
        id: idProfile
        anchors.bottom: parent.bottom
        width: parent.width
        height: 30
        color: "black"

        Text {
            color: "#ffffff"
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "5 рота\nст. л-т Воробьев Е.В."
        }
    }

    NavButton {
        id: navButton
        anchors.bottom: idProfile.top
    }

    HoverHandler {
        id: mouseAreaHover
        acceptedDevices: PointerDevice.AllDevices
        target: root
    }

    states: [
        State {
            name: "reduced"

            PropertyChanges {
                target: root;
                width: root.parent.width / coefReduced;
            }
        },

        State {
            name: "expanded"

            PropertyChanges {
                target: root;
                width: root.parent.width / coefExpanded;
            }


        }

    ]

    transitions: [
        Transition {
            from: "reduced"
            to: "expanded"
            NumberAnimation {
                duration: 200;
                properties: "width"
            }
        },

        Transition {
            from: "expanded"
            to: "reduced"
            NumberAnimation {
                duration: 200;
                properties: "width"
            }
        }
    ]
}

/*##^##
Designer {
    D{i:0;formeditorZoom:3}
}
##^##*/
