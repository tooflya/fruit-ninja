#ifndef CONST_DROP
#define CONST_DROP

#include "Drop.h"

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

Drop::Drop() :
    Entity("drops.png", 6, 3)
    {
    
    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void Drop::onCreate()
{
    Entity::onCreate();
    
    this->setScale(1.0);
    this->setOpacity(255.0);
    
    this->mScale = Utils::probably(50);
    this->mUp = Utils::probably(50);
    
    this->mScaleSpeed = Utils::randomf(0.01, 0.1);
    this->mMaxScale = Utils::randomf(1.0, 2.0);
    
    this->mAlphaSpeed = Utils::randomf(0.01, 0.1);
    
    this->mSpeedX = Utils::randomf(-10.0, 10.0);
    this->mSpeedY = Utils::randomf(1.0, 5.0);
    
    this->mWeight = Utils::randomf(0.1, 1.0);
}

void Drop::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(this->mScale)
    {
        this->setScale(this->getScaleX() + this->mScaleSpeed);
        
        if(this->getScaleX() >= this->mMaxScale)
        {
            this->mScale = !this->mScale;
        }
    }
    else
    {
        this->setScale(this->getScaleX() - this->mScaleSpeed);
    }
    
    this->setOpacity(this->getOpacity() - this->mAlphaSpeed);
    
    if(this->mUp)
    {
        this->setCenterPosition(this->getCenterX(), this->getCenterY() + this->mSpeedY);
        
        this->mSpeedY -= this->mWeight;
        
        if(this->mSpeedY <= 0.0)
        {
            this->mUp = !this->mUp;
        }
    }
    else
    {
        this->setCenterPosition(this->getCenterX(), this->getCenterY() - this->mSpeedY);
        
        this->mSpeedY += this->mWeight;
    }
    
    this->setCenterPosition(this->getCenterX() - this->mSpeedX, this->getCenterY());
    
    if(this->getScaleX() <= 0.0 || this->getOpacity() <= 0.0)
    {
        this->destroy();
    }
}

Drop* Drop::deepCopy()
{
    return new Drop();
}

#endif