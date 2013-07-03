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
    
    this->setScale(this->getScaleX() + this->mScaleSpeed * Processor::FREEZY_TIME);
    this->setOpacity(this->getOpacity() - this->mAlphaSpeed * Processor::FREEZY_TIME);
    
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
    
    this->mScaleSpeed = 0.2;
    this->mAlphaSpeed = 0.35;
}

Wave* Wave::deepCopy()
{
    return new Wave();
}

#endif