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
    compressionFeedback.compressionAmount = amount;
    compressionFeedback.compressionCount = 0;
}

void FeedbackInteractorImpl::setBpmErrorThreshold(float percentage)
{
    compressionFeedback.bpmErrorThreshold = compressionFeedback.DESIRED_BPM * percentage/100;
    std::cout << "FeedbackInteractorImpl: allowed bpm error high is :" << compressionFeedback.bpmErrorThreshold << std::endl;
}

void FeedbackInteractorImpl::setDepthErrorThreshold(float percentage)
{
    compressionFeedback.depthErrorThreshold = compressionFeedback.DESIRED_DEPTH * percentage/100;
    std::cout << "FeedbackInteractorImpl: allowed depth error high is :" << compressionFeedback.depthErrorThreshold << std::endl;
}

void FeedbackInteractorImpl::setVentilationAmount(int amount)
{
    ventilationFeedback.ventilationAmount = amount;
    ventilationFeedback.ventilationCount = 0;
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
    ventilationFeedback.volumeErrorThreshold = ventilationFeedback.desiredVolume_ml * percentage/100;
    std::cout << "FeedbackInteractorImpl: allowed volume error is :" << ventilationFeedback.volumeErrorThreshold << std::endl;
}

void FeedbackInteractorImpl::setTimeErrorThreshold(float percentage)
{
    ventilationFeedback.timeErrorThreshold = ventilationFeedback.DESIRED_TIME_IN_MS * percentage/100;
     std::cout << "FeedbackInteractorImpl: allowed time error is :" << ventilationFeedback.timeErrorThreshold << std::endl;
}

void FeedbackInteractorImpl::setDesiredVentilationVolumeFromBabyWeight(float babyWeight_mg)
{
    viewModel->setBabyWeight_mg(babyWeight_mg);
    std::cout << "FeedbackInteractorImpl: babyWeight is :" << babyWeight_mg << std::endl;

    ventilationFeedback.desiredVolume_ml = babyWeight_mg * ML_PER_KG_BABY_WEIGHT /1000;
    std::cout << "FeedbackInteractorImpl: desired volume is :" << ventilationFeedback.desiredVolume_ml << std::endl;
}

void FeedbackInteractorImpl::setFingerPositionFeedbackSelected(bool state)
{
    this->fingerPositionFeedbackSelected = state;
}
