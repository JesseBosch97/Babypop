#include "FeedbackInteractorImpl.h"

FeedbackInteractorImpl::FeedbackInteractorImpl()
{

}

void FeedbackInteractorImpl::handleFingerPosition(FingerPosition fingerPosition)
{
    if (fingerPositionFeedbackSelected)
    {
        audioPlayer->giveFeedback(fingerPositionFeedback.handleFingerPosition(fingerPosition));
    }
}

void FeedbackInteractorImpl::handleCompression(Compression compression)
{
    if (compressionFeedbackSelected)
    {
        audioPlayer->giveFeedback(compressionFeedback.handleCompression(compression));
    }
}

void FeedbackInteractorImpl::handleHeadPosition(HeadPosition headPosition)
{
    if (headPositionFeedbackSelected)
    {
        audioPlayer->giveFeedback(headPositionFeedback.handleHeadPosition(headPosition));
    }
}

void FeedbackInteractorImpl::handleVolumeIn(Ventilation ventilation)
{
    audioPlayer->giveFeedback(ventilationFeedback.handleVolumeIn(ventilation));
}

void FeedbackInteractorImpl::handleVolumeOut(Ventilation ventilation)
{
    audioPlayer->giveFeedback(ventilationFeedback.handleVolumeOut(ventilation));
}

void FeedbackInteractorImpl::setCompressionFeedbackSelected(bool state)
{
    this->compressionFeedbackSelected = state;
    if (compressionFeedbackSelected == true)
    {
        audioPlayer->giveFeedback(START_COMPRESSION);
    }

    compressionFeedback.compressionCount = 0;
}

void FeedbackInteractorImpl::setCompressionAmount(int amount)
{
    compressionFeedback.setCompressionAmount(amount);

}

void FeedbackInteractorImpl::setBpmErrorThreshold(float percentage)
{
    compressionFeedback.setBpmErrorThreshold(percentage);
}

void FeedbackInteractorImpl::setDepthErrorThreshold(float percentage)
{
    compressionFeedback.setDepthErrorThreshold(percentage);

}

void FeedbackInteractorImpl::setVentilationAmount(int amount)
{
    ventilationFeedback.setVentilationAmount(amount);
}

void FeedbackInteractorImpl::setVentilationFeedbackSelected(bool state)
{
    this->ventilationFeedbackSelected = state;
    if (state == true)
    {
        audioPlayer->giveFeedback(START_VENTILATION);
    }

    ventilationFeedback.ventilationCount = 0;
}

void FeedbackInteractorImpl::setVolumeErrorThreshold(float percentage)
{
    ventilationFeedback.setVolumeErrorThreshold(percentage);
}

void FeedbackInteractorImpl::setTimeErrorThreshold(float percentage)
{
    ventilationFeedback.setTimeErrorThreshold(percentage);
}

void FeedbackInteractorImpl::setBabyWeight(float babyWeightInKg)
{
    ventilationFeedback.setBabyWeight(babyWeightInKg);
}
