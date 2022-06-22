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


                Label {
                    text: "BPM allowed error: " + bpmErrorSlider.value + "%"
                }

                Slider {
                    id: bpmErrorSlider
                    snapMode: "SnapOnRelease"
                    stepSize: 10
                    from: 0
                    value: 20
                    to: 100
                    onMoved: RequestModel.bpmErrorSliderMoved(value)
                    Component.onCompleted: RequestModel.bpmErrorSliderMoved(value)
                }



                Label {
                    text: "Depth allowed error: " + depthErrorSlider.value + "%"
                }

                Slider {
                    id: depthErrorSlider
                    snapMode: "SnapOnRelease"
                    stepSize: 10
                    from: 0
                    value: 20
                    to: 100
                    onMoved: RequestModel.depthErrorSliderMoved(value)
                    Component.onCompleted: RequestModel.depthErrorSliderMoved(value)
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
                    text: "Baby Weight: (kg)"
                }

                //this is adapted from the function at https://doc.qt.io/qt-5/qml-qtquick-controls2-spinbox.html
                SpinBox {
                    id: babyWeightBox
                    from: 0
                    value: ViewModel.babyWeight_mg
                    to: 10000
                    stepSize: 100

                    property int decimals: 1
                    property real realValue: value / 1000

                    validator: DoubleValidator {
                        bottom: Math.min(babyWeightBox.from, babyWeightBox.to)
                        top:  Math.max(babyWeightBox.from, babyWeightBox.to)
                    }

                    textFromValue: function(value, locale) {
                        return Number(value / 1000).toLocaleString(locale, 'f', babyWeightBox.decimals)
                    }

                    valueFromText: function(text, locale) {
                        return Number.fromLocaleString(locale, text) * 1000
                    }

                    onValueChanged: RequestModel.babyWeightChanged(value)
                    Component.onCompleted: RequestModel.babyWeightChanged(value)
                }



                Label {
                    text: "Allowed volume error: " + volumeErrorSlider.value + "%"
                }

                Slider {
                    id: volumeErrorSlider
                    snapMode: "SnapOnRelease"
                    stepSize: 10
                    from: 0
                    value: 40
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
                    value: 40
                    to: 100
                    onMoved: RequestModel.timeErrorSliderMoved(value)
                    Component.onCompleted: RequestModel.timeErrorSliderMoved(value)
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
