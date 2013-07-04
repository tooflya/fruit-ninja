#ifndef CONST_CIRCLEFRUIT
#define CONST_CIRCLEFRUIT

#include "CircleFruit.h"

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

CircleFruit::CircleFruit() :
    ImpulseEntity("fruits.png", 6, 3)
    {
    }

// ===========================================================
// Methods
// ===========================================================

void CircleFruit::setRotationSpeed(float pRotationSpeed)
{
    this->mRotationSpeed = pRotationSpeed;
}

void CircleFruit::free()
{
    this->mWeight = Utils::coord(1200.0f);
    this->mImpulsePower = Utils::coord(600.0f);
    this->mSideImpulse   = Utils::coord(Utils::randomf(-300.0f, 300.0f));
    this->mRotateImpulse = Utils::randomf(-360.0f, 360.0f);
}

// ===========================================================
// Virtual Methods
// ===========================================================

void CircleFruit::onCreate()
{
    Entity::onCreate();
}
    
CircleFruit* CircleFruit::deepCopy()
{
    return new CircleFruit();
}
    
void CircleFruit::update(float pDeltaTime)
{
    ImpulseEntity::update(pDeltaTime * 2.0);
    
    if(!this->isVisible()) return;
    
    this->setRotation(this->getRotation() + this->mRotationSpeed);
}

#endif