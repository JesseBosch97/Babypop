#ifndef FEEDBACKINTERACTORIMPL_H
#define FEEDBACKINTERACTORIMPL_H

#include "FeedbackInteractor.h"
#include "CompressionFeedback.h"
#include "VentilationFeedback.h"
#include "HeadPositionFeedback.h"
#include "FingerPositionFeedback.h"
#include "AudioPlayer.h"

class FeedbackInteractorImpl : public FeedbackInteractor
{
public:
    FeedbackInteractorImpl();

    CompressionFeedbackImpl compressionFeedback;
    VentilationFeedbackImpl ventilationFeedback;
    HeadPositionFeedbackImpl headPositionFeedback;
    FingerPositionFeedbackImpl fingerPositionFeedback;
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
    void setBabyWeight(float babyWeightInKg) override;

private:
    bool compressionFeedbackSelected = false;
    bool ventilationFeedbackSelected = false;
    bool fingerPositionFeedbackSelected = false;
    bool headPositionFeedbackSelected = false;
};

#endif // FEEDBACKINTERACTORIMPL_H
