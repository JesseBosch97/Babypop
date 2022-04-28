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
                    text: "Feedback Amount: " + compressionFeedbackAmountSlider.value
                }

                Slider {
                    id: compressionFeedbackAmountSlider
                    snapMode: "SnapOnRelease"
                    stepSize: 10
                    from: 0
                    value: 90
                    to: 100
                    onMoved: RequestModel.compressionSliderMoved(value)
                    Component.onCompleted: RequestModel.compressionSliderMoved(value)
                }

                Label {
                    text: "Compression Amount: "
                }

                SpinBox {
                    value: 30
                }

                Label {
                    text: "Error Margin: "
                }

                SpinBox {
                    value: 5
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
                    onValueChanged: RequestModel.ventilationFeedbackAmountChanged(value)
                    Component.onCompleted: RequestModel.ventilationFeedbackAmountChanged(value)
                }

                Label {
                    text: "Error Margin: "
                }

                SpinBox {
                    value: 5
                }
            }
        }

        Column {
            id: airwayColumn

            CheckBox {
                id: airwayCheckbox
                text: "Airway Management"
                onCheckStateChanged:
                {
                    RequestModel.airwayCheckboxSelected(checkState)
                    airwaySubColumn.visible = checkState
                }

            }

            Column {
                id: airwaySubColumn
                visible: false

                Label {
                    text: "Feedback Amount: " + airwayFeedbackAmountSlider.value
                }

                Slider {
                    id: airwayFeedbackAmountSlider
                    snapMode: "SnapOnRelease"
                    stepSize: 10
                    from: 0
                    value: 50
                    to: 100
                    onMoved: RequestModel.airwaySliderMoved(value)
                    Component.onCompleted: RequestModel.airwaySliderMoved(value)
                }

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
