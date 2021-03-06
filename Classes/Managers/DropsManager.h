#ifndef CONST_DROPSMANAGER_H
#define CONST_DROPSMANAGER_H

#include "cocos2d.h"

#include "Drop.h"
#include "BatchEntityManager.h"

using namespace cocos2d;

class DropsManager : public BatchEntityManager
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
    
        DropsManager(int pCreateCount, Entity* pEntity, CCNode* pScreen);

		// ===========================================================
		// Methods
		// ===========================================================
    
        void init(float pX, float pY, int pType);
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
};

#endif