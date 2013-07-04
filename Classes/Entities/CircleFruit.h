#ifndef CONST_CIRCLEFRUIT_H
#define CONST_CIRCLEFRUIT_H

#include "cocos2d.h"

#include "ImpulseEntity.h"
#include "Processor.h"

using namespace cocos2d;

class CircleFruit : public ImpulseEntity
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
    
        float mRotationSpeed;

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
    
        CircleFruit();

		// ===========================================================
		// Methods
		// ===========================================================
    
        void setRotationSpeed(float pRotationSpeed);
    
        void free();
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
    
        void update(float pDeltaTime);
    
        void onCreate();
    
        CircleFruit* deepCopy();
};

#endif