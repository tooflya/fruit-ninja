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
        this->is = 0;
        this->free1 = false;
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
    
    this->free1 = true;
}

// ===========================================================
// Virtual Methods
// ===========================================================

void CircleFruit::onCreate()
{
    Entity::onCreate();
    
    this->free1 = false;
}

CircleFruit* CircleFruit::deepCopy()
{
    return new CircleFruit();
}
    
void CircleFruit::update(float pDeltaTime)
{
    ImpulseEntity::update(pDeltaTime * 2.3);
    
    if(!this->isVisible()) return;
    
    this->setRotation(this->getRotation() + this->mRotationSpeed);
    
    if(this->getCenterY() < -Utils::coord(200))
    {
        this->destroy(false);
    }
}

void CircleFruit::setScale(float pScale)
{
    if(pScale < 0) pScale = 0;
    
    ImpulseEntity::setScale(pScale);
    
    if(this->is == 0)
    {
        this->is = pScale;
    }
}


#endif