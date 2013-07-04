#ifndef CONST_CIRCLE
#define CONST_CIRCLE

#include "Circle.h"

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

Circle::Circle(BatchEntityManager* pFruitsManager) :
    Entity("main_menu_circles.png", 2, 2)
    {
        this->mFruitsManager = pFruitsManager;
        
        this->mRotationSpeed = Utils::randomf(-0.3, 0.3);
    }

// ===========================================================
// Methods
// ===========================================================

void Circle::free()
{
    this->runAction(CCScaleTo::create(0.25, 0.0));
}

void Circle::onCreate()
{
    Entity::onCreate();
}

void Circle::setCurrentFrameIndex(int pIndex)
{
    Entity::setCurrentFrameIndex(pIndex);
    
    CircleFruit* fruit = (CircleFruit*) this->mFruitsManager->create();
    fruit->create()->setCenterPosition(this->getCenterX(), this->getCenterY());
    
    switch(pIndex)
    {
        case 0:
            fruit->setCurrentFrameIndex(Options::TYPE_COCONUT);
            break;
        case 1:
            fruit->setCurrentFrameIndex(Options::TYPE_ORANGE);
            fruit->setScale(0.7);
            break;
        case 2:
            fruit->setCurrentFrameIndex(Options::TYPE_REDAPPLE);
            break;
        case 3:
            fruit->setCurrentFrameIndex(Options::TYPE_LEMON);
            fruit->setScale(1.2);
            break;
    }
    
    fruit->setRotationSpeed(-this->mRotationSpeed);
}

// ===========================================================
// Virtual Methods
// ===========================================================
    
void Circle::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
    
    this->setRotation(this->getRotation() + this->mRotationSpeed);
}

Circle* Circle::deepCopy()
{
    return new Circle(this->mFruitsManager);
}

#endif