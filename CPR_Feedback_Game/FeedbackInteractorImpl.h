#ifndef FEEDBACKINTERACTORIMPL_H
#define FEEDBACKINTERACTORIMPL_H

#include "FeedbackInteractor.h"
#include "CompressionFeedback.h"
#include "VentilationFeedback.h"
#include "HeadPositionFeedback.h"
#include "FingerPositionFeedback.h"
#include "AudioPlayer.h"
#include "ViewModelImpl.h"

class FeedbackInteractorImpl : public FeedbackInteractor
{
public:
    FeedbackInteractorImpl();

    CompressionFeedback compressionFeedback;
    VentilationFeedback ventilationFeedback;
    HeadPositionFeedbackImpl headPositionFeedback;
    FingerPositionFeedbackImpl fingerPositionFeedback;
    ViewModelImpl * viewModel;
    AudioPlayer * audioPlayer;


    void handleFingerPosition(FingerPosition fingerPosition) override;
    void handleCompression(Compression compression) override;
    void handleHeadPosition(HeadPosition headPosition) override;
    void handleVolumeIn(Ventilation ventilation) override;
    void handleVolumeOut(Ventilation ventilation) override;

    void setCompressionFeedbackSelected(bool state) override;
    void setCompressionAmount(int amount) override;
    void setBpmErrorThreshold(float percentage) override;
    void setDepthErrorThreshold(float percentage) override;

    void setVentilationAmount(int amount) override;
    void setVentilationFeedbackSelected(bool state) override;
    void setVolumeErrorThreshold(float percentage) override;
    void setTimeErrorThreshold(float percentage) override;
    void setDesiredVentilationVolumeFromBabyWeight(float babyWeightInKg) override;

    void setFingerPositionFeedbackSelected(bool state) override;

private:
    bool compressionFeedbackSelected = false;
    bool ventilationFeedbackSelected = false;
    bool fingerPositionFeedbackSelected = false;
    bool headPositionFeedbackSelected = false;


    // the bag contains 125 mil
    //top value for the bag used is 140

    //a baby should be ventilated with 6 to 8 ml per kg of bodyweight
    const int ML_PER_KG_BABY_WEIGHT = 7;
};

#endif // FEEDBACKINTERACTORIMPL_H
