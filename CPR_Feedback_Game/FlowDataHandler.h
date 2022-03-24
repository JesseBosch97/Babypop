#ifndef FLOWDATAHANDLER_H
#define FLOWDATAHANDLER_H

#include <string>
#include <iostream>
#include "StringFunctions.h"
#include <QElapsedTimer>
#include <vector>
#include "PerformanceTypes.h"


#define FLOW_THRESHOLD 2




class FlowDataHandler
{
public:
   FlowDataHandler();
   void handleFlowData(std::string flowData);
   FlowPerformance flowPerformance;
   QElapsedTimer timer;
   std::vector<int> flowSamples;

   int sampleTotal = 0;


   bool ventilationLengthTimerRunning = false;
   bool flowPerformanceCollected = false;



private:
   int getMaxValue();
};

#endif // FLOWDATAHANDLER_H
