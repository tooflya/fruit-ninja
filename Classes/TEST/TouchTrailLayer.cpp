#ifndef CONST_TOUCHTRAILLAYER
#define CONST_TOUCHTRAILLAYER

#include "TouchTrailLayer.h"

#include "CCBlade.h"
#include "Menu.h"

#define kFileStreak "streak1-hd.png"

TouchTrailLayer::TouchTrailLayer()
{
    setTouchEnabled(true);

    this->mBladeParticleSystemQuad = CCParticleSystemQuad::create("blade_sparkle.plist");
    this->mBladeParticleSystemQuad->stopSystem();
    this->mBladeParticleSystemQuad->setPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

    this->mSunParticleSystemQuad = CCParticleSystemQuad::create("sun.plist");

    this->addChild(this->mSunParticleSystemQuad, 10);
    this->addChild(this->mBladeParticleSystemQuad, 10);

    this->mTimeBeforeNextBladeSound = 0.15f;
    this->mTimeBeforeNextBladeSoundElapsed = 0;

    this->scheduleUpdate();
}

TouchTrailLayer* TouchTrailLayer::create()
{
    TouchTrailLayer *pRet = new TouchTrailLayer();
    pRet->autorelease();
    return pRet;
}

void TouchTrailLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    this->mTimeBeforeNextBladeSoundElapsed = this->mTimeBeforeNextBladeSound;

    for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
        CCTouch *touch = (CCTouch *)*it;
		CCBlade *blade = CCBlade::create(kFileStreak, Utils::coord(10), 10);
        _map[touch] = blade;
		addChild(blade);
        
        blade->setColor(ccc3(255, 255, 255));
        blade->setOpacity(255);
        blade->setDrainInterval(1.0 / 60.0);
        
        CCPoint point = convertTouchToNodeSpace(touch);
		blade->push(point);

        this->mBladeParticleSystemQuad->setPosition(point);
        //this->mBladeParticleSystemQuad->resumeSystem();
	}
}

void TouchTrailLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
    for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
        CCTouch *touch = (CCTouch *)*it;
        if (_map.find(touch) == _map.end()) continue;
        
        CCBlade *blade = _map[touch];
        CCPoint point = convertTouchToNodeSpace(touch);
		blade->push(point);

        if(ccpDistance(point, this->mBladeLastCoordinates) > Utils::coord(200))
        {
            if(this->mTimeBeforeNextBladeSoundElapsed >= this->mTimeBeforeNextBladeSound)
            {
                this->mTimeBeforeNextBladeSoundElapsed = 0;

                SimpleAudioEngine::sharedEngine()->playEffect("Sound/swoosh.mp3");

                this->mBladeLastCoordinates = point;
            }
        }

        this->mBladeParticleSystemQuad->setPosition(point);

        Menu::mTouchCoordinate = point;
    }
}

void TouchTrailLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
        CCTouch *touch = (CCTouch *)*it;
        if (_map.find(touch) == _map.end()) continue;
        
        CCBlade *blade = _map[touch];
        blade->autoCleanup();
        _map.erase(touch);

        this->mBladeParticleSystemQuad->stopSystem();
    }

    Menu::mTouchCoordinate = ccp(-1000, -1000);
}

void TouchTrailLayer::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);

    this->mTimeBeforeNextBladeSoundElapsed += pDeltaTime;
}

#endif