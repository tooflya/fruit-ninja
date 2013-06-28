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

CCPoint Menu::mTouchCoordinate = ccp(-1000, -1000);

int Menu::FRUITS = 0;
int Menu::SCORE = 0;
int Menu::LIFES = 0;

Entity* Menu::SPECIAL_FRUIT = NULL;

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

    this->mParticlesTypeFruits = CCParticleSystemQuad::create("fruits.plist");
    this->mParticlesTypeFruits->stopSystem();

	TouchTrailLayer* p = TouchTrailLayer::create();

	this->mBackground = new Entity("background.png", this);

	this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

	this->addChild(p, 100);

	/** Main menu layer **/
	this->mMainMenuLayer = CCLayer::create();

	//(new Entity("gamename.png", this->mMainMenuLayer))->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
	//(new Entity("swords.png", this->mMainMenuLayer))->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

	/** Top layer **/
	this->mTopLayer = CCLayer::create();
	this->mTopLayer->setPosition(ccp(this->mTopLayer->getPosition().x, this->mTopLayer->getPosition().y + Utils::coord(200)));

	this->mBottomLayer = CCLayer::create();
	this->mBottomLayer->setPosition(ccp(this->mBottomLayer->getPosition().x, this->mBottomLayer->getPosition().y - Utils::coord(200)));

	this->addChild(this->mMainMenuLayer);
	this->addChild(this->mTopLayer);
	this->addChild(this->mBottomLayer);

	this->mSplashes = new BatchEntityManager(20, new Splash(), this);
	this->mFruits = new BatchEntityManager(20, new Fruit(), this);
	this->mParts = new BatchEntityManager(20, new Part(), this);
	this->mCriticalHits = new BatchEntityManager(5, new Label("critical.png", 1, 1), this);
	this->mSparks = new BatchEntityManager(200, new Spark(), this);

	this->addChild(this->mParticlesTypeDanger, 100);
	this->addChild(this->mParticlesTypeFruits, 100);

	this->mFruitTime = 5.0;
	this->mFruitTimeElapsed = 0;

	this->mSpecialChalengeTime = 60.0;
	this->mSpecialChalengeTimeElapsed = 0;

	this->mFruitRemaning = 0;

	this->mFruitsSlashed = CCLabelTTF::create("0", "Fonts/go3v2.ttf", Utils::coord(64));
	this->mFruitsSlashed->setPosition(ccp(Utils::coord(90) + mFruitsSlashed->getContentSize().width / 2, Options::CAMERA_HEIGHT - Utils::coord(48)));

	this->mBestFruitsSlashed = CCLabelTTF::create("Best: 0", "Fonts/go3v2.ttf", Utils::coord(32));
	this->mBestFruitsSlashed->setPosition(ccp(Utils::coord(25) + mBestFruitsSlashed->getContentSize().width / 2, Options::CAMERA_HEIGHT - Utils::coord(100)));

	this->mScore = CCLabelTTF::create("Score: 0", "Fonts/go3v2.ttf", Utils::coord(32));
	this->mScore->setPosition(ccp(Utils::coord(25) + mScore->getContentSize().width / 2, Utils::coord(48)));

	this->mTopLayer->addChild(this->mFruitsSlashed, 101);
	this->mTopLayer->addChild(this->mBestFruitsSlashed, 101);
	this->mBottomLayer->addChild(this->mScore, 101);

	this->mCounter = new Entity("counter.png", this->mTopLayer);
	this->mCounter->create()->setCenterPosition(Utils::coord(48), Options::CAMERA_HEIGHT - Utils::coord(50));

	this->mLifes = new BatchEntityManager(3, new Entity("lifes.png", 1, 2), this->mTopLayer);

	for(int i = 3; i > 0; i--)
	{
		this->mLifes->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(64) * i, Options::CAMERA_HEIGHT - Utils::coord(64));
	}

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Music/nature_bgm.mp3", true);

	this->mIsGameRunning = false;

	//

	test = new Entity("test.png", this);
	//test->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

	//

	this->mSpecialLabel = CCLabelTTF::create("Fruit Combo", "Fonts/go3v2.ttf", Utils::coord(64));
	this->mSpecialLabelScore = CCLabelTTF::create("100 points", "Fonts/go3v2.ttf", Utils::coord(48));

	this->mSpecialLabel->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
	this->mSpecialLabelScore->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(50)));

	this->addChild(this->mSpecialLabel, 101);
	this->addChild(this->mSpecialLabelScore, 101);

	this->mSpecialLabel->setVisible(false);
	this->mSpecialLabelScore->setVisible(false);

	this->mDebugInformationNeed = false;

	if(this->mDebugInformationNeed)
	{
		this->mDebugUpdateTime = 1.0;
		this->mDebugUpdateTimeElapsed = 0;

		this->mDebugInformation[0] = CCLabelTTF::create("Debug Information", "Fonts/go3v2.ttf", Utils::coord(24));
		this->mDebugInformation[1] = CCLabelTTF::create("Current fps: ", "Fonts/go3v2.ttf", Utils::coord(16));
		this->mDebugInformation[2] = CCLabelTTF::create("60", "Fonts/go3v2.ttf", Utils::coord(16));
		this->mDebugInformation[3] = CCLabelTTF::create("Fruits: ", "Fonts/go3v2.ttf", Utils::coord(16));
		this->mDebugInformation[4] = CCLabelTTF::create("0 / 0", "Fonts/go3v2.ttf", Utils::coord(16));
		this->mDebugInformation[5] = CCLabelTTF::create("Parts: ", "Fonts/go3v2.ttf", Utils::coord(16));
		this->mDebugInformation[6] = CCLabelTTF::create("0 / 0", "Fonts/go3v2.ttf", Utils::coord(16));
		this->mDebugInformation[7] = CCLabelTTF::create("Sparks: ", "Fonts/go3v2.ttf", Utils::coord(16));
		this->mDebugInformation[8] = CCLabelTTF::create("0 / 0", "Fonts/go3v2.ttf", Utils::coord(16));
		this->mDebugInformation[9] = CCLabelTTF::create("Splashes: ", "Fonts/go3v2.ttf", Utils::coord(16));
		this->mDebugInformation[10] = CCLabelTTF::create("0 / 0", "Fonts/go3v2.ttf", Utils::coord(16));

		for(int i = 0; i < 11; i++)
		{
			this->addChild(this->mDebugInformation[i], 555);
		}

		this->mDebugInformation[0]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200), Utils::coord(300)));
		this->mDebugInformation[1]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(258), Utils::coord(270)));
		this->mDebugInformation[2]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[2]->getContentSize().width / 2, Utils::coord(270)));
		this->mDebugInformation[3]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(282), Utils::coord(240)));
		this->mDebugInformation[4]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[4]->getContentSize().width / 2, Utils::coord(240)));
		this->mDebugInformation[5]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(284), Utils::coord(210)));
		this->mDebugInformation[6]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[6]->getContentSize().width / 2, Utils::coord(210)));
		this->mDebugInformation[7]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(278), Utils::coord(180)));
		this->mDebugInformation[8]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[8]->getContentSize().width / 2, Utils::coord(180)));
		this->mDebugInformation[9]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(269), Utils::coord(150)));
		this->mDebugInformation[10]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[10]->getContentSize().width / 2, Utils::coord(150)));
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

	this->mIsSpecialChalengeRunning = false;

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

	this->mTopLayer->runAction(CCMoveTo::create(0.8, ccp(this->mTopLayer->getPosition().x, this->mTopLayer->getPosition().y - Utils::coord(200))));
	this->mBottomLayer->runAction(CCMoveTo::create(0.8, ccp(this->mBottomLayer->getPosition().x, this->mBottomLayer->getPosition().y + Utils::coord(200))));

	SimpleAudioEngine::sharedEngine()->playEffect("Sound/game-start.ogg");
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
	((Entity*) this->mLifes->objectAtIndex(LIFES))->setCurrentFrameIndex(1);

	((Entity*) this->mLifes->objectAtIndex(LIFES))->setScale(1.3);
	((Entity*) this->mLifes->objectAtIndex(LIFES))->runAction(CCScaleTo::create(0.3, 1));

	//LIFES++;

	if(LIFES == 3)
	{
		this->mFruits->pauseSchedulerAndActions();
		this->mParts->pauseSchedulerAndActions();
		this->mSplashes->pauseSchedulerAndActions();

		this->mIsGameRunning = false;

		SimpleAudioEngine::sharedEngine()->playEffect("Sound/game-over.ogg");
	}
}

void Menu::runSpecialChalenge()
{
	if(this->mIsSpecialChalengeRunning)
	{
		this->mSpecialChalengeTime = 1000.0;

		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/combo-blitz-backing-light.ogg", true);
	}
	else
	{
		this->mIsSpecialChalengeRunning = true;

		this->mSpecialChalengeTime = 3.0;

		SimpleAudioEngine::sharedEngine()->playEffect("Sound/combo-blitz-backing.ogg");
	}
}

void Menu::stopSpecialChalenge()
{
	this->mIsSpecialChalengeRunning = false;

	this->mSpecialChalengeTime = 60.0;
	this->mSpecialChalengeTimeElapsed = 0;

	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Music/nature_bgm.mp3", true);
	
	SimpleAudioEngine::sharedEngine()->playEffect("Sound/combo-blitz-backing-end.ogg");
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

		if(this->mTimeBeforeRestartElapsed >= 7.0)
		{
			this->startGame();
		}

		return;
	}
	
	if(this->mIsSpecialChalengeRunning)
	{
		this->mFruitTimeElapsed += pDeltaTime;

		if(this->mFruitTimeElapsed >= 0.3)
		{
			this->mFruitTimeElapsed = 0;

			((Fruit*) this->mFruits->create())->setSpecialChalenge();

			this->mFruitRemaning++;

			SimpleAudioEngine::sharedEngine()->playEffect("Sound/toss_simultaneous.mp3");

			if(this->mFruitRemaning >= 100)
			{
				this->stopSpecialChalenge();
			}
		}
	}
	else
	{
		this->mFruitTimeElapsed += pDeltaTime;

		if(this->mFruitTimeElapsed >= this->mFruitTime)
		{
			this->mFruitTimeElapsed = 0;

			if(this->mFruitRemaning == 0)
			{
				this->mFruitRemaning = Utils::random(1, 6);
			}

			this->mFruitTime = Utils::randomf(0.0, 1.5);

			this->mFruits->create();

			SimpleAudioEngine::sharedEngine()->playEffect("Sound/toss_simultaneous.mp3");

			this->mFruitRemaning--;

			if(this->mFruitRemaning == 0)
			{
				this->mFruitTime = Utils::randomf(2.0, 7.0);
			}
		}
	}

	if(Menu::SPECIAL_FRUIT != NULL)
	{
		this->mSpecialLabel->setPosition(ccp(Menu::SPECIAL_FRUIT->getCenterX() + (Menu::SPECIAL_FRUIT->getCenterX() < (Options::CAMERA_HEIGHT - Utils::coord(250)) ? Utils::coord(250) : -Utils::coord(250)), Menu::SPECIAL_FRUIT->getCenterY()));
		this->mSpecialLabelScore->setPosition(ccp(this->mSpecialLabel->getPosition().x, this->mSpecialLabel->getPosition().y - Utils::coord(50)));
	}

	// Special Chalenge

	this->mSpecialChalengeTimeElapsed += pDeltaTime;

	if(this->mSpecialChalengeTimeElapsed >= this->mSpecialChalengeTime)
	{
		this->mSpecialChalengeTimeElapsed = 0;

		this->runSpecialChalenge();
	}

	// Debug Information

	if(this->mDebugInformationNeed)
	{
		this->mDebugUpdateTimeElapsed += pDeltaTime;

		if(this->mDebugUpdateTimeElapsed >= this->mDebugUpdateTime)
		{
			this->mDebugUpdateTimeElapsed = 0;

			char text[256];
			sprintf(text, "%f", CCDirector::sharedDirector()->getAnimationInterval() * 60.0 * 60.0);
			this->mDebugInformation[2]->setString(text);
			sprintf(text, "%d / %d", this->mFruits->getCount(), this->mFruits->getCapacity());
			this->mDebugInformation[4]->setString(text);
			sprintf(text, "%d / %d", this->mParts->getCount(), this->mParts->getCapacity());
			this->mDebugInformation[6]->setString(text);
			sprintf(text, "%d / %d", this->mSparks->getCount(), this->mSparks->getCapacity());
			this->mDebugInformation[8]->setString(text);
			sprintf(text, "%d / %d", this->mSplashes->getCount(), this->mSplashes->getCapacity());
			this->mDebugInformation[10]->setString(text);

			this->mDebugInformation[2]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[2]->getContentSize().width / 2, Utils::coord(270)));
			this->mDebugInformation[4]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[4]->getContentSize().width / 2, Utils::coord(240)));
			this->mDebugInformation[6]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[6]->getContentSize().width / 2, Utils::coord(210)));
			this->mDebugInformation[8]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[8]->getContentSize().width / 2, Utils::coord(180)));
			this->mDebugInformation[10]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[10]->getContentSize().width / 2, Utils::coord(150)));
		}
	}
}

void Menu::onEnter()
{
	Screen::onEnter();
}

#endif