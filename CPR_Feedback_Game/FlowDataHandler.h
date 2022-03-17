#ifndef FLOWDATAHANDLER_H
#define FLOWDATAHANDLER_H

#include <string>
#include <iostream>
#include "StringFunctions.h"
#include <QElapsedTimer>
#include <vector>
#include "PerformanceTypes.h"

#define DESIRED_FLOW 15
#define FLOW_THRESHOLD 10
#define FLOW_ERROR 5


//struct FlowPerformance{
//    int ventilationTime = 0;
//    int pauseTime = 0;
//    int averageFlowStrenght = 0;
//};

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
   bool pauseLengthTimerRunning = false;

   bool flowPerformanceCollected = false;



};

#endif // FLOWDATAHANDLER_H
