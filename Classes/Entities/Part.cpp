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
            case Options::TYPE_REDAPPLE:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_APPLE);
            break;
            case Options::TYPE_GREENAPPLE:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_APPLE);
            break;
            case Options::TYPE_BANANA:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_BANANA);
            break;
            case Options::TYPE_COCONUT:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_COCONUT);
            break;
            case Options::TYPE_WATERMELON:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_WATERMELON);
            break;
            case Options::TYPE_KIWIFRUIT:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_KIWIFRUIT);
            break;
            case Options::TYPE_LEMON:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
            break;
            case Options::TYPE_LIME:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
            break;
            case Options::TYPE_MANGO:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
            break;
            case Options::TYPE_PEAR:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_ORANGE);
            break;
            case Options::TYPE_PINEAPPLE:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                break;
            case Options::TYPE_STARFRUIT:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                break;
            case Options::TYPE_STRAWBERRY:
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                break;
        }
        
        if(this->mType != Options::TYPE_BANANA && this->mType != Options::TYPE_DANGER)
        {
            menu->mDropsManager->init(this->getCenterX(), this->getCenterY(),this->mType);
        }
        
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