#include "feedback.h"

Feedback::Feedback()
{

}

void Feedback::compressionPerformed()
{
    lastTimeInterval = timer.restart();
    std::cout << "time interval is " << lastTimeInterval << std::endl;
    output->giveFeedback();
}
