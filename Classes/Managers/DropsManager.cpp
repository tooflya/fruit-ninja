#ifndef CONST_DROPSMANAGER
#define CONST_DROPSMANAGER

#include "DropsManager.h"

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

DropsManager::DropsManager(int pCreateCount, Entity* pEntity, CCNode* pScreen) :
    BatchEntityManager(pCreateCount, pEntity, pScreen)
    {
    
    }

// ===========================================================
// Methods
// ===========================================================

void DropsManager::init(float pX, float pY, int pType)
{
    for(int i = 0; i < 50; i++)
    {
        Entity* particle = (Entity*) this->create();
        
        particle->setCenterPosition(pX, pY);
        particle->setCurrentFrameIndex(pType);
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

#endif