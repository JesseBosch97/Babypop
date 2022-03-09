import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import StringListModel 1.0

Window {
    width: 1280
    height: 480
    visible: true
    title: qsTr("CPR Feedback Game")
    color: "azure"


    ComboBox {
        id: voiceSelection
        model: ["MaleTTS", "FemaleTTS", "Male", "Female"]
        anchors.right: parent.right
        onActivated: RequestModel.voiceSelected(currentText)
        Component.onCompleted: RequestModel.voiceSelected(currentText)
    }

    ComboBox {
        id: portList
        model: PortListModel
        textRole: "display"
        onActivated: RequestModel.serialPortSelected(currentText)
        Component.onCompleted: RequestModel.serialPortSelected(currentText)
    }

    Button {
        text: "Connect"
        onPressed: RequestModel.serialConnectButtonPressed()
        anchors.left: portList.right
        anchors.leftMargin: 20
    }


    Label {
        text: "Press the button 30 times.\nFind the right BPM by listening to the feedback."
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
        onPressed: RequestModel.compressionButtonPressed()
    }

    Label {
        id: bpmLabel
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: compressionButton.bottom
        anchors.topMargin: 32
    }

    Slider {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        snapMode: "SnapOnRelease"
        stepSize: 1
        from: 0
        value: 5
        to: 10
        onMoved: RequestModel.sliderMoved(value)
    }
}
