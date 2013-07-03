#ifndef CONST_UTILS_H
#define CONST_UTILS_H

#include "cocos2d.h"

#include "Options.h"

#include <string>
#include <sstream>
#include <stdlib.h>
#include <cmath>

using namespace std;
using namespace cocos2d;

class Entity;

class Utils
{
	protected:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

		// ===========================================================
		// Fields
		// ===========================================================

		// ===========================================================
		// Constructors
		// ===========================================================

		// ===========================================================
		// Methods
		// ===========================================================

		// ===========================================================
		// Virtual Methods
		// ===========================================================

	private:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

		// ===========================================================
		// Fields
		// ===========================================================

		// ===========================================================
		// Constructors
		// ===========================================================

		// ===========================================================
		// Methods
		// ===========================================================
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================

	public:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

		static float Pi;

		// ===========================================================
		// Fields
		// ===========================================================

		// ===========================================================
		// Constructors
		// ===========================================================

		// ===========================================================
		// Methods
		// ===========================================================

		static CCPoint vectorNormalize(float pVectorX, float pVectorY, float pMultipleFactor);

        static float coord(float pCoordinate);
        static float coordP(float pCoordinate);

		static float distance(float dX0, float dY0, float dX1, float dY1);

		static float randomf(float min, float max);

		static int random(int min, int max);

		static bool probably(int pProbably);
    
        static long millisecondNow();

        static float round(float x);
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
};

#endif