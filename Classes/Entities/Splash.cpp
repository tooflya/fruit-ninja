#ifndef CONST_SPLASH
#define CONST_SPLASH

#include "Splash.h"

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

Splash::Splash() :
    Entity("splashes.png", 4, 2)
    {
        this->setAnchorPoint(ccp(0.5, 1.0));
    }

// ===========================================================
// Methods
// ===========================================================

void Splash::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
    
    this->mLiveTimeElapsed += pDeltaTime;
    
    if(this->mLiveTimeElapsed >= this->mLiveTime)
    {
        this->setOpacity(this->getOpacity() - this->mAlphaSpeed);
        this->setScaleY(this->getScaleY() + this->mScaleSpeed);
    }

    if(this->getOpacity() <= 0)
    {
    	this->destroy();
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Splash::onCreate()
{
    Entity::onCreate();
    
    this->setCurrentFrameIndex(Utils::random(0, 7));
    this->setOpacity(80.0);
    
    this->mLiveTime = Utils::randomf(1.5, 4.0);
    this->mLiveTimeElapsed = 0;
    
    this->mAlphaSpeed = Utils::randomf(0.1, 3.0);
    this->mScaleSpeed = 0.001;
    
    this->setScale(1.0);
}

Splash* Splash::deepCopy()
{
    return new Splash();
}

#endif