#ifndef CONST_UTILS
#define CONST_UTILS

#include "Utils.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

float Utils::Pi = atan(1.0) * 4;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

float Utils::randomf(float min, float max)
{
	return min + (float) rand() / ((float) RAND_MAX / (max - min));
}

int Utils::random(int min, int max)
{
	return min + rand() / (RAND_MAX / (max + 1 - min));
}

float Utils::coord(float pCoordinate)
{
	return pCoordinate / CCDirector::sharedDirector()->getContentScaleFactor();
}

float Utils::distance(float dX0, float dY0, float dX1, float dY1)
{
    return sqrt((dX1 - dX0)*(dX1 - dX0) + (dY1 - dY0)*(dY1 - dY0));
}

bool Utils::probably(int pProbably)
{
	return Utils::random(0, 100) < pProbably;
}

CCPoint Utils::vectorNormalize(float pVectorX, float pVectorY, float pMultipleFactor)
{
	float x = pVectorX / sqrt(pVectorX * pVectorX + pVectorY * pVectorY) * pMultipleFactor;
	float y = pVectorY / sqrt(pVectorX * pVectorX + pVectorY * pVectorY) * pMultipleFactor;

	return ccp(x, y);
}

long Utils::millisecondNow()
{
    struct cc_timeval now;
    CCTime::gettimeofdayCocos2d(&now, NULL);
    return (now.tv_sec * 1000.0 + now.tv_usec / 1000.0);
}

// ===========================================================
// Virtual Methods
// ===========================================================

#endif