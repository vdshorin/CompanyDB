import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import Qt.labs.qmlmodels 1.0
import QtQuick.Layouts 1.1
import QtQuick.Dialogs
import QtQml 2.15

//import TableModelTest 0.1

Rectangle{
    anchors.top: appHeader.top
    anchors.bottom: parent.bottom
    anchors.left: navigationDrawer.right
    anchors.right: parent.right
    color: "red"


//    TableModel{
//        id: tableModel_1

//        TableModelColumn {
////            id: column_1
//            display: "column_1_name"
////            accessibleText: "column_1_name"
//        }

//        TableModelColumn {
////            id: column_2
//            display: "column_2_name"
//        }

//        TableModelColumn {
////            id: column_3
//            display: "column_3_name"
//        }

//        TableModelColumn {
////            id: column_4
//            display: "column_4_name"
//        }

//        TableModelColumn {
////            id: column_5
//            display: "column_5_name"
//        }

//        rows: [
//            {
//                column_1_name : "row_1 column_1",
//                column_2_name : "row_1 column_2",
//                column_3_name : "row_1 column_3",
//                column_4_name : "row_1 column_4",
//                column_5_name : "row_1 column_5"
//            },
//            {
//                column_1_name : "row_2 column_1",
//                column_2_name : "row_2 column_2",
//                column_3_name : "row_2 column_3",
//                column_4_name : "row_2 column_4",
//                column_5_name : "row_2 column_5"
//            },
//            {
//                column_1_name : "row_3 column_1",
//                column_2_name : "row_3 column_2",
//                column_3_name : "row_3 column_3",
//                column_4_name : "row_3 column_4",
//                column_5_name : "row_3 column_5"
//            }
//        ]
//    }



    TableView {
        id: tableView
//        anchors.fill: parent
        anchors.top: horizontalHeader.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        columnSpacing: 1
        rowSpacing: 1
        clip: true



//        model: tableModel_1

        model: TableModelTest{}

//        model: TableModel {
//            TableModelColumn { display: "name" }
//            TableModelColumn { display: "color" }

//            rows: [
//                {
//                    "name": "cat",
//                    "color": "black"
//                },
//                {
//                    "name": "dog",
//                    "color": "brown"
//                },
//                {
//                    "name": "bird",
//                    "color": "white"
//                }
//            ]
//        }

        delegate: Button {
            implicitWidth: 100
            implicitHeight: 50
            text: model.display

            onClicked: {

//                model.display = text
                console.log(row, column)
//                focus = false
            }

//            anchors.centerIn: parent
        }



    }

    HorizontalHeaderView {
        id: horizontalHeader
        syncView: tableView

//        delegate: Rectangle {
//            implicitWidth: 100
//            implicitHeight: 50
//            border.width: 1

//            Text {
//                text: display
//                anchors.centerIn: parent
//            }
//        }

//        Component.onCompleted: {
//            console.log(tableModel_1.columns)
//        }
    }


//    TableView {
//        anchors.fill: parent
//        columnSpacing: 1
//        rowSpacing: 1
//        boundsBehavior: Flickable.StopAtBounds

//        model: TableModel {
//            id: model

//            TableModelColumn { display: "checked" }
//            TableModelColumn { display: "amount" }
//            TableModelColumn { display: "fruitType" }
//            TableModelColumn { display: "fruitName" }
//            TableModelColumn { display: "fruitPrice" }

//            // Each row is one type of fruit that can be ordered
//            rows: [
//                {
//                    // Each property is one cell/column.
//                    checked: false,
//                    amount: 1,
//                    fruitType: "Apple",
//                    fruitName: "Granny Smith",
//                    fruitPrice: 1.50
//                },
//                {
//                    checked: true,
//                    amount: 4,
//                    fruitType: "Orange",
//                    fruitName: "Navel",
//                    fruitPrice: 2.50
//                },
//                {
//                    checked: false,
//                    amount: 1,
//                    fruitType: "Banana",
//                    fruitName: "Cavendish",
//                    fruitPrice: 3.50
//                }
//            ]
//        }
//        delegate: DelegateChooser {
////            DelegateChoice {
////                column: 0
////                delegate: CheckBox {
////                    checked: model.display
////                    onToggled: model.display = checked
////                }
////            }
////            DelegateChoice {
////                column: 1
////                delegate: SpinBox {
////                    value: model.display
////                    onValueModified: model.display = value
////                }
////            }
//            DelegateChoice {
//                delegate: TextField {
//                    text: model.display
//                    selectByMouse: true
//                    implicitWidth: 140
//                    onAccepted: model.display = text
//                }
//            }
//        }
//    }

//    Button{
//        onClicked: {
//            var index = model.index(0,1);

////            console.log(modelw.data(modelw.index(0, 0),2))
//            console.log(model.setData(index, false, 2))
//        }
//    }
}
