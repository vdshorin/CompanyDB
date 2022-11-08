import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Rectangle {
    id: root
    width: parent.width
    height: 60
    color: "transparent"

    property var currentActiveButton
    readonly property var firstItem: lvButtons.itemAtIndex(0)

    property color prevNavBtn: "black"
    readonly property color defaultNavBtn: "yellow"
    readonly property color currentNavBtn: "lightsteelblue"

//    property var listContacts: test.listQML

//    property var mapContacts: []

    signal navBtnClicked(int index)

    ListView {
//        ListElement {}
        id: lvButtons
        anchors { fill: parent; margins: 2}
        orientation: ListView.Horizontal
        clip: true
        spacing: 2


        model: pages
        delegate: delegateBtn2
    }

    Component.onCompleted: {
        currentActiveButton = lvButtons.itemAtIndex(0);
        currentActiveButton.setActiveButton();

        console.log(mapContacts.key)
    }

    Component {
        id: delegateBtn2

        Rectangle {
            height: parent.height
            width: parent.height

            border.width: 1
            color: defaultNavBtn

            Image {
                id: navBtn

                source: pageIcon
                fillMode: Image.PreserveAspectFit
    //            color: defaultNavBtn

                height: parent.height
                width: parent.height
                anchors.margins: 7

                function setActiveButton() {
                    //console.log("width: ", width);
    //                currentActiveButton.color = currentNavBtn;
    //                prevNavBtn = currentActiveButton.color;
                }

                function setNoActiveButton() {
    //                currentActiveButton.color = yellow;
                }

                MouseArea{
                    id: mouseNavButton
                    anchors.fill: parent
                    hoverEnabled: true

                    onClicked: {
                    navBtnClicked(index)

                    console.log("navButton" , index);
                    currentActiveButton.setNoActiveButton();
                    currentActiveButton = lvButtons.itemAtIndex(index);
                    currentActiveButton.setActiveButton();

                    if (index === 0) {
                        //console.log("asd: ", parent.);
                    }
                    //var y = test.getMapListHuman(listContacts);
                    }

                    onEntered: {
    //                    navBtn.color = Qt.lighter(navBtn.color)
                    }

                    onExited: {
    //                    navBtn.color = lvButtons.itemAtIndex(index) === currentActiveButton
    //                        ? currentNavBtn : defaultNavBtn
                    }
                }
            }
        }
    }

    Component {
        id: delegateBtn
        Rectangle {
            id: navBtn
            border.width: 1

            color: defaultNavBtn

            height: parent.height
            width: parent.height

            function setActiveButton() {
                //console.log("width: ", width);
                currentActiveButton.color = currentNavBtn;
                prevNavBtn = currentActiveButton.color;
            }

            function setNoActiveButton()                {
                currentActiveButton.color = yellow;
            }

            MouseArea{
                id: mouseNavButton
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                navBtnClicked(index)

                console.log("navButton" , index);
                currentActiveButton.setNoActiveButton();
                currentActiveButton = lvButtons.itemAtIndex(index);
                currentActiveButton.setActiveButton();

                if (index === 0) {
                    //console.log("asd: ", parent.);
                }
                //var y = test.getMapListHuman(listContacts);
                }

                onEntered: {
                    navBtn.color = Qt.lighter(navBtn.color)
                }

                onExited: {
                    navBtn.color = lvButtons.itemAtIndex(index) === currentActiveButton
                        ? currentNavBtn : defaultNavBtn
                }
            }
        }
    }

    ListModel {
        id: pages

        ListElement {
            pageIcon: "qrc:/Resources/users.png"
        }

        ListElement {
            pageIcon: "qrc:/Resources/document.png"
        }
    }
}
