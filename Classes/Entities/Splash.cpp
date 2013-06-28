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
    }

// ===========================================================
// Methods
// ===========================================================

void Splash::update(float pDeltaTime)
{
    if(!this->isVisible()) return;
    
    Entity::update(pDeltaTime);

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
    this->setRotation(Utils::randomf(-360.0, 360.0));

    this->runAction(CCFadeOut::create(2.0));
}

Splash* Splash::deepCopy()
{
    return new Splash();
}

#endif