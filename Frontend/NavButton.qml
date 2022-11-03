import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Rectangle{
    id: navButton
    width: parent.width
    height: 60
    color: "transparent"

    property var currentActivButton

    property var listContacts: test.listQML

    property var mapContacts: []

    signal navBtnClicked(int _index)

    ScrollView{
        id: viewNavButtons
        width: parent.width
        height: parent.height
        clip: true

        Row{
            anchors.fill: parent

            Repeater{
                id: repeaterButtons
                model: 4

                Rectangle{
                    id: navBtn
                    border.width: 1
                    color: yellow
                    height: parent.height
                    width: parent.height


                    function setActivButton()
                    {
//                        console.log("width: ", width);
                        currentActivButton.color = "red";
                    }

                    function setNoActivButton()
                    {
                        currentActivButton.color = yellow;
                    }

                    MouseArea{
                        id: mouseNavButton
                        anchors.fill: parent
                        hoverEnabled: true

                        onClicked: {
                            navBtnClicked(index)

                            console.log("navButton" , index);
                            currentActivButton.setNoActivButton();
                            currentActivButton = repeaterButtons.itemAt(index);
                            currentActivButton.setActivButton();

                            if (index === 0)
                            {

//                                console.log("asd: ", parent.);
                            }

    //                        var y = test.getMapListHuman(listContacts);
                        }
                    }
                }
            }
        }
    }


    Component.onCompleted: {
        currentActivButton = repeaterButtons.itemAt(0);
        currentActivButton.setActivButton();

        console.log(mapContacts.key)
    }
}
