#ifndef CONST_SPLASH_H
#define CONST_SPLASH_H

#include "cocos2d.h"

#include "Entity.h"

using namespace cocos2d;

class Splash : public Entity
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

		// ===========================================================
		// Constructors
		// ===========================================================
    
        Splash();

		// ===========================================================
		// Methods
		// ===========================================================

        void update(float pDelta);
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
    
        virtual void onCreate();
    
        virtual Splash* deepCopy();
};

#endif