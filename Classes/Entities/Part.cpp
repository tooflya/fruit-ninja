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
    ImpulseEntity("parts.png", 6, 8)
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
        this->setCenterPosition(this->getCenterX() + this->mAwesomeVectorX, this->getCenterY() + this->mAwesomeVectorY);
        
        this->setRotation(this->getRotation() - this->mRotateImpulse * pDeltaTime);
        
        if(this->getCenterX() < 0 || this->getCenterX() > Options::CAMERA_WIDTH || this->getCenterY() < 0 || this->getCenterY() > Options::CAMERA_HEIGHT)
        {
            this->destroy();
        }
    }
    else
    {
        ImpulseEntity::update(pDeltaTime);
    }
    
    bool collides = false;
    
    for(int i = 0; i < 10; i++)
    {
        if(this->isCollideWithPoint(Processor::TOUCH_COORDINATES[i].x, Processor::TOUCH_COORDINATES[i].y))
        {
            collides = true;
        }
    }
    
    if(collides)
    {
        if(this->getScaleX() != 1) return;

        this->setScale(1.3);
        this->runAction(CCScaleTo::create(0.3, 1));

        Menu* menu = (Menu*) this->getParent()->getParent()->getParent();
        
        switch(this->mType)
        {
            case 1:
                SimpleAudioEngine::sharedEngine()->playEffect("impact-apple.ogg");
            break;
            case 2:
                SimpleAudioEngine::sharedEngine()->playEffect("impact-apple.ogg");
            break;
            case 3:
                SimpleAudioEngine::sharedEngine()->playEffect("impact-banana.ogg");
            break;
            case 4:
                SimpleAudioEngine::sharedEngine()->playEffect("impact-coconut.ogg");
            break;
            case 5:
                SimpleAudioEngine::sharedEngine()->playEffect("impact-watermelon.ogg");
            break;
            case 6:
                SimpleAudioEngine::sharedEngine()->playEffect("impact-kiwifruit.ogg");
            break;
            case 7:
                SimpleAudioEngine::sharedEngine()->playEffect("squash.mp3");
            break;
            case 8:
                SimpleAudioEngine::sharedEngine()->playEffect("squash.mp3");
            break;
            case 9:
                SimpleAudioEngine::sharedEngine()->playEffect("squash.mp3");
            break;
            case 10:
                SimpleAudioEngine::sharedEngine()->playEffect("impact-orange.ogg");
            break;
            case 11:
                SimpleAudioEngine::sharedEngine()->playEffect("squash.mp3");
            break;
        }
        
        menu->mDropsManager->init(this->getCenterX(), this->getCenterY(),this->mType);
        
        menu->addScore(10);
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

// ===========================================================
// Virtual Methods
// ===========================================================

void Part::onCreate()
{
    ImpulseEntity::onCreate();

    this->mAwesome = false;
    
    this->setScale(1.3);
    this->runAction(CCScaleTo::create(0.3, 1));
}

Part* Part::deepCopy()
{
    return new Part();
}

#endif