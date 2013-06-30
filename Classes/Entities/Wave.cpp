#ifndef CONST_WAVE
#define CONST_WAVE

#include "Wave.h"

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

Wave::Wave() :
    Entity("red-wave.png")
    {
    }

// ===========================================================
// Methods
// ===========================================================

void Wave::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
    
    if(this->getScaleX() >= 20.0 || this->getOpacity() <= 0.0)
    {
        this->destroy();
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Wave::onCreate()
{
    Entity::onCreate();
    
    this->setScale(0.0);
    this->setOpacity(255.0);
    
    this->runAction(CCScaleTo::create(1.7, 20.0));
    this->runAction(CCFadeTo::create(1.7, 0.0));
}

Wave* Wave::deepCopy()
{
    return new Wave();
}

#endif