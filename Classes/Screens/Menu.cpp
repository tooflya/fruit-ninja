#ifndef CONST_MENU
#define CONST_MENU

#include "Menu.h"

#include "TouchTrailLayer.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int Menu::FRUITS = 0;
int Menu::SCORE = 0;
int Menu::LIFES = 0;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Menu::Menu()
{
    this->mParticlesTypeDanger = CCParticleSystemQuad::create("explosion.plist");
    this->mParticlesTypeDanger->stopSystem();

	/** Main menu layer **/
	this->mMainMenuLayer = CCLayer::create();

	/** Top layer **/
	this->mTopLayer = CCLayer::create();
	this->mTopLayer->setPosition(ccp(this->mTopLayer->getPosition().x, this->mTopLayer->getPosition().y + Utils::coord(200)));

    /** Bottom Layer */
	this->mBottomLayer = CCLayer::create();
	this->mBottomLayer->setPosition(ccp(this->mBottomLayer->getPosition().x, this->mBottomLayer->getPosition().y - Utils::coord(200)));
    
    /** Fruits Layer */
    this->mFruitsLayer = CCLayer::create();
    
	TouchTrailLayer* p = TouchTrailLayer::create();
    
	this->mFruitsLayer->addChild(p, 100);
    
    const char* backgrounds[3] = {"background.png", "background2.png",  "background3.png"};
    
    /** */
	this->mBackground = new Entity(backgrounds[Utils::random(0, 2)], this->mFruitsLayer);
    
	this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
	this->addChild(this->mFruitsLayer);
	this->addChild(this->mMainMenuLayer);
	this->mFruitsLayer->addChild(this->mTopLayer);
	this->mFruitsLayer->addChild(this->mBottomLayer);
    
    this->mMarks = new BatchEntityManager(20, new Mark(), this->mFruitsLayer);
	this->mShadows = new BatchEntityManager(20, new Entity("shadow.png"), this->mFruitsLayer);
	this->mWaves = new BatchEntityManager(5, new Wave(), this->mFruitsLayer);
	this->mSplashes = new BatchEntityManager(20, new Splash(), this->mFruitsLayer);
	this->mFruits = new BatchEntityManager(20, new Fruit(), this->mFruitsLayer);
	this->mParts = new BatchEntityManager(20, new Part(), this->mFruitsLayer);
	this->mCriticalHits = new BatchEntityManager(5, new Label("critical.png", 1, 1), this->mFruitsLayer);
	this->mSparks = new BatchEntityManager(200, new Spark(), this->mFruitsLayer);
	this->mCutters = new BatchEntityManager(20, new Cutter(), this->mFruitsLayer);
	this->mDropsManager = new DropsManager(100, new Drop(), this->mFruitsLayer);
    
    this->mWhiteEffect = new Entity("white.png");
    this->mWhiteEffect->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mFruitsLayer->addChild(this->mWhiteEffect, 100);

	this->addChild(this->mParticlesTypeDanger, 100);

	this->mFruitTime = 5.0;
	this->mFruitTimeElapsed = 0;

	this->mSpecialChalengeTime = 60.0;
	this->mSpecialChalengeTimeElapsed = 0;
    
	this->mTimeBeforeRestartElapsed = 0;
    
	this->mAwesomeFruitTime = 5.0;//Utils::randomf(15.0f, 150.0f);
	this->mAwesomeFruitTimeElapsed = 0;

	this->mFruitRemaning = 0;

	this->mFruitsSlashed = CCLabelTTF::create("0", Options::FONT, Utils::coord(64));
	this->mFruitsSlashed->setPosition(ccp(Utils::coord(90) + mFruitsSlashed->getContentSize().width / 2, Options::CAMERA_HEIGHT - Utils::coord(48)));

	this->mBestFruitsSlashed = CCLabelTTF::create("Best: 0", Options::FONT, Utils::coord(32));
	this->mBestFruitsSlashed->setPosition(ccp(Utils::coord(25) + mBestFruitsSlashed->getContentSize().width / 2, Options::CAMERA_HEIGHT - Utils::coord(100)));

	this->mScore = CCLabelTTF::create("Score: 0", Options::FONT, Utils::coord(32));
	this->mScore->setPosition(ccp(Utils::coord(25) + mScore->getContentSize().width / 2, Utils::coord(48)));

	this->mTopLayer->addChild(this->mFruitsSlashed, 101);
	this->mTopLayer->addChild(this->mBestFruitsSlashed, 101);
	this->mBottomLayer->addChild(this->mScore, 101);

	this->mCounter = new Entity("counter.png", this->mTopLayer);
	this->mCounter->create()->setCenterPosition(Utils::coord(48), Options::CAMERA_HEIGHT - Utils::coord(45));

	this->mLifes = new BatchEntityManager(3, new Heart(), this->mTopLayer);

	this->mLifes->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(176), Options::CAMERA_HEIGHT - Utils::coord(36));
	this->mLifes->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(128), Options::CAMERA_HEIGHT - Utils::coord(48));
	this->mLifes->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(64));
    
    ((Entity*) this->mLifes->objectAtIndex(0))->setScale(0.5);
    ((Entity*) this->mLifes->objectAtIndex(1))->setScale(0.75);

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic(Options::GAME_MUSIC, true);

	this->mIsGameRunning = false;

	//

	test = new Entity("test.png", this);
	//test->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

	//

	this->mSpecialLabel = CCLabelTTF::create("Fruit Combo", Options::FONT, Utils::coord(64));
	this->mSpecialLabelScore = CCLabelTTF::create("100 points", Options::FONT, Utils::coord(48));

	this->mSpecialLabel->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
	this->mSpecialLabelScore->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(50)));

	this->addChild(this->mSpecialLabel, 101);
	this->addChild(this->mSpecialLabelScore, 101);

	this->mSpecialLabel->setVisible(false);
	this->mSpecialLabelScore->setVisible(false);
    
	this->mIsSpecialChalengeRunning = false;
    this->mIsAwesomeChalengeRunning = false;

	this->mDebugInformationNeed = false;

	if(this->mDebugInformationNeed)
	{
		this->mDebugUpdateTime = 0.1;
		this->mDebugUpdateTimeElapsed = 0;

		this->mDebugInformation[0] = CCLabelTTF::create("Debug Information", Options::FONT, Utils::coord(24));
		this->mDebugInformation[1] = CCLabelTTF::create("Delta time: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[2] = CCLabelTTF::create("0.0000", Options::FONT, Utils::coord(16));
		this->mDebugInformation[3] = CCLabelTTF::create("Fruits: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[4] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));
		this->mDebugInformation[5] = CCLabelTTF::create("Parts: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[6] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));
		this->mDebugInformation[7] = CCLabelTTF::create("Sparks: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[8] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));
		this->mDebugInformation[9] = CCLabelTTF::create("Splashes: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[10] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));
		this->mDebugInformation[11] = CCLabelTTF::create("Marks: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[12] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));
		this->mDebugInformation[13] = CCLabelTTF::create("Shadows: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[14] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));
		this->mDebugInformation[15] = CCLabelTTF::create("Waves: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[16] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));
		this->mDebugInformation[17] = CCLabelTTF::create("Cutters: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[18] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));
		this->mDebugInformation[19] = CCLabelTTF::create("Drops: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[20] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));
		this->mDebugInformation[21] = CCLabelTTF::create("Current fps: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[22] = CCLabelTTF::create("0.0000", Options::FONT, Utils::coord(16));
		this->mDebugInformation[23] = CCLabelTTF::create("Average fps: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[24] = CCLabelTTF::create("0.0000", Options::FONT, Utils::coord(16));

		for(int i = 0; i < 25; i++)
		{
			this->addChild(this->mDebugInformation[i], 555);
		}

		this->mDebugInformation[0]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(203), Utils::coord(500)));
		this->mDebugInformation[1]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(262), Utils::coord(360)));
		this->mDebugInformation[2]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[2]->getContentSize().width / 2, Utils::coord(360)));
		this->mDebugInformation[3]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(277), Utils::coord(330)));
		this->mDebugInformation[4]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[4]->getContentSize().width / 2, Utils::coord(330)));
		this->mDebugInformation[5]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(279), Utils::coord(300)));
		this->mDebugInformation[6]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[6]->getContentSize().width / 2, Utils::coord(300)));
		this->mDebugInformation[7]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(273), Utils::coord(270)));
		this->mDebugInformation[8]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[8]->getContentSize().width / 2, Utils::coord(270)));
		this->mDebugInformation[9]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(264), Utils::coord(240)));
		this->mDebugInformation[10]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[10]->getContentSize().width / 2, Utils::coord(240)));
		this->mDebugInformation[11]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(274), Utils::coord(210)));
		this->mDebugInformation[12]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[12]->getContentSize().width / 2, Utils::coord(210)));
		this->mDebugInformation[13]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(263), Utils::coord(180)));
		this->mDebugInformation[14]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[14]->getContentSize().width / 2, Utils::coord(180)));
		this->mDebugInformation[15]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(271), Utils::coord(150)));
		this->mDebugInformation[16]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[16]->getContentSize().width / 2, Utils::coord(150)));
		this->mDebugInformation[17]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(269), Utils::coord(120)));
		this->mDebugInformation[18]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[18]->getContentSize().width / 2, Utils::coord(120)));
		this->mDebugInformation[19]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(273), Utils::coord(90)));
		this->mDebugInformation[20]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[20]->getContentSize().width / 2, Utils::coord(90)));
		this->mDebugInformation[21]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(258), Utils::coord(390)));
		this->mDebugInformation[22]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[22]->getContentSize().width / 2, Utils::coord(390)));
		this->mDebugInformation[23]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(256), Utils::coord(420)));
		this->mDebugInformation[24]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[24]->getContentSize().width / 2, Utils::coord(420)));
        
        this->mFpsCount = 0;
        this->mFpsSum = 0;
	}
}

// ===========================================================
// Methods
// ===========================================================

void Menu::startGame()
{
	LIFES = 0;
	SCORE = 0;
	FRUITS = -1;

	this->mSpecialChalengeTime = 60.0;
	this->mSpecialChalengeTimeElapsed = 0;
    
	this->mAwesomeFruitTime = 5.0;//Utils::randomf(15.0f, 150.0f);
	this->mAwesomeFruitTimeElapsed = 0;

	this->mIsSpecialChalengeRunning = false;
    this->mIsAwesomeChalengeRunning = false;
    
    this->mShaking = false;
    
    Processor::SPECIAL_FRUIT = NULL;
    Processor::AWESOME_FRUIT = NULL;

	this->updateCounter();
	this->addScore(0);

	for(int i = 0; i < 3; i++)
	{
		((Entity*) this->mLifes->objectAtIndex(i))->setCurrentFrameIndex(0);
	}

	this->mTimeBeforeRestartElapsed = 0;

	this->mFruits->clear();
	this->mParts->clear();
	this->mSplashes->clear();

	this->mFruits->resumeSchedulerAndActions();
	this->mParts->resumeSchedulerAndActions();
	this->mSplashes->resumeSchedulerAndActions();

	this->mIsGameRunning = true;

	this->mTopLayer->runAction(CCMoveTo::create(0.8, ccp(this->mTopLayer->getPosition().x, 0)));
	this->mBottomLayer->runAction(CCMoveTo::create(0.8, ccp(this->mBottomLayer->getPosition().x, 0)));

	SimpleAudioEngine::sharedEngine()->playEffect(Options::START_LEVEL);
}

void Menu::updateCounter()
{
	FRUITS++;

	char text[256];
	sprintf(text, "%d", FRUITS);
	this->mFruitsSlashed->setString(text);
	sprintf(text, "Best: %d", FRUITS);
	this->mBestFruitsSlashed->setString(text);

	this->mCounter->setScale(1.3);
	this->mCounter->runAction(CCScaleTo::create(0.3, 1));

	this->mFruitsSlashed->setPosition(ccp(Utils::coord(90) + this->mFruitsSlashed->getContentSize().width / 2, Options::CAMERA_HEIGHT - Utils::coord(48)));
	this->mBestFruitsSlashed->setPosition(ccp(Utils::coord(25) + this->mBestFruitsSlashed->getContentSize().width / 2, Options::CAMERA_HEIGHT - Utils::coord(100)));
}

void Menu::addScore(int pScore)
{
	SCORE += pScore;

	char text[256];
	sprintf(text, "Score: %d", SCORE);
	this->mScore->setString(text);

	this->mScore->setPosition(ccp(Utils::coord(25) + this->mScore->getContentSize().width / 2, Utils::coord(48)));
}

void Menu::removeLife()
{
	((Heart*) this->mLifes->objectAtIndex(LIFES))->disable();

    LIFES++;
    
	if(LIFES == 3)
	{
		this->mFruits->pauseSchedulerAndActions();
		this->mParts->pauseSchedulerAndActions();
		this->mSplashes->pauseSchedulerAndActions();

		this->mIsGameRunning = false;

		SimpleAudioEngine::sharedEngine()->playEffect(Options::GAME_OVER);
	}
}

void Menu::runSpecialChalenge()
{
	if(this->mIsSpecialChalengeRunning)
	{
		this->mSpecialChalengeTime = 1000.0;

		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(Options::COMBO_BLITZ_BACKING_LIGHT, true);
	}
	else
	{
		this->mIsSpecialChalengeRunning = true;

		this->mSpecialChalengeTime = 3.0;

		SimpleAudioEngine::sharedEngine()->playEffect(Options::COMBO_BLITZ_BACKING);
	}
}

void Menu::runAwesomeChalenge()
{
    ((Fruit*) this->mFruits->create())->setAwesomeChalenge();
    
    this->mIsAwesomeChalengeRunning = true;
}

void Menu::stopSpecialChalenge()
{
	this->mIsSpecialChalengeRunning = false;

	this->mSpecialChalengeTime = 60.0;
	this->mSpecialChalengeTimeElapsed = 0;

	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic(Options::NATURE_BGM, true);
	
	SimpleAudioEngine::sharedEngine()->playEffect(Options::COMBO_BLITZ_BACKING_END);
}

void Menu::hitedAwesome()
{
    this->randomSlide();
    
    this->mWhiteEffect->create()->setOpacity(100.0);
    this->mWhiteEffect->runAction(CCFadeTo::create(0.3, 0.0));
    
    if(this->mFruitsLayer->getScaleX() != 1.0) return;
    if(Processor::AWESOME_FRUIT == NULL) return;
    
    this->mFruitsLayer->setAnchorPoint(ccp(Processor::AWESOME_FRUIT->getCenterX() / Options::CAMERA_WIDTH, Processor::AWESOME_FRUIT->getCenterY() / Options::CAMERA_HEIGHT));
    
    this->mFruitsLayer->runAction(CCScaleTo::create(0.3, 1.7));
    this->mFruitsLayer->runAction(CCRotateTo::create(0.3, Utils::randomf(-50.0, 50.0)));
    
    Processor::FREEZY_TIME = 0.1;
}

void Menu::hitedAwesomeLast()
{
    this->mFruitsLayer->setAnchorPoint(ccp(0.5, 0.5));
    this->mFruitsLayer->setScale(1.7);
    this->mFruitsLayer->runAction(CCScaleTo::create(0.2, 1.0));
    
    SimpleAudioEngine::sharedEngine()->playEffect(Options::BONUS_BLOW);
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Menu::update(float pDeltaTime)
{
	Screen::update(pDeltaTime);
    
	if(!this->mIsGameRunning)
	{
		this->mTimeBeforeRestartElapsed += pDeltaTime;

		if(this->mTimeBeforeRestartElapsed >= 1.0) // 7)
		{
            this->mTimeBeforeRestartElapsed = 0;
            
			this->startGame();
		}

		return;
	}
	
	if(this->mIsSpecialChalengeRunning)
	{
		this->mFruitTimeElapsed += pDeltaTime * Processor::FREEZY_TIME;

		if(this->mFruitTimeElapsed >= 0.3)
		{
			this->mFruitTimeElapsed = 0;

			((Fruit*) this->mFruits->create())->setSpecialChalenge();

			this->mFruitRemaning++;

			SimpleAudioEngine::sharedEngine()->playEffect(Options::TOSS_SIMULTANEOUS);

			if(this->mFruitRemaning >= 100)
			{
				this->stopSpecialChalenge();
			}
		}
	}
	else
	{
		this->mFruitTimeElapsed += pDeltaTime * Processor::FREEZY_TIME;

		if(this->mFruitTimeElapsed >= this->mFruitTime)
		{
			this->mFruitTimeElapsed = 0;

			if(this->mFruitRemaning == 0)
			{
				this->mFruitRemaning = Utils::random(1, 6);
			}

			this->mFruitTime = Utils::randomf(0.0, 1.5);

			this->mFruits->create();

			SimpleAudioEngine::sharedEngine()->playEffect(Options::TOSS_SIMULTANEOUS);

			this->mFruitRemaning--;

			if(this->mFruitRemaning == 0)
			{
				this->mFruitTime = Utils::randomf(2.0, 7.0);
			}
		}
	}

	if(Processor::SPECIAL_FRUIT != NULL)
	{
		this->mSpecialLabel->setPosition(ccp(Processor::SPECIAL_FRUIT->getCenterX() + (Processor::SPECIAL_FRUIT->getCenterX() < (Options::CAMERA_HEIGHT - Utils::coord(250)) ? Utils::coord(250) : -Utils::coord(250)), Processor::SPECIAL_FRUIT->getCenterY()));
		this->mSpecialLabelScore->setPosition(ccp(this->mSpecialLabel->getPosition().x, this->mSpecialLabel->getPosition().y - Utils::coord(50)));
	}

	// Special Chalenge

	this->mSpecialChalengeTimeElapsed += pDeltaTime;

	if(this->mSpecialChalengeTimeElapsed >= this->mSpecialChalengeTime)
	{
		this->mSpecialChalengeTimeElapsed = 0;

		this->runSpecialChalenge();
	}
    
    // Awesome fruit
    
    this->mAwesomeFruitTimeElapsed += pDeltaTime;
    
    if(this->mIsAwesomeChalengeRunning)
    {
        if(this->mAwesomeFruitTimeElapsed >= this->mAwesomeFruitTime)
        {
            this->mAwesomeFruitTimeElapsed = 0;
            this->mAwesomeFruitTime = 1.0;
            
            this->mIsAwesomeChalengeRunning = false;
            
            Processor::AWESOME_FRUIT = NULL;
            
            this->mFruitsLayer->runAction(CCScaleTo::create(0.3, 1.0));
            this->mFruitsLayer->runAction(CCRotateTo::create(0.3, 0.0));
        }
    }
    else if(Processor::AWESOME_FRUIT == NULL)
    {
        if(this->mAwesomeFruitTimeElapsed >= this->mAwesomeFruitTime)
        {
            if(Processor::FREEZY_TIME == 1.0)
            {
                this->mAwesomeFruitTimeElapsed = 0;
                this->mAwesomeFruitTime = 3.0;
        
                this->runAwesomeChalenge();
            }
            else
            {
                Processor::FREEZY_TIME = 1.0;
                
                this->mAwesomeFruitTimeElapsed = 0;
                this->mAwesomeFruitTime = 5.0;//Utils::randomf(15.0, 300.0);
            }
        }
    }

	// Debug Information

	if(this->mDebugInformationNeed)
	{
		this->mDebugUpdateTimeElapsed += pDeltaTime;

		if(this->mDebugUpdateTimeElapsed >= this->mDebugUpdateTime)
		{
			this->mDebugUpdateTimeElapsed = 0;

            float dt = CCDirector::sharedDirector()->getDeltaTime();
            float fps = 1.0 / dt;
            
            this->mFpsCount++;
            this->mFpsSum += fps;
            
			char text[256];
			sprintf(text, "%f", dt);
			this->mDebugInformation[2]->setString(text);
			sprintf(text, "%d / %d / %d", this->mFruits->getCount(), this->mFruits->getCapacity(), this->mFruits->getInitCapacity());
			this->mDebugInformation[4]->setString(text);
            if(this->mFruits->getCapacity() > this->mFruits->getInitCapacity()) this->mDebugInformation[4]->setColor(ccc3(255.0, 0.0, 0.0));
			sprintf(text, "%d / %d / %d", this->mParts->getCount(), this->mParts->getCapacity(), this->mParts->getInitCapacity());
			this->mDebugInformation[6]->setString(text);
            if(this->mParts->getCapacity() > this->mParts->getInitCapacity()) this->mDebugInformation[6]->setColor(ccc3(255.0, 0.0, 0.0));
			sprintf(text, "%d / %d / %d", this->mSparks->getCount(), this->mSparks->getCapacity(), this->mSparks->getInitCapacity());
			this->mDebugInformation[8]->setString(text);
            if(this->mSparks->getCapacity() > this->mSparks->getInitCapacity()) this->mDebugInformation[8]->setColor(ccc3(255.0, 0.0, 0.0));
			sprintf(text, "%d / %d / %d", this->mSplashes->getCount(), this->mSplashes->getCapacity(), this->mSplashes->getInitCapacity());
			this->mDebugInformation[10]->setString(text);
            if(this->mSplashes->getCapacity() > this->mSplashes->getInitCapacity()) this->mDebugInformation[10]->setColor(ccc3(255.0, 0.0, 0.0));
			sprintf(text, "%d / %d / %d", this->mMarks->getCount(), this->mMarks->getCapacity(), this->mMarks->getInitCapacity());
			this->mDebugInformation[12]->setString(text);
            if(this->mMarks->getCapacity() > this->mMarks->getInitCapacity()) this->mDebugInformation[12]->setColor(ccc3(255.0, 0.0, 0.0));
			sprintf(text, "%d / %d / %d", this->mShadows->getCount(), this->mShadows->getCapacity(), this->mShadows->getInitCapacity());
			this->mDebugInformation[14]->setString(text);
            if(this->mShadows->getCapacity() > this->mShadows->getInitCapacity()) this->mDebugInformation[14]->setColor(ccc3(255.0, 0.0, 0.0));
			sprintf(text, "%d / %d / %d", this->mWaves->getCount(), this->mWaves->getCapacity(), this->mWaves->getInitCapacity());
			this->mDebugInformation[16]->setString(text);
            if(this->mWaves->getCapacity() > this->mWaves->getInitCapacity()) this->mDebugInformation[16]->setColor(ccc3(255.0, 0.0, 0.0));
			sprintf(text, "%d / %d / %d", this->mCutters->getCount(), this->mCutters->getCapacity(), this->mCutters->getInitCapacity());
			this->mDebugInformation[18]->setString(text);
            if(this->mCutters->getCapacity() > this->mCutters->getInitCapacity()) this->mDebugInformation[18]->setColor(ccc3(255.0, 0.0, 0.0));
			sprintf(text, "%d / %d / %d", this->mDropsManager->getCount(), this->mDropsManager->getCapacity(), this->mDropsManager->getInitCapacity());
			this->mDebugInformation[20]->setString(text);
            if(this->mDropsManager->getCapacity() > this->mDropsManager->getInitCapacity()) this->mDebugInformation[20]->setColor(ccc3(255.0, 0.0, 0.0));
			sprintf(text, "%f", fps);
			this->mDebugInformation[22]->setString(text);
			sprintf(text, "%f", this->mFpsSum / this->mFpsCount);
			this->mDebugInformation[24]->setString(text);
            
            if(this->mFpsSum / this->mFpsCount < 55.0)
            {
                this->mDebugInformation[24]->setColor(ccc3(255.0, 0.0, 0.0));
            }
            else
            {
                this->mDebugInformation[24]->setColor(ccc3(255.0, 255.0, 255.0));
            }
            
            if(fps < 55.0)
            {
                this->mDebugInformation[22]->setColor(ccc3(255.0, 0.0, 0.0));
            }
            else
            {
                this->mDebugInformation[22]->setColor(ccc3(255.0, 255.0, 255.0));
            }

			this->mDebugInformation[2]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[2]->getContentSize().width / 2, Utils::coord(360)));
			this->mDebugInformation[4]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[4]->getContentSize().width / 2, Utils::coord(330)));
			this->mDebugInformation[6]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[6]->getContentSize().width / 2, Utils::coord(300)));
			this->mDebugInformation[8]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[8]->getContentSize().width / 2, Utils::coord(270)));
			this->mDebugInformation[10]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[10]->getContentSize().width / 2, Utils::coord(240)));
			this->mDebugInformation[12]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[12]->getContentSize().width / 2, Utils::coord(210)));
			this->mDebugInformation[14]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[14]->getContentSize().width / 2, Utils::coord(180)));
			this->mDebugInformation[16]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[16]->getContentSize().width / 2, Utils::coord(150)));
			this->mDebugInformation[18]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[18]->getContentSize().width / 2, Utils::coord(120)));
			this->mDebugInformation[20]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[20]->getContentSize().width / 2, Utils::coord(90)));
			this->mDebugInformation[22]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[22]->getContentSize().width / 2, Utils::coord(390)));
			this->mDebugInformation[24]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[24]->getContentSize().width / 2, Utils::coord(420)));
		}
	}
    
    if(this->mShaking)
	{
		this->mShakeDurationElapsed += pDeltaTime;
        
		if(this->mShakeDurationElapsed > this->mShakeDuration)
		{
			this->mShaking = false;
			this->mShakeDuration = 0;
            
            this->mFruitsLayer->setPosition(ccp(0, 0));
		}
		else
		{
			int sentitX = 1;
			int sentitY = 1;
            
			if(Utils::randomf(0, 1) < 0.5) sentitX = -1;
			if(Utils::randomf(0, 1) < 0.5) sentitY = -1;
            
			this->mFruitsLayer->setPosition(this->mFruitsLayer->getPosition().x + Utils::randomf(0, 1) * this->mShakeIntensity * sentitX, this->mFruitsLayer->getPosition().y + Utils::randomf(0, 1) * this->mShakeIntensity * sentitY);
		}
	}
    
    if(this->mSlide)
    {
		if(this->mSlideOperations < 0)
        {
            this->mFruitsLayer->setPosition(this->mFruitsLayer->getPosition().x + this->mSlideVectorX * pDeltaTime, this->mFruitsLayer->getPosition().y + this->mSlideVectorY * pDeltaTime);
        }
        else
        {
            this->mFruitsLayer->setPosition(this->mFruitsLayer->getPosition().x - this->mSlideVectorX * pDeltaTime, this->mFruitsLayer->getPosition().y - this->mSlideVectorY * pDeltaTime);
        }
        
        this->mSlideOperations++;
        
        if(this->mSlideOperations >= 10)
        {
            this->mSlide = false;
            
            this->mFruitsLayer->setPosition(ccp(0, 0));
        }
    }
}

void Menu::randomSlide()
{
    if(this->mSlide) return;
        
    this->mSlide = true;
    
    this->mSlideOperations = -10;
    
    this->mSlideVectorX = Utils::randomf(-1000.0, 1000.0);
    this->mSlideVectorY = Utils::randomf(-1000.0, 1000.0);
}

void Menu::shake(float d, float i)
{
	this->mShaking = true;
	this->mShakeDuration = d;
	this->mShakeIntensity = i;
    
	this->mShakeDurationElapsed = 0;
}

void Menu::onEnter()
{
	Screen::onEnter();
}

#endif