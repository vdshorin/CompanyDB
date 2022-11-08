import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Rectangle{
    width: parent.width
    height: 40
    color: mouseRep.containsMouse ? Qt.darker(Qt.darker("gray")) : Qt.darker("gray")

    Text {
        text: listNames[index]
        width: parent.width
        color: yellow
//        font.bold: true
        font.pixelSize: 24
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    MouseArea{
        id: mouseRep
        anchors.fill: parent

        hoverEnabled: true
        onClicked: {
            console.log("click", index);
        }
    }
}
