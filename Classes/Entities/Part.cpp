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
    ImpulseEntity("parts.png", 6, 6)
    {
    }

// ===========================================================
// Methods
// ===========================================================

void Part::update(float pDeltaTime)
{
    if(!this->isVisible()) return;
    
    ImpulseEntity::update(pDeltaTime);

    if(this->isCollideWithPoint(Menu::mTouchCoordinate.x, Menu::mTouchCoordinate.y))
    {
        if(this->getScaleX() != 1) return;

        this->setScale(1.3);
        this->runAction(CCScaleTo::create(0.3, 1));

        Menu* menu = (Menu*) this->getParent()->getParent();
        
        menu->mParticlesTypeFruits->setPosition(this->getCenterX(), this->getCenterY());
        //menu->mParticlesTypeFruits->resumeSystem();

        switch(this->mType)
        {
            case 1:
                menu->mParticlesTypeFruits->setPosition(this->getCenterX(), this->getCenterY());
                //menu->mParticlesTypeFruits->resumeSystem();

                SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-apple.ogg");
            break;
            case 2:
                menu->mParticlesTypeFruits->setPosition(this->getCenterX(), this->getCenterY());
               // menu->mParticlesTypeFruits->resumeSystem();

                SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-apple.ogg");
            break;
            case 3:
                menu->mParticlesTypeFruits->setPosition(this->getCenterX(), this->getCenterY());
                //menu->mParticlesTypeFruits->resumeSystem();

                SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-banana.ogg");
            break;
            case 4:
                menu->mParticlesTypeFruits->setPosition(this->getCenterX(), this->getCenterY());
               // menu->mParticlesTypeFruits->resumeSystem();

                SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-coconut.ogg");
            break;
            case 5:
                menu->mParticlesTypeFruits->setPosition(this->getCenterX(), this->getCenterY());
                //menu->mParticlesTypeFruits->resumeSystem();

                SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-watermelon.ogg");
            break;
            case 6:
                menu->mParticlesTypeFruits->setPosition(this->getCenterX(), this->getCenterY());
               // menu->mParticlesTypeFruits->resumeSystem();

                SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-kiwifruit.ogg");
            break;
            case 7:
                menu->mParticlesTypeFruits->setPosition(this->getCenterX(), this->getCenterY());
                //menu->mParticlesTypeFruits->resumeSystem();

                SimpleAudioEngine::sharedEngine()->playEffect("Sound/squash.mp3");
            break;
            case 8:
                menu->mParticlesTypeFruits->setPosition(this->getCenterX(), this->getCenterY());
               // menu->mParticlesTypeFruits->resumeSystem();

                SimpleAudioEngine::sharedEngine()->playEffect("Sound/squash.mp3");
            break;
            case 9:
                menu->mParticlesTypeFruits->setPosition(this->getCenterX(), this->getCenterY());
                //menu->mParticlesTypeFruits->resumeSystem();

                SimpleAudioEngine::sharedEngine()->playEffect("Sound/squash.mp3");
            break;
            case 10:
                menu->mParticlesTypeFruits->setPosition(this->getCenterX(), this->getCenterY());
                //menu->mParticlesTypeFruits->resumeSystem();

                SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-orange.ogg");
            break;
            case 11:
                menu->mParticlesTypeFruits->setPosition(this->getCenterX(), this->getCenterY());
               // menu->mParticlesTypeFruits->resumeSystem();

                SimpleAudioEngine::sharedEngine()->playEffect("Sound/squash.mp3");
            break;
        }

        Entity* splash = menu->mSplashes->create();
        splash->setCenterPosition(this->getCenterX(), this->getCenterY());

        switch(this->mType)
        {
            case 1:
                splash->setColor(ccc3(181.0, 40.0, 46.0));
            break;
            case 2:
                splash->setColor(ccc3(193.0, 214.0, 47.0));
            break;
            case 3:
                splash->setColor(ccc3(251.0, 226.0, 22.0));
            break;
            case 4:
                splash->setColor(ccc3(255.0, 255.0, 255.0));
            break;
            case 5:
                splash->setColor(ccc3(237.0, 51.0, 65.0));
            break;
            case 6:
                splash->setColor(ccc3(119.0, 190.0, 68.0));
            break;
            case 7:
                splash->setColor(ccc3(247.0, 207.0, 58.0));
            break;
            case 8:
                splash->setColor(ccc3(47.0, 165.0, 72.0));
            break;
            case 9:
                splash->setColor(ccc3(250.0, 166.0, 50.0));
            break;
            case 10:
                splash->setColor(ccc3(244.0, 107.0, 37.0));
            break;
            case 11:
                splash->setColor(ccc3(225.0, 204.0, 33.0));
            break;
        }
        
        menu->addScore(10);
    }
    
    if(this->getCenterY() < -Utils::coord(200) && this->mImpulsePower <= 0.0f)
    {
        this->destroy();
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Part::onCreate()
{
    ImpulseEntity::onCreate();

    this->setScale(1.3);
    this->runAction(CCScaleTo::create(0.3, 1));
}

Part* Part::deepCopy()
{
    return new Part();
}

#endif