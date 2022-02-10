#include "feedback.h"

Feedback::Feedback()
{

}

void Feedback::compressionPerformed()
{
    lastTimeInterval = timer.restart();
    std::cout << "time interval is " << lastTimeInterval << std::endl;

    int bpm = calculateBPM(lastTimeInterval);

    if (bpm < 90){
        output->giveBpmFeedback(TOO_SLOW);
    }
    else if (bpm > 110) {
        output->giveBpmFeedback(TOO_FAST);
    }
    else {
        output->giveBpmFeedback(PERFECT);
    }
}

int Feedback::calculateBPM(int intervalInMs){
    int beatsPerMinute = 60000/intervalInMs;
    std::cout << "BPM is " << beatsPerMinute << std::endl;
    return beatsPerMinute;
}
