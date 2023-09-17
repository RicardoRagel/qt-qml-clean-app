import QtQuick 2.14
import QtQuick.Window 2.3
import QtQuick.Scene3D 2.14

import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.3
import QtGraphicalEffects 1.0

import QtQuick.Layouts 1.3

// Import C++ data handlers
import DataManager 1.0

// App Window
ApplicationWindow
{
    id: root
    property color appWindowColor:      Qt.rgba(30/255,30/255,30/255, 1)

    // Windows Configuration
    title: qsTr("App")
    visible: true
    visibility : Window.Maximized
    x: 0
    y: 0
    minimumWidth: Screen.width * 0.5
    minimumHeight: Screen.height * 0.75
    color: appWindowColor

    // Manage the app starup
    Component.onCompleted:
    {
        // nothing for now
        //console.log("verticalMargin: " + verticalMargin)
        //console.log("horizontalMargin: " + horizontalMargin)
    }

    /*
        CONTENT
    */
    Rectangle
    {
        id: appBackground
        visible: true
        anchors.fill: parent
        color: "transparent"

        Row
        {
            anchors.centerIn: parent
            spacing: 10

            property int rect_width: appBackground.width/8

            // Accesing using QList
            Rectangle
            {
                anchors.verticalCenter: parent.verticalCenter
                width: parent.rect_width
                height: width

                color: DataManager.itemList[0].color

                Text
                {
                    anchors.centerIn: parent
                    font.pointSize: parent.height/10

                    text: DataManager.itemList[0].id
                }
            }
            Rectangle
            {
                anchors.verticalCenter: parent.verticalCenter
                width: parent.rect_width
                height: width

                color: DataManager.itemList[1].color

                Text
                {
                    anchors.centerIn: parent
                    font.pointSize: parent.height/10

                    text: DataManager.itemList[1].id
                }
            }

            // Accesing using map
            Rectangle
            {
                anchors.verticalCenter: parent.verticalCenter
                width: parent.rect_width
                height: width

                color: DataManager.getItem("ABC").color

                Text
                {
                    anchors.centerIn: parent
                    font.pointSize: parent.height/10

                    text: DataManager.getItem("ABC").id
                }
            }
            Rectangle
            {
                anchors.verticalCenter: parent.verticalCenter
                width: parent.rect_width
                height: width

                color: DataManager.getItem("DEF").color

                Text
                {
                    anchors.centerIn: parent
                    font.pointSize: parent.height/10

                    text: DataManager.getItem("DEF").id
                }
            }
        }

    }//background
}
