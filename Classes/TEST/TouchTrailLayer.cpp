#ifndef CONST_TOUCHTRAILLAYER
#define CONST_TOUCHTRAILLAYER

#include "TouchTrailLayer.h"

#include "CCBlade.h"
#include "Menu.h"

#define kFileStreak "streak1-hd.png"

TouchTrailLayer::TouchTrailLayer()
{
    setTouchEnabled(true);
    
    this->mSunParticleSystemQuad = CCParticleSystemQuad::create("sun.plist");

    this->addChild(this->mSunParticleSystemQuad, 10);

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
		CCBlade *blade = CCBlade::create(kFileStreak, 20, 12);
        _map[touch] = blade;
		addChild(blade);
        
        blade->setDrainInterval(1.0 / 60.0);
        
        CCPoint point = convertTouchToNodeSpace(touch);
		blade->push(point);
        
        Processor::TOUCH_COORDINATES_TIME[touch->getID()] = Utils::millisecondNow();
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
        
        if(abs(ccpDistance(point, Processor::TOUCH_COORDINATES_TIME_C[touch->getID()])) > Utils::coord(50))
        {
            float dtime = 20.0;
            
            if(Utils::millisecondNow() - Processor::TOUCH_COORDINATES_TIME[touch->getID()] < dtime && this->mTimeBeforeNextBladeSoundElapsed > 0.1)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SWOOSH);
                
                this->mTimeBeforeNextBladeSoundElapsed = 0;
            }
            
            Processor::TOUCH_COORDINATES_TIME_C[touch->getID()] = point;
            Processor::TOUCH_COORDINATES_TIME[touch->getID()] = Utils::millisecondNow();
            
        }
        
        Processor::TOUCH_COORDINATES[touch->getID()] = point;
    }
}

void TouchTrailLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    int i = -1;
    for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
        i++;
        
        CCTouch *touch = (CCTouch *)*it;
        if (_map.find(touch) == _map.end()) continue;
        
        CCBlade *blade = _map[touch];
        blade->autoCleanup();
        _map.erase(touch);
        
        Processor::TOUCH_COORDINATES[touch->getID()] = ccp(-1000, -1000);
    }
}

void TouchTrailLayer::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);

    this->mTimeBeforeNextBladeSoundElapsed += pDeltaTime;
}

#endif