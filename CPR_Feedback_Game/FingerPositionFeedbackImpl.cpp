#include "FingerPositionFeedbackImpl.h"

FingerPositionFeedbackImpl::FingerPositionFeedbackImpl()
{

}



void FingerPositionFeedbackImpl::handleFingerPosition(FingerPosition positionOfFingers)
{
    int fingerPositionPerformance = CORRECT;

    //enum location {UP_LEFT, UP, UP_RIGHT, LEFT, MID, RIGHT, BOTTOM_LEFT, LOW, BOTTOM_RIGHT};
    if(pressurePoints(positionOfFingers) < 3)
    {
        switch(locationOfFingers(positionOfFingers))
        {
        case UP_LEFT:
            fingerPositionPerformance = TOO_FAR_LEFT;
            break;
        case UP:
            fingerPositionPerformance = TOO_HIGH;
            break;
        case UP_RIGHT:
            fingerPositionPerformance = TOO_FAR_RIGHT;
            break;
        case LEFT:
            fingerPositionPerformance = TOO_FAR_LEFT;
            break;
        case MID:
            fingerPositionPerformance = CORRECT;
            break;
        case RIGHT:
            fingerPositionPerformance = TOO_FAR_RIGHT;
            break;
        case BOTTOM_LEFT:
            fingerPositionPerformance = TOO_LOW;
            break;
        case LOW:
            fingerPositionPerformance = TOO_LOW;
            break;
        case BOTTOM_RIGHT:
            fingerPositionPerformance = TOO_LOW;
            break;

        }
    }
    else
    {
        fingerPositionPerformance = TOO_MANY_PRESSURE_POINTS;
    }

    audioPlayer->giveFingerPositionFeedback(fingerPositionPerformance);
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




    thorax.x = ((bottomLeft.x + topLeft.x + topRight.x + mid.x + bottomRight.x + top.x + lowmid.x) / 4);
    thorax.y = ((bottomLeft.y + topLeft.y + topRight.y + mid.y + bottomRight.y + top.y + lowmid.y) / 6);

    return calculateLocation(thorax);
}

location FingerPositionFeedbackImpl::calculateLocation(Coordinates thorax)
{
    location retval;
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
    }
    if(up && midx)
    {
        retval = UP;
    }
    if(up && right)
    {
        retval = UP_RIGHT;
    }
    if(midy && left)
    {
        retval = LEFT;
    }
    if(midy && midx)
    {
        retval = MID;
    }
    if(midy && right)
    {
        retval = RIGHT;
    }
    if(low && left)
    {
        retval = BOTTOM_LEFT;
    }
    if(low && midx)
    {
        retval = LOW;
    }
    if(low && right)
    {
        retval = BOTTOM_RIGHT;
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






