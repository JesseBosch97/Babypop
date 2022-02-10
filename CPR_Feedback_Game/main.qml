import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("CPR Feedback Game")
    color: "azure"


    Label {
        text: "Find the right BPM by pressing the button repeatedly ..."
        font.pointSize: 18
        anchors.horizontalCenter: parent.horizontalCenter
    }

    RoundButton {
        id: compressionButton
        text: "Press!"
        font.pointSize: 18
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        width: 200
        height: 200
        padding: 50
        onClicked: RequestModel.compressionButtonPressed()
    }

    Label {
        id: bpmLabel
        text: "BPM:"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: compressionButton.bottom
        anchors.topMargin: 32
    }
}
