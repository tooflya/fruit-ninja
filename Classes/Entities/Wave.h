#ifndef CONST_WAVE_H
#define CONST_WAVE_H

#include "cocos2d.h"

#include "Entity.h"

#include "Processor.h"

using namespace cocos2d;

class Wave : public Entity
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
    
        float mScaleSpeed;
        float mAlphaSpeed;

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

		// ===========================================================
		// Fields
        // ===========================================================

		// ===========================================================
		// Constructors
		// ===========================================================
    
        Wave();

		// ===========================================================
		// Methods
		// ===========================================================

        void update(float pDelta);
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
    
        virtual void onCreate();
    
        virtual Wave* deepCopy();
};

#endif