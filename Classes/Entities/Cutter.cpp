#ifndef CONST_CUTTER
#define CONST_CUTTER

#include "Cutter.h"

#include "BatchEntityManager.h"

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

Cutter::Cutter(bool pBottomed) :
    Entity("cut-splash.png")
    {
        this->mBottomed = pBottomed;
        
        this->mTime = 1.0;
        this->mTimeElapsed = 0;
    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void Cutter::onCreate()
{
    Entity::onCreate();
    
    this->setScale(0.0);
    this->runAction(CCScaleTo::create(0.1, 1.0));
    
    this->mTimeElapsed = 0;
}

Cutter* Cutter::deepCopy()
{
    return new Cutter(this->mBottomed);
}
    
void Cutter::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
    
    if(this->mBottomed)
    {
        this->mTimeElapsed += pDeltaTime;
        
        if(this->mTimeElapsed > this->mTime)
        {
            this->mTimeElapsed = 0;
            
            this->destroy();
        }
        else
        {
            if(this->getBatchEntityManager()->getCount() > 2)
            {
                this->destroy();
            }
        }
    }
    else
    {
        if(this->getScaleX() >= 1.0)
        {
            this->destroy();
        }
    }
}

#endif