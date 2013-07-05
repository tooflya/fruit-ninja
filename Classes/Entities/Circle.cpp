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
    Entity("circles_sprite.png", 6, 2)
    {
        this->mFruitsManager = pFruitsManager;
        
        this->mRotationSpeed = Utils::randomf(-0.3, 0.3);
        
        this->mFruit = NULL;
    }

// ===========================================================
// Methods
// ===========================================================

void Circle::free()
{
    this->runAction(CCScaleTo::create(0.25, 0.0));
    
    this->mFruit->free();
}

void Circle::setCurrentFrameIndex(int pIndex)
{
    Entity::setCurrentFrameIndex(pIndex);
    
    CircleFruit* fruit = (CircleFruit*) this->mFruitsManager->create();
    this->mFruit = fruit;
    fruit->create()->setCenterPosition(this->getCenterX(), this->getCenterY());
    
    switch(pIndex)
    {
        case 0:
            fruit->setCurrentFrameIndex(Options::TYPE_COCONUT);
            fruit->setScale(1.0);
            break;
        case 1:
            fruit->setCurrentFrameIndex(Options::TYPE_REDAPPLE);
            fruit->setScale(1.0);
            break;
        case 2:
            fruit->setCurrentFrameIndex(Options::TYPE_ORANGE);
            fruit->setScale(0.7);
            break;
        case 11:
            fruit->setCurrentFrameIndex(Options::TYPE_LEMON);
            fruit->setScale(1.2);
            break;
        case 9:
            fruit->setCurrentFrameIndex(Options::TYPE_GREENAPPLE);
            fruit->setScale(1.0);
            break;
        case 5:
            fruit->setCurrentFrameIndex(Options::TYPE_COCONUT);
            fruit->setScale(1.0);
            break;
        case 6:
            fruit->setCurrentFrameIndex(Options::TYPE_STRAWBERRY);
            fruit->setScale(1.0);
            break;
        case 7:
            fruit->setCurrentFrameIndex(Options::TYPE_ORANGE);
            fruit->setScale(0.9);
            break;
        case 10:
            fruit->setCurrentFrameIndex(Options::TYPE_DANGER);
            fruit->setScale(1.0);
            fruit->setAnchorPoint(ccp(0.5, 0.36));
            break;
    }
    
    fruit->setRotationSpeed(-this->mRotationSpeed);
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Circle::onCreate()
{
    Entity::onCreate();
    
    if(this->mFruit != NULL)
    {
        this->mFruit->setScale(0.0);
        
        this->mFruit->mWeight = 0;
        this->mFruit->mSideImpulse = 0;
        this->mFruit->mImpulsePower = 0;
        this->mFruit->mRotateImpulse = 0;
        this->mFruit->create()->setCenterPosition(this->getCenterX(), this->getCenterY());
    }
}

void Circle::onDestroy()
{
    Entity::onDestroy();
    
    if(this->mFruit != NULL)
    this->mFruit->destroy(false);
}

void Circle::setScaleX(float pScale)
{
    Entity::setScale(pScale);
    
    if(!this->mFruit->free1)
    this->mFruit->setScale(pScale + (this->mFruit->is - 1.0));
}

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