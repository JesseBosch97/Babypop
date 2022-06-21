#include "FingerPositionFeedback.h"

FingerPositionFeedbackImpl::FingerPositionFeedbackImpl()
{

}



FeedbackType FingerPositionFeedbackImpl::handleFingerPosition(FingerPosition positionOfFingers)
{
    int fingerPositionPerformance = CORRECT;
    //enum location {UP_LEFT, UP, UP_RIGHT, LEFT, MID, RIGHT, BOTTOM_LEFT, LOW, BOTTOM_RIGHT};
    if((pressurePoints(positionOfFingers) <= 3) && (pressurePoints(positionOfFingers) > 0))
    {
        switch(locationOfFingers(positionOfFingers))
        {
        case UP_LEFT:
            fingerPositionPerformance = TOO_FAR_LEFT;
            std::cout << "FingerPosition: TOO FAR LEFT" << std::endl;
            break;
        case UP:
            fingerPositionPerformance = TOO_HIGH;
            std::cout << "FingerPosition: TOO HIGH" << std::endl;
            break;
        case UP_RIGHT:
            fingerPositionPerformance = TOO_FAR_RIGHT;
            std::cout << "FingerPosition: TOO FAR RIGH" << std::endl;
            break;
        case LEFT:
            fingerPositionPerformance = TOO_FAR_LEFT;
            std::cout << "FingerPosition: TOO FAR LEFT" << std::endl;
            break;
        case MID:
            fingerPositionPerformance = CORRECT;
            std::cout << "FingerPosition: CORRECT" << std::endl;
            break;
        case RIGHT:
            fingerPositionPerformance = TOO_FAR_RIGHT;
            std::cout << "FingerPosition: TOO FAR RIGHT" << std::endl;
            break;
        case BOTTOM_LEFT:
            fingerPositionPerformance = TOO_LOW;
            std::cout << "FingerPosition: TOO LOW" << std::endl;
            break;
        case LOW:
            fingerPositionPerformance = TOO_LOW;
            std::cout << "FingerPosition: TOO LOW" << std::endl;
            break;
        case BOTTOM_RIGHT:
            fingerPositionPerformance = TOO_LOW;
            std::cout << "FingerPosition: TOO LOW" << std::endl;
            break;            
        case LOWEST:
            fingerPositionPerformance = WAY_TOO_LOW;
            std::cout << "FingerPosition: WAY TOO LOW" << std::endl;
            break;
        }
    }
    else if (pressurePoints(positionOfFingers) > 3)
    {
        fingerPositionPerformance = TOO_MANY_PRESSURE_POINTS;
        std::cout << "FingerPosition: TOO many" << std::endl;
    }
    else if (pressurePoints(positionOfFingers) <= 0)
    {
        fingerPositionPerformance = NO_TOUCH;
        std::cout << "FingerPosition: none" << std::endl;
    }
    std::cout << "points: " << pressurePoints(positionOfFingers) << std::endl;
    return fingerPositionPerformance;
}



location FingerPositionFeedbackImpl::locationOfFingers(FingerPosition positionOfFingers)
{
    Coordinates bottomLeft;
    bottomLeft.x = -1 * positionOfFingers.bottomleft;
    bottomLeft.y = -1 * positionOfFingers.bottomleft;

    Coordinates topLeft;
    topLeft.x = -1 * positionOfFingers.topleft;
    topLeft.y = 1 * positionOfFingers.topleft;

    Coordinates topRight;
    topRight.x = 1 * positionOfFingers.topright;
    topRight.y = 1 * positionOfFingers.topright;

    Coordinates mid;
    mid.x = 0 * positionOfFingers.mid;
    mid.y = 0 * positionOfFingers.mid;

    Coordinates bottomRight;
    bottomRight.x = 1 * positionOfFingers.bottomright;
    bottomRight.y = -1 * positionOfFingers.bottomright;

    Coordinates top;
    top.x = 0 * positionOfFingers.top;
    top.y = 1 * positionOfFingers.top;

    Coordinates lowmid;
    lowmid.x = 0 * positionOfFingers.lowmid;
    lowmid.y = -1 * positionOfFingers.lowmid;

    Coordinates thorax;
    thorax.x = 0;
    thorax.y = 0;



    if(positionOfFingers.bottom <= 50)
    {
        thorax.x = ((bottomLeft.x + topLeft.x + topRight.x + mid.x + bottomRight.x + top.x + lowmid.x) / 4);
        thorax.y = ((bottomLeft.y + topLeft.y + topRight.y + mid.y + bottomRight.y + top.y + lowmid.y) / 6);
        return calculateLocation(thorax);
    }
    else
    {
      return LOWEST;
    }
}

location FingerPositionFeedbackImpl::calculateLocation(Coordinates thorax)
{
    location retval = MID;
    bool up = 0;
    bool midy = 0;
    bool low = 0;
    bool left = 0;
    bool midx = 0;
    bool right = 0;

    if(30 < thorax.y && thorax.y <= 100)
    {
        up = 1;
    }
    if(-30 <= thorax.y && thorax.y <= 30)
    {
        midy = 1;
    }
    if(-100 <= thorax.y && thorax.y < -30)
    {
        low = 1;
    }
    if(-100 <= thorax.x && thorax.x < -30)
    {
        left = 1;
    }
    if(-30 <= thorax.x && thorax.x <= 30)
    {
        midx = 1;
    }
    if(30 < thorax.x && thorax.x <= 100)
    {
        right = 1;
    }


    if(up && left)
    {
        retval = UP_LEFT;
        std::cout << "retval: UP LEFT" << std::endl;
    }
    else if(up && midx)
    {
        retval = UP;
        std::cout << "retval: UP" << std::endl;
    }
    else if(up && right)
    {
        retval = UP_RIGHT;
        std::cout << "retval: UP RIGHT" << std::endl;
    }
    else if(midy && left)
    {
        retval = LEFT;
        std::cout << "retval: LEFT" << std::endl;
    }
    else if(midy && right)
    {
        retval = RIGHT;
        std::cout << "retval: RIGHT" << std::endl;
    }
    else if(low && left)
    {
        retval = BOTTOM_LEFT;
        std::cout << "retval: BOTTOM LEFT" << std::endl;
    }
    else if(low && midx)
    {
        retval = LOW;
        std::cout << "retval: LOW" << std::endl;
    }
    else if(low && right)
    {
        retval = BOTTOM_RIGHT;
        std::cout << "retval: BOTTOM RIGHT" << std::endl;
    }
    else if(left)
    {
        retval = LEFT;
        std::cout << "retval: LEFT" << std::endl;
    }
    else if(right)
    {
        retval = RIGHT;
        std::cout << "retval: RIGHT" << std::endl;
    }
    else if(midy && midx)
    {
        retval = MID;
        std::cout << "retval: MID" << std::endl;
    }
    return retval;
}

int FingerPositionFeedbackImpl::pressurePoints(FingerPosition positionOfFingers)
{
    int pressurePoints = 0;

    if(positionOfFingers.lowmid > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.mid > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.top > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.bottomleft > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.bottomright > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.topleft > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.topright > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.bottom > 150)
    {
        pressurePoints++;
    }
    return pressurePoints;
}






