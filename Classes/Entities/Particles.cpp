#ifndef CONST_PARTICLES
#define CONST_PARTICLES

#include "Particles.h"

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

Particles::Particles() :
    Entity("sm-parts.png", 2, 2)
    {
        
    }

// ===========================================================
// Methods
// ===========================================================

Particles* Particles::setType(int pType)
{
    this->mType = pType;
    
    switch(this->mType)
    {
        case TYPE_GARNET_CORE_BIG:
            this->setCurrentFrameIndex(1);
        break;
        case TYPE_GARNET_CORE_SMALL:
            this->setCurrentFrameIndex(1);
            
            this->mGarnetDropsTime = 0.3;
            this->mGarnetDropsTimeElapsed = this->mGarnetDropsTime;
        break;
    }
    
    return this;
}

void Particles::setAwesome(int pCounter, int pCapacity)
{
    this->mAwesomeVectorX = Utils::coord(25.0f) * sin(pCounter * 2 * Utils::Pi / pCapacity);
    this->mAwesomeVectorY = Utils::coord(25.0f) * cos(pCounter * 2 * Utils::Pi / pCapacity);
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Particles::onCreate()
{
    Entity::onCreate();
}
    
Particles* Particles::deepCopy()
{
    return new Particles();
}
    
void Particles::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
    
    switch(this->mType)
    {
        case TYPE_GARNET_CORE_BIG:
            
            break;
        case TYPE_GARNET_CORE_SMALL:
            
            this->setCenterPosition(this->getCenterX() + this->mAwesomeVectorX * Processor::FREEZY_TIME, this->getCenterY() + this->mAwesomeVectorY * Processor::FREEZY_TIME);
            
            this->mGarnetDropsTimeElapsed += pDeltaTime * Processor::FREEZY_TIME;
            
            if(this->mGarnetDropsTimeElapsed >= this->mGarnetDropsTime)
            {
                this->mGarnetDropsTimeElapsed = 0;
                
                
                Menu* menu = (Menu*) this->getParent()->getParent()->getParent();
                menu->mDropsManager->init(this->getCenterX(), this->getCenterY(), Options::TYPE_GARNET);
            }
            
            if(this->getCenterX() < 0 || this->getCenterX() > Options::CAMERA_WIDTH || this->getCenterY() < 0 || this->getCenterY() > Options::CAMERA_HEIGHT)
            {
                this->destroy();
            }
            break;
    }
}

#endif