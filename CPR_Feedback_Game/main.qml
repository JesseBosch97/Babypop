import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import StringListModel 1.0

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("CPR Feedback Game")
    color: "azure"




    Label {
        id: voiceSelectionLabel
        text: "Select feedback voice"
        font.pointSize: 18
        anchors.left: parent.left
    }

    ComboBox {
        id: voiceSelection
        model: ["MaleTTS", "FemaleTTS", "Male", "Female"]
        anchors.left: parent.left
        anchors.top: voiceSelectionLabel.bottom
        onActivated: RequestModel.voiceSelected(currentText)
        Component.onCompleted: RequestModel.voiceSelected(currentText)
    }


    Label {
        id: portSelectionLabel
        text: "Select COM port"
        font.pointSize: 18
        anchors.right: parent.right
    }

    ComboBox {
        id: portList
        model: PortListModel
        textRole: "display"
        anchors.top: portSelectionLabel.bottom
        anchors.right: parent.right
        onActivated: RequestModel.serialPortSelected(currentText)
        Component.onCompleted: RequestModel.serialPortSelected(currentText)
    }

    Button {
        text: "Connect"
        onPressed: RequestModel.serialConnectButtonPressed()
        anchors.right: portList.left
        anchors.top: portSelectionLabel.bottom
        anchors.rightMargin: 20
    }


    Label {
        id: compressionSimulationLabel
        text: "Press to apply simulated compression"
        font.pointSize: 18
        anchors.horizontalCenter: parent.horizontalCenter
    }

    RoundButton {
        id: compressionButton
        text: "Press!"
        font.pointSize: 18
        anchors.horizontalCenter: parent.horizontalCenter

        anchors.top: compressionSimulationLabel.bottom
        width: 200
        height: 200
        padding: 50
        onPressed: RequestModel.compressionButtonPressed()
    }







    Label {
        id: feedbackLabel
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        text: "Select feedback type"
        font.pointSize: 18
    }

    Row {
        anchors.top: feedbackLabel.bottom


        Column {
            id: compressionColumn

            CheckBox {
                id: compressionCheckbox
                text: "Compression"
                onCheckStateChanged:
                {
                    RequestModel.compressionCheckboxSelected(checkState)
                    compressionSubColumn.visible = checkState
                }
            }

            Column {
                id: compressionSubColumn
                visible: false

                Label {
                    text: "Compression Amount: "
                }

                SpinBox {
                    id: compressionAmountBox
                    from: 0
                    value: 30
                    onValueChanged: RequestModel.compressionAmountChanged(value)
                    Component.onCompleted: RequestModel.compressionAmountChanged(value)
                }

//                Label {
//                    text: "Feedback every " + compressionFeedbackFrequencyBox.value + " compressions"
//                }

//                SpinBox {
//                    id: compressionFeedbackFrequencyBox
//                    value: 5
//                    from: 0
//                    to: compressionAmountBox.value
//                    onValueChanged: RequestModel.compressionFeedbackFrequencyChanged(value)
//                    Component.onCompleted: RequestModel.compressionFeedbackFrequencyChanged(value)
//                }


                Label {
                    text: "Allowed BPM high error: " + bpmErrorHighSlider.value + "%"
                }

                Slider {
                    id: bpmErrorHighSlider
                    snapMode: "SnapOnRelease"
                    stepSize: 10
                    from: 0
                    value: 10
                    to: 100
                    onMoved: RequestModel.bpmErrorHighSliderMoved(value)
                    Component.onCompleted: RequestModel.bpmErrorHighSliderMoved(value)
                }

                Label {
                    text: "Allowed BPM low error: " + bpmErrorLowSlider.value + "%"
                }

                Slider {
                    id: bpmErrorLowSlider
                    snapMode: "SnapOnRelease"
                    stepSize: 10
                    from: 0
                    value: 10
                    to: 100
                    onMoved: RequestModel.bpmErrorLowSliderMoved(value)
                    Component.onCompleted: RequestModel.bpmErrorLowSliderMoved(value)
                }

                Label {
                    text: "Allowed depth high error: " + depthHighErrorSlider.value + "%"
                }

                Slider {
                    id: depthHighErrorSlider
                    snapMode: "SnapOnRelease"
                    stepSize: 10
                    from: 0
                    value: 10
                    to: 100
                    onMoved: RequestModel.depthErrorHighSliderMoved(value)
                    Component.onCompleted: RequestModel.depthErrorHighSliderMoved(value)
                }


                Label {
                    text: "Allowed depth low error: " + depthLowErrorSlider.value + "%"
                }

                Slider {
                    id: depthLowErrorSlider
                    snapMode: "SnapOnRelease"
                    stepSize: 10
                    from: 0
                    value: 10
                    to: 100
                    onMoved: RequestModel.depthErrorLowSliderMoved(value)
                    Component.onCompleted: RequestModel.depthErrorLowSliderMoved(value)
                }


            }
        }

        Column {
            id: ventilationColumn

            CheckBox {
                id: ventilationCheckbox
                text: "Ventilation"
                onCheckStateChanged:
                {
                    RequestModel.ventilationCheckboxSelected(checkState)
                    ventilationSubColumn.visible = checkState
                }

            }

            Column {
                id: ventilationSubColumn
                visible: false

                Label {
                    text: "Ventilation Amount: "
                }

                SpinBox {
                    id: ventilationAmountBox
                    from: 0
                    value: 2
                    onValueChanged: RequestModel.ventilationAmountChanged(value)
                    Component.onCompleted: RequestModel.ventilationAmountChanged(value)
                }

                Label {
                    text: "Feedback every " + feedbackFrequencyBox.value + " ventilations"
                }

                SpinBox {
                    id: feedbackFrequencyBox
                    value: 1
                    from: 0
                    to: ventilationAmountBox.value
                    onValueChanged: RequestModel.ventilationFeedbackFrequencyChanged(value)
                    Component.onCompleted: RequestModel.ventilationFeedbackFrequencyChanged(value)
                }

                Label {
                    text: "Allowed volume error: " + volumeErrorSlider.value + "%"
                }

                Slider {
                    id: volumeErrorSlider
                    snapMode: "SnapOnRelease"
                    stepSize: 10
                    from: 0
                    value: 10
                    to: 100
                    onMoved: RequestModel.volumeErrorSliderMoved(value)
                    Component.onCompleted: RequestModel.volumeErrorSliderMoved(value)
                }

                Label {
                    text: "Allowed time error: " + timeErrorSlider.value + "%"
                }

                Slider {
                    id: timeErrorSlider
                    snapMode: "SnapOnRelease"
                    stepSize: 10
                    from: 0
                    value: 10
                    to: 100
                    onMoved: RequestModel.ventilationTimeErrorSliderMoved(value)
                    Component.onCompleted: RequestModel.ventilationTimeErrorSliderMoved(value)
                }



            }
        }

        Column {
            id: fingerColumn

            CheckBox {
                id: fingerCheckbox
                text: "Finger Position"
                onCheckStateChanged:
                {
                    RequestModel.fingerCheckboxSelected(checkState)
                    fingerSubColumn.visible = checkState
                }
            }

            Column {
                id: fingerSubColumn
                visible: false

                Label {
                    text: "Error Margin: "
                }

                SpinBox {
                    value: 5
                }
            }
        }




        Column {
            id: headPositionColumn

            CheckBox {
                id: headPositionCheckbox
                text: "Head Position"
                onCheckStateChanged:
                {
                    RequestModel.headPositionCheckboxSelected(checkState)
                    headPositionSubColumn.visible = checkState
                }

            }

            Column {
                id: headPositionSubColumn
                visible: false


                Label {
                    text: "Error Margin: "
                }

                SpinBox {
                    value: 5
                }
            }
        }




    }




}
