#ifndef CONST_PART_H
#define CONST_PART_H

#include "cocos2d.h"

#include "ImpulseEntity.h"

using namespace cocos2d;

class Part : public ImpulseEntity
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

		// ===========================================================
		// Fields
        // ===========================================================

        int mType;

		// ===========================================================
		// Constructors
		// ===========================================================
    
        Part();

		// ===========================================================
		// Methods
		// ===========================================================

        void update(float pDelta);
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
    
        virtual void onCreate();
    
        virtual Part* deepCopy();
};

#endif