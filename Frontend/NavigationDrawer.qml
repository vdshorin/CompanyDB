import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Rectangle {
    id: navigationDrawer
    width: parent.width / 5
    height: parent.height
    color: Qt.darker("gray")

    property var listNames: ["Весь", "Постоянный", "Переменный"]
    property string yellow: "#eaff0d"

    Column{
        id: columnNav
        anchors.top: parent.top
        width: parent.width
        //        height: 100
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
            model: 4

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
}

/*##^##
Designer {
    D{i:0;formeditorZoom:3}
}
##^##*/
