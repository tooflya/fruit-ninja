#ifndef CONST_HEART
#define CONST_HEART

#include "Heart.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int Heart::I = -1;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Heart::Heart() :
    Entity("lifes.png", 1, 2)
    {
    }

// ===========================================================
// Methods
// ===========================================================

void Heart::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
    
    if(this->getCurrentFrameIndex() == 0)
    {
        this->mTimeToBeatElapsed += pDeltaTime;
        
        if(this->mTimeToBeatElapsed >= this->mTimeToBeat)
        {
            if(this->mBeatCount == 0)
            {
                this->mTimeToBeatElapsed = 2.8;
                
                this->mBeatCount++;
            }
            else if(this->mBeatCount == 1)
            {
                this->mTimeToBeatElapsed = 2.8;
                
                this->mBeatCount++;
            }
            
            this->setScale(this->mInitScale);
            
            if(this->mBeatCount < 3)
            {
                this->runAction(CCScaleTo::create(0.1, this->mInitScale + 0.08));
                
                this->mTimeToBeatElapsed = 2.8;
                
                this->mBeatCount++;
            }
            else
            {
                this->mBeatCount = 0;
                this->mTimeToBeatElapsed = 0;
            }
        }
    }
}

void Heart::disable()
{
    this->setCurrentFrameIndex(1);
    
    this->setScale(this->mInitScale);
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Heart::onCreate()
{
    Entity::onCreate();
    
    I++;
    
    this->mTimeToBeat = 3.0;
    
    switch(I)
    {
        case 0:
            this->mTimeToBeatElapsed = 2.0;
            this->mInitScale = 0.5;
            break;
        case 1:
            this->mTimeToBeatElapsed = 1.0;
            this->mInitScale = 0.75;
            break;
        case 2:
            this->mTimeToBeatElapsed = 0.0;
            this->mInitScale = 1.0;
            break;
    }
    
    this->mBeatCount = 0;
}

Heart* Heart::deepCopy()
{
    return new Heart();
}

#endif