#ifndef CONST_Part
#define CONST_Part

#include "Part.h"

#include "Menu.h"

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

Part::Part() :
    ImpulseEntity("parts.png", 6, 9)
    {
    }

// ===========================================================
// Methods
// ===========================================================

void Part::update(float pDeltaTime)
{
    if(!this->isVisible()) return;
    
    if(this->mAwesome)
    {
        this->setCenterPosition(this->getCenterX() + this->mAwesomeVectorX * Processor::FREEZY_TIME, this->getCenterY() + this->mAwesomeVectorY * Processor::FREEZY_TIME);
        
        this->setRotation(this->getRotation() - this->mRotateImpulse * pDeltaTime * Processor::FREEZY_TIME);
        
        if(this->getCenterX() < 0 || this->getCenterX() > Options::CAMERA_WIDTH || this->getCenterY() < 0 || this->getCenterY() > Options::CAMERA_HEIGHT)
        {
            this->destroy();
        }
    }
    else
    {
        ImpulseEntity::update(pDeltaTime);
    }
    
    if(this->getCenterY() < -Utils::coord(200) && this->mImpulsePower <= 0.0f)
    {
        this->destroy();
    }
}

void Part::setAwesome(int pCounter, int pCapacity)
{
    this->mAwesome = true;

    this->mAwesomeVectorX = Utils::coord(25.0f) * sin(pCounter * 2 * Utils::Pi / pCapacity);
    this->mAwesomeVectorY = Utils::coord(25.0f) * cos(pCounter * 2 * Utils::Pi / pCapacity);
}

void Part::setAwesomeByVectors(float pVectorX, float pVectorY)
{
    this->mAwesome = true;
    
    this->mAwesomeVectorX = Utils::coord(pVectorX);
    this->mAwesomeVectorY = Utils::coord(pVectorY);
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Part::onCreate()
{
    ImpulseEntity::onCreate();

    this->mAwesome = false;
    
    this->setScale(1.0);
    this->setRotation(0);
}

Part* Part::deepCopy()
{
    return new Part();
}

#endif