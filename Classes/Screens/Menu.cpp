#ifndef CONST_MENU
#define CONST_MENU

#include "Menu.h"

#include "TouchTrailLayer.h"

// ===========================================================
// Inner Classes
// ===========================================================

class SoundButton : public Entity
{
    public:
    SoundButton(CCNode* pParent) :
        Entity("main_menu_btn_sfx.png", 2, 2, pParent)
        {
            this->create()->setCurrentFrameIndex(0);
            this->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(200), Options::CAMERA_HEIGHT - Utils::coord(64));
            this->setRegisterAsTouchable(true);
        }
    
        void onTouch(CCTouch* touch, CCEvent* event)
        {
            if(Options::SOUND_ENABLE)
            {
                this->setCurrentFrameIndex(2);
            }
            else
            {
                this->setCurrentFrameIndex(0);
            }
            
            Options::SOUND_ENABLE = !Options::SOUND_ENABLE;
        }
    
        void onEnter()
        {
            CCDirector* pDirector = CCDirector::sharedDirector();
            pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
            Entity::onEnter();
        }
};

class MusicButton : public Entity
{
    public:
    MusicButton(CCNode* pParent) :
        Entity("main_menu_btn_sfx.png", 2, 2, pParent)
        {
            this->create()->setCurrentFrameIndex(1);
            this->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Options::CAMERA_HEIGHT -  Utils::coord(64));
            this->setRegisterAsTouchable(true);
        }
    
        void onTouch(CCTouch* touch, CCEvent* event)
        {
            if(Options::MUSIC_ENABLE)
            {
                this->setCurrentFrameIndex(3);
            }
            else
            {
                this->setCurrentFrameIndex(1);
            }
        
            Options::MUSIC_ENABLE = !Options::MUSIC_ENABLE;
        }
    
        void onEnter()
        {
            CCDirector* pDirector = CCDirector::sharedDirector();
            pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
            Entity::onEnter();
        }
};

class PauseSoundButton : public Entity
{
    public:
    PauseSoundButton(CCNode* pParent) :
    Entity("main_menu_btn_sfx.png", 2, 2, pParent)
    {
        this->create()->setCurrentFrameIndex(0);
        this->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(50), Options::CAMERA_CENTER_Y - Utils::coord(200));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        if(Options::SOUND_ENABLE)
        {
            this->setCurrentFrameIndex(2);
        }
        else
        {
            this->setCurrentFrameIndex(0);
        }
        
        Options::SOUND_ENABLE = !Options::SOUND_ENABLE;
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

class PauseMusicButton : public Entity
{
    public:
    PauseMusicButton(CCNode* pParent) :
    Entity("main_menu_btn_sfx.png", 2, 2, pParent)
    {
        this->create()->setCurrentFrameIndex(1);
        this->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(50), Options::CAMERA_CENTER_Y - Utils::coord(200));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        if(Options::MUSIC_ENABLE)
        {
            this->setCurrentFrameIndex(3);
        }
        else
        {
            this->setCurrentFrameIndex(1);
        }
        
        Options::MUSIC_ENABLE = !Options::MUSIC_ENABLE;
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

class TwitterButton : public Entity
{
    public:
    TwitterButton(CCNode* pParent) :
    Entity("main_menu_social.png", 2, 1)
    {
        this->setAnchorPoint(ccp(-7.0, 0.5));
        this->create()->setCurrentFrameIndex(0);
        this->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(260) - Utils::coord(1500), Utils::coord(64));
        this->setRegisterAsTouchable(true);
        
        pParent->addChild(this, 21);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

class FacebookButton : public Entity
{
    public:
    FacebookButton(CCNode* pParent) :
    Entity("main_menu_social.png", 2, 1)
    {
        this->setAnchorPoint(ccp(-7.0, 0.5));
        this->create()->setCurrentFrameIndex(1);
        this->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100) - Utils::coord(1500), Utils::coord(64));
        this->setRegisterAsTouchable(true);
        
        pParent->addChild(this, 21);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

class PauseButton : public Entity
{
    public:
    PauseButton(CCNode* pParent) :
    Entity("pause_btn.png", pParent)
    {
        this->create()->setCenterPosition(Utils::coord(32), Utils::coord(32));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        Menu* menu = (Menu*) this->getParent()->getParent();
        
        menu->switchPause();
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

class RestartButton : public Entity
{
    public:
    RestartButton(CCNode* pParent) :
    Entity("pause_buttons.png", 1, 2, pParent)
    {
        this->setCurrentFrameIndex(1);
        this->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(128), Options::CAMERA_CENTER_Y);
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        Menu* menu = (Menu*) this->getParent()->getParent();
        
        menu->startGame();
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

class ContinueButton : public Entity
{
    public:
    ContinueButton(CCNode* pParent) :
    Entity("pause_buttons.png", 1, 2, pParent)
    {
        this->setCurrentFrameIndex(0);
        this->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(100), Options::CAMERA_CENTER_Y);
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        Menu* menu = (Menu*) this->getParent()->getParent();
        
        menu->switchPause();
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

// ===========================================================
// Constants
// ===========================================================

int Menu::FRUITS = 0;
int Menu::SCORE = 0;
int Menu::LIFES = 0;

int Menu::APPEND_STATUS = APPEND_STATUS_MAIN_MENU;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Menu::Menu()
{this->mScreenSwitched = false;
    this->mParticlesTypeDanger = CCParticleSystemQuad::create("explosion.plist");
    this->mParticlesTypeDanger->stopSystem();
    
	TouchTrailLayer* p = TouchTrailLayer::create();
    
	this->addChild(p, 100);

	/** Main menu layer **/
	this->mMainMenuLayer = CCLayer::create();
    
    this->mMenuDecorations[0] = new Entity("main_menu_gui_black_up.png", this->mMainMenuLayer);
    this->mMenuDecorations[0]->create()->setCenterPosition(this->mMenuDecorations[0]->getWidth() / 2, Options::CAMERA_HEIGHT - this->mMenuDecorations[0]->getHeight() / 2);
    this->mMenuDecorations[1] = new Entity("main_menu_label_name_fruit.png", this->mMainMenuLayer);
    this->mMenuDecorations[1]->create()->setCenterPosition(Utils::coord(300), Options::CAMERA_HEIGHT - Utils::coord(128));
    this->mMenuDecorations[2] = new Entity("main_menu_label_name_mania.png", this->mMainMenuLayer);
    this->mMenuDecorations[2]->create()->setCenterPosition(Utils::coord(800), Options::CAMERA_HEIGHT - Utils::coord(64));
    this->mMenuDecorations[3] = new Entity("main_menu_ninja.png", this->mMainMenuLayer);
    this->mMenuDecorations[3]->create()->setCenterPosition(Utils::coord(200), Utils::coord(220));
    
    this->mCirclesFruits = new BatchEntityManager(4, new CircleFruit(), NULL);
    this->mCirclesParts = new BatchEntityManager(4, new CirclePart(), NULL);
    this->mCirclesManager = new BatchEntityManager(4, new Circle(this->mCirclesFruits), NULL);
    this->mCirclesDropsManager = new DropsManager(20, new Drop(), NULL);
    this->mCirclesCutters = new BatchEntityManager(2, new Cutter(false), NULL);
    this->mCirclesSplashes = new BatchEntityManager(2, new Splash(), NULL);
    
    this->mMainMenuLayer->addChild(this->mCirclesFruits, 17);
    this->mMainMenuLayer->addChild(this->mCirclesParts, 17);
    this->mMainMenuLayer->addChild(this->mCirclesDropsManager, 17);
    this->mMainMenuLayer->addChild(this->mCirclesCutters, 17);
    this->mMainMenuLayer->addChild(this->mCirclesSplashes, 15);
    this->mMainMenuLayer->addChild(this->mCirclesManager, 16);
    
    this->mCircles[0] = (Circle*) this->mCirclesManager->create();
    this->mCircles[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mCircles[0]->create()->setCurrentFrameIndex(0);
    this->mCircles[0]->setScaleX(0.0);
    this->mCircles[0]->destroy(false);
    
    this->mCircles[1] = (Circle*) this->mCirclesManager->create();
    this->mCircles[1]->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(250), Options::CAMERA_CENTER_Y - Utils::coord(100));
    this->mCircles[1]->create()->setCurrentFrameIndex(11);
    this->mCircles[1]->setScaleX(0.0);
    this->mCircles[1]->destroy(false);
    
    this->mCircles[2] = (Circle*) this->mCirclesManager->create();
    this->mCircles[2]->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(350), Options::CAMERA_CENTER_Y + Utils::coord(100));
    this->mCircles[2]->create()->setCurrentFrameIndex(2);
    this->mCircles[2]->setScaleX(0.0);
    this->mCircles[2]->destroy(false);
    
    this->mCircles[3] = (Circle*) this->mCirclesManager->create();
    this->mCircles[3]->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(250), Options::CAMERA_CENTER_Y - Utils::coord(100));
    this->mCircles[3]->create()->setCurrentFrameIndex(1);
    this->mCircles[3]->setScaleX(0.0);
    this->mCircles[3]->destroy(false);

    this->mSoundButton = new SoundButton(this->mMainMenuLayer);
    this->mMusicButton = new MusicButton(this->mMainMenuLayer);
    this->mTwitterButton = new TwitterButton(this->mMainMenuLayer);
    this->mFacebookButton = new FacebookButton(this->mMainMenuLayer);
    
    /** Extras layer **/
    this->mExtrasLayer = CCLayer::create();
    
    Entity* n = new Entity("extras_black_down.png", this->mExtrasLayer);
    n->setAnchorPoint(ccp(0.0, 0.0));
    n->create()->setPosition(Options::CAMERA_WIDTH - n->getWidth() / 2, -n->getHeight() / 2);
    n->setRotation(45.0);
    
    this->mCircles[4] = (Circle*) this->mCirclesManager->create();
    this->mCircles[4]->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(100));
    this->mCircles[4]->setCurrentFrameIndex(10);
    this->mCircles[4]->setScaleX(0.0);
    this->mCircles[4]->destroy(false);
    
    this->mCircles[5] = (Circle*) this->mCirclesManager->create();
    this->mCircles[5]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mCircles[5]->setCurrentFrameIndex(9);
    this->mCircles[5]->setScaleX(0.0);
    this->mCircles[5]->destroy(false);
    
    /** Mode layer **/
    this->mModeLayer = CCLayer::create();
    
    this->mCircles[6] = (Circle*) this->mCirclesManager->create();
    this->mCircles[6]->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(50), Options::CAMERA_CENTER_Y);
    this->mCircles[6]->setCurrentFrameIndex(5);
    this->mCircles[6]->setScaleX(0.0);
    this->mCircles[6]->destroy(false);
    
    this->mCircles[7] = (Circle*) this->mCirclesManager->create();
    this->mCircles[7]->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(250), Options::CAMERA_CENTER_Y - Utils::coord(100));
    this->mCircles[7]->setCurrentFrameIndex(6);
    this->mCircles[7]->setScaleX(0.0);
    this->mCircles[7]->destroy(false);
    
    this->mCircles[8] = (Circle*) this->mCirclesManager->create();
    this->mCircles[8]->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(350), Options::CAMERA_CENTER_Y + Utils::coord(100));
    this->mCircles[8]->setCurrentFrameIndex(7);
    this->mCircles[8]->setScaleX(0.0);
    this->mCircles[8]->destroy(false);
    
    this->mCircles[9] = (Circle*) this->mCirclesManager->create();
    this->mCircles[9]->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(100));
    this->mCircles[9]->setCurrentFrameIndex(10);
    this->mCircles[9]->setScaleX(0.0);
    this->mCircles[9]->destroy(false);
    
    n = new Entity("choose_mode_bg_down.png");
    n->setAnchorPoint(ccp(0.0, 0.0));
    n->create()->setPosition(Options::CAMERA_WIDTH - n->getWidth() / 2, -n->getHeight() / 2);
    n->setRotation(45.0);
    
    this->mModeLayer->addChild(n, 7);
    
    /** Pause layer **/
    this->mPauseLayer = CCLayer::create();
    this->mPauseLayer->setVisible(false);
    
    this->mRestartButton = new RestartButton(this->mPauseLayer);
    this->mContinueButton = new ContinueButton(this->mPauseLayer);
    
    this->mPauseSoundButton = new PauseSoundButton(this->mPauseLayer);
    this->mPauseMusicButton = new PauseMusicButton(this->mPauseLayer);
    
    Entity* y = new Entity("shop_bg_up.png", this->mPauseLayer);
    y->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - y->getHeight() / 2);
    
    Entity* i = new Entity("pause_label.png", y);
    i->create()->setCenterPosition(i->getWidth() / 2, y->getHeight() / 2);
    
    (new Entity("shop_bg_name.png", y))->create()->setCenterPosition(y->getWidth() / 2, y->getHeight() / 2);
    (new Entity("shop_carambols_icon.png", y))->create()->setCenterPosition(0, 0);
    
    (new Entity("shop_bg_scram.png", y))->create()->setCenterPosition(i->getCenterX() - i->getWidth() / 2 - Utils::coord(25), y->getHeight() / 2);
    (new Entity("shop_bg_scram.png", y))->create()->setCenterPosition(i->getCenterX() + i->getWidth() / 2 + Utils::coord(25), y->getHeight() / 2);

	/** Top layer **/
	this->mTopLayer = CCLayer::create();
	this->mTopLayer->setPosition(ccp(this->mTopLayer->getPosition().x, this->mTopLayer->getPosition().y + Utils::coord(200)));

    /** Bottom Layer */
	this->mBottomLayer = CCLayer::create();
	this->mBottomLayer->setPosition(ccp(this->mBottomLayer->getPosition().x, this->mBottomLayer->getPosition().y - Utils::coord(200)));
    
    /** Fruits Layer */
    this->mFruitsLayer = CCLayer::create();
    
    /** */
	this->mBackground = new Entity("background3.png", this->mFruitsLayer);
    
	this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
	this->addChild(this->mFruitsLayer);
	this->addChild(this->mMainMenuLayer, 0);
	this->addChild(this->mTopLayer);
	this->addChild(this->mBottomLayer);
	this->addChild(this->mPauseLayer);
    this->mMainMenuLayer->addChild(this->mExtrasLayer, 0);
    this->mMainMenuLayer->addChild(this->mModeLayer, 0);
    
    this->mPauseButton = new PauseButton(this->mBottomLayer);
    
	this->mAwCutters = new BatchEntityManager(3, new Cutter(true), this->mFruitsLayer);
    this->mMarks = new BatchEntityManager(20, new Mark(), this->mFruitsLayer);
	this->mShadows = new BatchEntityManager(20, new Entity("shadow.png"), this->mFruitsLayer);
	this->mWaves = new BatchEntityManager(5, new Wave(), this->mFruitsLayer);
	this->mSplashes = new BatchEntityManager(20, new Splash(), this->mFruitsLayer);
	this->mFruits = new BatchEntityManager(20, new Fruit(), this->mFruitsLayer);
	this->mParts = new BatchEntityManager(20, new Part(), this->mFruitsLayer);
	this->mCriticalHits = new BatchEntityManager(5, new Label("critical.png", 1, 1), this->mFruitsLayer);
	this->mSparks = new BatchEntityManager(200, new Spark(), this->mFruitsLayer);
	this->mCutters = new BatchEntityManager(20, new Cutter(false), this->mFruitsLayer);
	this->mDropsManager = new DropsManager(100, new Drop(), this->mFruitsLayer);
	this->mParticles = new BatchEntityManager(10, new Particles(), this->mFruitsLayer);
    
    this->mEffect[1] = new Entity("effect.png");
    this->mEffect[1]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mFruitsLayer->addChild(this->mEffect[1], 0);
    
    this->mEffect[0] = new Entity("effect.png");
    this->mEffect[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mFruitsLayer->addChild(this->mEffect[0], 100);

	this->addChild(this->mParticlesTypeDanger, 100);
    
    this->mAwesomeLights = new Entity("splash-granat.png");
    this->mFruitsLayer->addChild(this->mAwesomeLights, 0);

	this->mFruitTime = 5.0;
	this->mFruitTimeElapsed = 0;

	this->mSpecialChalengeTime = 60.0;
	this->mSpecialChalengeTimeElapsed = 0;
    
	this->mTimeBeforeRestartElapsed = 0;
    
	this->mAwesomeFruitTime = Utils::randomf(15.0f, 150.0f);
	this->mAwesomeFruitTimeElapsed = 0;

	this->mFruitRemaning = 0;
    
    this->mShaking = false;
    this->mSlide = false;

	this->mFruitsSlashed = CCLabelTTF::create("0", Options::FONT, Utils::coord(64));
	this->mFruitsSlashed->setPosition(ccp(Utils::coord(90) + mFruitsSlashed->getContentSize().width / 2, Options::CAMERA_HEIGHT - Utils::coord(48)));

	this->mBestFruitsSlashed = CCLabelTTF::create("Best: 0", Options::FONT, Utils::coord(32));
	this->mBestFruitsSlashed->setPosition(ccp(Utils::coord(25) + mBestFruitsSlashed->getContentSize().width / 2, Options::CAMERA_HEIGHT - Utils::coord(100)));

	this->mTopLayer->addChild(this->mFruitsSlashed, 101);
	this->mTopLayer->addChild(this->mBestFruitsSlashed, 101);

	this->mCounter = new Entity("counter.png", this->mTopLayer);
	this->mCounter->create()->setCenterPosition(Utils::coord(48), Options::CAMERA_HEIGHT - Utils::coord(48));

	this->mLifes = new BatchEntityManager(3, new Heart(), this->mTopLayer);

	this->mLifes->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(176), Options::CAMERA_HEIGHT - Utils::coord(36));
	this->mLifes->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(128), Options::CAMERA_HEIGHT - Utils::coord(48));
	this->mLifes->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(64));
    
    ((Entity*) this->mLifes->objectAtIndex(0))->setScale(0.5);
    ((Entity*) this->mLifes->objectAtIndex(1))->setScale(0.75);

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic(Options::GAME_MUSIC, true);

	this->mIsGameRunning = false;

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
		this->mDebugInformation[19] = CCLabelTTF::create("Aw cutters: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[20] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));
		this->mDebugInformation[21] = CCLabelTTF::create("Current fps: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[22] = CCLabelTTF::create("0.0000", Options::FONT, Utils::coord(16));
		this->mDebugInformation[23] = CCLabelTTF::create("Average fps: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[24] = CCLabelTTF::create("0.0000", Options::FONT, Utils::coord(16));
		this->mDebugInformation[25] = CCLabelTTF::create("Unix time: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[26] = CCLabelTTF::create("0.00000", Options::FONT, Utils::coord(16));
		this->mDebugInformation[27] = CCLabelTTF::create("Drops: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[28] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));
		this->mDebugInformation[29] = CCLabelTTF::create("Particles: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[30] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));
		this->mDebugInformation[31] = CCLabelTTF::create("Resolution: ", Options::FONT, Utils::coord(16));
		this->mDebugInformation[32] = CCLabelTTF::create("0 / 0 / 0", Options::FONT, Utils::coord(16));

		for(int i = 0; i < 33; i++)
		{
			this->addChild(this->mDebugInformation[i], 555);
		}

		this->mDebugInformation[0]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[0]->getContentSize().width / 2, Utils::coord(630)));
		this->mDebugInformation[1]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[1]->getContentSize().width / 2, Utils::coord(460)));
		this->mDebugInformation[2]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[2]->getContentSize().width / 2, Utils::coord(460)));
		this->mDebugInformation[3]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[3]->getContentSize().width / 2, Utils::coord(430)));
		this->mDebugInformation[4]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[4]->getContentSize().width / 2, Utils::coord(430)));
		this->mDebugInformation[5]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[5]->getContentSize().width / 2, Utils::coord(400)));
		this->mDebugInformation[6]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[6]->getContentSize().width / 2, Utils::coord(400)));
		this->mDebugInformation[7]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[7]->getContentSize().width / 2, Utils::coord(370)));
		this->mDebugInformation[8]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[8]->getContentSize().width / 2, Utils::coord(370)));
		this->mDebugInformation[9]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[9]->getContentSize().width / 2, Utils::coord(340)));
		this->mDebugInformation[10]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[10]->getContentSize().width / 2, Utils::coord(340)));
		this->mDebugInformation[11]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[11]->getContentSize().width / 2, Utils::coord(310)));
		this->mDebugInformation[12]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[12]->getContentSize().width / 2, Utils::coord(310)));
		this->mDebugInformation[13]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[13]->getContentSize().width / 2, Utils::coord(280)));
		this->mDebugInformation[14]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[14]->getContentSize().width / 2, Utils::coord(280)));
		this->mDebugInformation[15]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[15]->getContentSize().width / 2, Utils::coord(250)));
		this->mDebugInformation[16]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[16]->getContentSize().width / 2, Utils::coord(250)));
		this->mDebugInformation[17]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[17]->getContentSize().width / 2, Utils::coord(220)));
		this->mDebugInformation[18]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[18]->getContentSize().width / 2, Utils::coord(220)));
		this->mDebugInformation[19]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[19]->getContentSize().width / 2, Utils::coord(190)));
		this->mDebugInformation[20]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[20]->getContentSize().width / 2, Utils::coord(190)));
		this->mDebugInformation[21]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[21]->getContentSize().width / 2, Utils::coord(490)));
		this->mDebugInformation[22]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[22]->getContentSize().width / 2, Utils::coord(490)));
		this->mDebugInformation[23]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[23]->getContentSize().width / 2, Utils::coord(520)));
		this->mDebugInformation[24]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[24]->getContentSize().width / 2, Utils::coord(520)));
		this->mDebugInformation[25]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[25]->getContentSize().width / 2, Utils::coord(550)));
		this->mDebugInformation[26]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[26]->getContentSize().width / 2, Utils::coord(550)));
		this->mDebugInformation[27]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[27]->getContentSize().width / 2, Utils::coord(160)));
		this->mDebugInformation[28]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[28]->getContentSize().width / 2, Utils::coord(160)));
		this->mDebugInformation[29]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[29]->getContentSize().width / 2, Utils::coord(130)));
		this->mDebugInformation[30]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[30]->getContentSize().width / 2, Utils::coord(130)));
		this->mDebugInformation[31]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(320) + this->mDebugInformation[31]->getContentSize().width / 2, Utils::coord(580)));
		this->mDebugInformation[32]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[32]->getContentSize().width / 2, Utils::coord(580)));
        
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
    
	this->mAwesomeFruitTime = Utils::randomf(15.0f, 150.0f);
	this->mAwesomeFruitTimeElapsed = 0;

	this->mIsSpecialChalengeRunning = false;
    this->mIsAwesomeChalengeRunning = false;
    
    this->mShaking = false;
    this->mSlide = false;
    
    Processor::SPECIAL_FRUIT = NULL;
    Processor::AWESOME_FRUIT = NULL;

	this->updateCounter();

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
        
        this->mTopLayer->runAction(CCMoveTo::create(0.8, ccp(this->mTopLayer->getPosition().x, Options::CAMERA_HEIGHT - Utils::coord(200))));
        this->mBottomLayer->runAction(CCMoveTo::create(0.8, ccp(this->mBottomLayer->getPosition().x, 0 - Utils::coord(200))));
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

		this->mSpecialChalengeTime = 2.7;

		SimpleAudioEngine::sharedEngine()->playEffect(Options::COMBO_BLITZ_BACKING);
	}
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

void Menu::runAwesomeChalenge()
{
    ((Fruit*) this->mFruits->create())->setAwesomeChalenge();
    
    this->mIsAwesomeChalengeRunning = true;
}

void Menu::hitedAwesome()
{
    this->randomSlide();
    
    this->mEffect[0]->create()->setOpacity(100.0);
    this->mEffect[0]->setColor(ccc3(255.0, 255.0, 255.0));
    this->mEffect[0]->runAction(CCFadeTo::create(Options::EFFECT_WHITE_APPEAR_TIME, 0.0));
    
    this->mAwesomeLights->setScale(this->mAwesomeLights->getScaleX() + 0.05);
    
    if(this->mFruitsLayer->getScaleX() != 1.0) return;
    if(Processor::AWESOME_FRUIT == NULL) return;
    
    this->mAwesomeFruitTimeElapsed = 0;
    this->mAwesomeFruitTime = 3.0;
    
    this->mAwesomeLights->create()->setCenterPosition(Processor::AWESOME_FRUIT->getCenterX(), Processor::AWESOME_FRUIT->getCenterY());
    this->mAwesomeLights->setScale(0.0);
    
    this->mEffect[1]->create()->setOpacity(0.0);
    this->mEffect[1]->setColor(ccc3(0.0, 0.0, 0.0));
    this->mEffect[1]->runAction(CCFadeTo::create(Options::EFFECT_BLACK_APPEAR_TIME, 220.0));
    
    this->mFruitsLayer->setAnchorPoint(ccp(Processor::AWESOME_FRUIT->getCenterX() / Options::CAMERA_WIDTH, Processor::AWESOME_FRUIT->getCenterY() / Options::CAMERA_HEIGHT));
    
    this->mFruitsLayer->runAction(CCScaleTo::create(Options::AWESOME_SCALE_APPEAR_TIME, Options::AWESOME_SCALE_APPEAR));
    this->mFruitsLayer->runAction(CCRotateTo::create(Options::AWESOME_ROTATE_APPEAR_TIME, Utils::randomf(-Options::AWESOME_ROTATE_APPEAR, Options::AWESOME_ROTATE_APPEAR)));
    
    this->mFruitsLayer->runAction(CCFollow::create(Processor::AWESOME_FRUIT, CCRectMake(-Utils::coord(184), -Utils::coord(152), Utils::coord(1280) + Utils::coord(368), Utils::coord(720) + Utils::coord(304))));
    
    Processor::FREEZY_TIME = 0.05;
}

void Menu::hitedAwesomeLast()
{
    this->mFruitsLayer->stopAllActions();
    this->mFruitsLayer->setAnchorPoint(ccp(0.5, 0.5));
    this->mFruitsLayer->runAction(CCScaleTo::create(0.2, 1.0));
    
    SimpleAudioEngine::sharedEngine()->playEffect(Options::BONUS_BLOW);
}

void Menu::switchPause()
{
    this->mPauseLayer->setVisible(!this->mPauseLayer->isVisible());
    
    this->mIsGameRunning = !this->mPauseLayer->isVisible(); // TODO: ?
    
    if(this->mPauseLayer->isVisible())
    {
        this->mFruits->pauseSchedulerAndActions();
        this->mParts->pauseSchedulerAndActions();
        this->mMarks->pauseSchedulerAndActions();
        this->mDropsManager->pauseSchedulerAndActions();
        this->mSplashes->pauseSchedulerAndActions();
    }
    else
    {
        this->mFruits->resumeSchedulerAndActions();
        this->mParts->resumeSchedulerAndActions();
        this->mMarks->resumeSchedulerAndActions();
        this->mDropsManager->resumeSchedulerAndActions();
        this->mSplashes->resumeSchedulerAndActions();
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Menu::update(float pDeltaTime)
{
	Screen::update(pDeltaTime);
    
    if(!this->mScreenSwitched)
    {
        int c = 0;
        
        for(int i = 0; i < this->mCirclesFruits->getCount(); i++)
        {
           if(((Entity*) this->mCirclesFruits->objectAtIndex(i))->isVisible())
           {
               c++;
           }
        }
        
        if(c <= 0)
        {
            this->mScreenSwitched = true;
            
            this->switchScreen();
        }
    }
    
    if(APPEND_STATUS == APPEND_STATUS_MAIN_MENU)
    {
        bool check = true;
        
        for(int i = 0; i < 4; i++)
        {
            if(!check) return;
            
            CircleFruit* fruit = (CircleFruit*) this->mCircles[i]->mFruit;
            
            bool collides = false;
            
            for(int i = 0; i < 10; i++)
            {
                if(fruit->isCollideWithPoint(Processor::TOUCH_INFORMATION[i].position.x, Processor::TOUCH_INFORMATION[i].position.y) && Processor::TOUCH_INFORMATION[i].slice)
                {
                    collides = true;
                    
                    Processor::TOUCH_INFORMATION[i].slice = false;
                }
            }
            
            if(collides)
            {
                switch(fruit->getCurrentFrameIndex())
                {
                    case Options::TYPE_ORANGE:
                        APPEND_STATUS = APPEND_STATUS_EXTRAS;
                        break;
                    case Options::TYPE_COCONUT:
                        APPEND_STATUS = APPEND_STATUS_MODE;
                        break;
                }
                
                if(fruit->getCurrentFrameIndex() == Options::TYPE_DANGER)
                {
                    this->mParticlesTypeDanger->setPosition(fruit->getCenterX(), fruit->getCenterY());
                    this->mParticlesTypeDanger->resetSystem();
                    
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::EXPLOSION);
                }
                else
                {
                    this->mCirclesDropsManager->init(fruit->getCenterX(), fruit->getCenterY(), fruit->getCurrentFrameIndex());
                    
                    Splash* splash = (Splash*) this->mCirclesSplashes->create();
                    splash->setCenterPosition(fruit->getCenterX(), fruit->getCenterY());
                    splash->setColor(Fruit::FRUITS_COLORS[fruit->getCurrentFrameIndex()]);
                    
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                }
                
                for(int j = 0; j < 4; j++)
                {
                    ((Circle*) this->mCirclesManager->objectAtIndex(j))->free();
                }
                
                for(int i = 0; i < 2; i++)
                {
                    CirclePart* part = (CirclePart*) this->mCirclesParts->create();
                    
                    part->setCurrentFrameIndex(fruit->getCurrentFrameIndex() * 3 + Utils::random(1, 2));
                    part->setCenterPosition(fruit->getCenterX() + Utils::coord(Utils::randomf(-50.0, 50.0)), fruit->getCenterY() + Utils::coord(Utils::randomf(-50.0, 50.0)));
                    
                    part->mRotateImpulse = fruit->mRotateImpulse;
                    part->mImpulsePower = fruit->mImpulsePower;
                    part->mSideImpulse = (i == 0 ? fruit->mSideImpulse : -fruit->mSideImpulse) / 2;
                    part->mWeight = fruit->mWeight;
                    part->setScale(fruit->getScaleX());
                }
                
                fruit->destroy(false);
                
                check = false;
                
                this->mScreenSwitched = false;
                
                this->mSoundButton->runAction(CCMoveTo::create(0.3, ccp(Options::CAMERA_WIDTH - Utils::coord(200), Options::CAMERA_HEIGHT + Utils::coord(64))));
                this->mMusicButton->runAction(CCMoveTo::create(0.3, ccp(Options::CAMERA_WIDTH - Utils::coord(100), Options::CAMERA_HEIGHT + Utils::coord(64))));
            }
        }
    }
    else if(APPEND_STATUS == APPEND_STATUS_EXTRAS)
    {
        bool check = true;
        
        for(int i = 4; i < 7; i++)
        {
            if(!check) return;
            
            CircleFruit* fruit = (CircleFruit*) this->mCircles[i]->mFruit;
            
            bool collides = false;
            
            for(int a = 0; a < 10; a++)
            {
                if(fruit->isCollideWithPoint(Processor::TOUCH_INFORMATION[a].position.x, Processor::TOUCH_INFORMATION[a].position.y) && Processor::TOUCH_INFORMATION[a].slice)
                {
                    collides = true;
                    
                    Processor::TOUCH_INFORMATION[a].slice = false;
                }
            }
            
            if(collides)
            {
                switch(fruit->getCurrentFrameIndex())
                {
                    case Options::TYPE_DANGER:
                        APPEND_STATUS = APPEND_STATUS_MAIN_MENU;
                        break;
                    case Options::TYPE_COCONUT:
                        //APPEND_STATUS = APPEND_STATUS_GAME;
                        break;
                }
                
                fruit->destroy(false);
                
                if(fruit->getCurrentFrameIndex() == Options::TYPE_DANGER)
                {
                    this->mParticlesTypeDanger->setPosition(fruit->getCenterX(), fruit->getCenterY());
                    this->mParticlesTypeDanger->resetSystem();
                    
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::EXPLOSION);
                }
                else
                {
                    this->mCirclesDropsManager->init(fruit->getCenterX(), fruit->getCenterY(), fruit->getCurrentFrameIndex());
                    
                    Splash* splash = (Splash*) this->mCirclesSplashes->create();
                    splash->setCenterPosition(fruit->getCenterX(), fruit->getCenterY());
                    splash->setColor(Fruit::FRUITS_COLORS[fruit->getCurrentFrameIndex()]);
                    
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                }
                
                for(int j = 4; j < 6; j++)
                {
                    ((Circle*) this->mCirclesManager->objectAtIndex(j))->free();
                }
                
                for(int b = 0; b < 2; b++)
                {
                    CirclePart* part = (CirclePart*) this->mCirclesParts->create();
                    
                    part->setCurrentFrameIndex(fruit->getCurrentFrameIndex() * 3 + Utils::random(1, 2));
                    part->setCenterPosition(fruit->getCenterX() + Utils::coord(Utils::randomf(-50.0, 50.0)), fruit->getCenterY() + Utils::coord(Utils::randomf(-50.0, 50.0)));
                    
                    part->mRotateImpulse = fruit->mRotateImpulse;
                    part->mImpulsePower = fruit->mImpulsePower;
                    part->mSideImpulse = (i == 0 ? fruit->mSideImpulse : -fruit->mSideImpulse) / 2;
                    part->mWeight = fruit->mWeight;
                    part->setScale(fruit->getScaleX());
                }
                
                check = false;
                
                this->mScreenSwitched = false;
                
                
                ((Entity*) this->mExtrasLayer->getChildren()->objectAtIndex(0))->runAction(CCRotateTo::create(0.3, 45));
                this->mTwitterButton->runAction(CCRotateTo::create(0.2, 0));
                this->mFacebookButton->runAction(CCRotateTo::create(0.2, 0));
            }
        }
    }
    else if(APPEND_STATUS == APPEND_STATUS_MODE)
    {
        bool check = true;
        
        for(int i = 6; i < 10; i++)
        {
            if(!check) return;
            
            CircleFruit* fruit = (CircleFruit*) this->mCircles[i]->mFruit;
            
            bool collides = false;
            
            for(int a = 0; a < 10; a++)
            {
                if(fruit->isCollideWithPoint(Processor::TOUCH_INFORMATION[a].position.x, Processor::TOUCH_INFORMATION[a].position.y) && Processor::TOUCH_INFORMATION[a].slice)
                {
                    collides = true;
                    
                    Processor::TOUCH_INFORMATION[a].slice = false;
                }
            }
            
            if(collides)
            {
                switch(fruit->getCurrentFrameIndex())
                {
                    case Options::TYPE_DANGER:
                        APPEND_STATUS = APPEND_STATUS_MAIN_MENU;
                        break;
                    case Options::TYPE_COCONUT:
                        APPEND_STATUS = APPEND_STATUS_GAME;
                        break;
                }
                
                fruit->destroy(false);
                
                if(fruit->getCurrentFrameIndex() == Options::TYPE_DANGER)
                {
                    this->mParticlesTypeDanger->setPosition(fruit->getCenterX(), fruit->getCenterY());
                    this->mParticlesTypeDanger->resetSystem();
                    
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::EXPLOSION);
                }
                else
                {
                    this->mCirclesDropsManager->init(fruit->getCenterX(), fruit->getCenterY(), fruit->getCurrentFrameIndex());
                    
                    Splash* splash = (Splash*) this->mCirclesSplashes->create();
                    splash->setCenterPosition(fruit->getCenterX(), fruit->getCenterY());
                    splash->setColor(Fruit::FRUITS_COLORS[fruit->getCurrentFrameIndex()]);
                    
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                }
                
                for(int j = 6; j < 10; j++)
                {
                    ((Circle*) this->mCirclesManager->objectAtIndex(j))->free();
                }
                
                for(int b = 0; b < 2; b++)
                {
                    CirclePart* part = (CirclePart*) this->mCirclesParts->create();
                    
                    part->setCurrentFrameIndex(fruit->getCurrentFrameIndex() * 3 + Utils::random(1, 2));
                    part->setCenterPosition(fruit->getCenterX() + Utils::coord(Utils::randomf(-50.0, 50.0)), fruit->getCenterY() + Utils::coord(Utils::randomf(-50.0, 50.0)));
                    
                    part->mRotateImpulse = fruit->mRotateImpulse;
                    part->mImpulsePower = fruit->mImpulsePower;
                    part->mSideImpulse = (i == 0 ? fruit->mSideImpulse : -fruit->mSideImpulse) / 2;
                    part->mWeight = fruit->mWeight;
                    part->setScale(fruit->getScaleX());
                }
                
                check = false;
                
                this->mScreenSwitched = false;
                
                
                ((Entity*) this->mModeLayer->getChildren()->objectAtIndex(0))->runAction(CCRotateTo::create(0.3, 45));
                
                if(fruit->getCurrentFrameIndex() != Options::TYPE_DANGER)
                {
                    this->mMenuDecorations[0]->runAction(CCFadeTo::create(0.3, 0.0));
                    this->mMenuDecorations[1]->runAction(CCMoveTo::create(0.3, ccp(this->mMenuDecorations[1]->getPosition().x - Utils::coord(1000), this->mMenuDecorations[1]->getPosition().y)));
                    this->mMenuDecorations[2]->runAction(CCMoveTo::create(0.3, ccp(this->mMenuDecorations[2]->getPosition().x, this->mMenuDecorations[2]->getPosition().y + Utils::coord(1000))));
                    this->mMenuDecorations[3]->runAction(CCMoveTo::create(0.3, ccp(this->mMenuDecorations[3]->getPosition().x - Utils::coord(1000), this->mMenuDecorations[3]->getPosition().y)));
                }
            }
        }
    }
    else if(APPEND_STATUS == APPEND_STATUS_GAME)
    {
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
    			sprintf(text, "%d / %d / %d", this->mAwCutters->getCount(), this->mAwCutters->getCapacity(), this->mAwCutters->getInitCapacity());
    			this->mDebugInformation[20]->setString(text);
                if(this->mAwCutters->getCapacity() > this->mAwCutters->getInitCapacity()) this->mDebugInformation[20]->setColor(ccc3(255.0, 0.0, 0.0));
    			sprintf(text, "%d / %d / %d", this->mDropsManager->getCount(), this->mDropsManager->getCapacity(), this->mDropsManager->getInitCapacity());
    			this->mDebugInformation[28]->setString(text);
                if(this->mDropsManager->getCapacity() > this->mDropsManager->getInitCapacity()) this->mDebugInformation[28]->setColor(ccc3(255.0, 0.0, 0.0));
    			sprintf(text, "%d / %d / %d", this->mParticles->getCount(), this->mParticles->getCapacity(), this->mParticles->getInitCapacity());
    			this->mDebugInformation[30]->setString(text);
                if(this->mParticles->getCapacity() > this->mParticles->getInitCapacity()) this->mDebugInformation[30]->setColor(ccc3(255.0, 0.0, 0.0));
    			sprintf(text, "%f", fps);
    			this->mDebugInformation[22]->setString(text);
    			sprintf(text, "%f", this->mFpsSum / this->mFpsCount);
    			this->mDebugInformation[24]->setString(text);
    			sprintf(text, "%lu", Utils::millisecondNow());
    			this->mDebugInformation[26]->setString(text);
    			sprintf(text, "%d / %d / %d / %.02f''", Options::CAMERA_WIDTH, Options::CAMERA_HEIGHT, CCDevice::getDPI(), (sqrt(Options::CAMERA_WIDTH * Options::CAMERA_WIDTH + Options::CAMERA_HEIGHT * Options::CAMERA_HEIGHT) / CCDevice::getDPI()));
    			this->mDebugInformation[32]->setString(text);
                
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
                
    			this->mDebugInformation[2]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[2]->getContentSize().width / 2, Utils::coord(460)));
    			this->mDebugInformation[4]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[4]->getContentSize().width / 2, Utils::coord(430)));
    			this->mDebugInformation[6]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[6]->getContentSize().width / 2, Utils::coord(400)));
    			this->mDebugInformation[8]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[8]->getContentSize().width / 2, Utils::coord(370)));
    			this->mDebugInformation[10]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[10]->getContentSize().width / 2, Utils::coord(340)));
    			this->mDebugInformation[12]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[12]->getContentSize().width / 2, Utils::coord(310)));
    			this->mDebugInformation[14]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[14]->getContentSize().width / 2, Utils::coord(280)));
    			this->mDebugInformation[16]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[16]->getContentSize().width / 2, Utils::coord(250)));
    			this->mDebugInformation[18]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[18]->getContentSize().width / 2, Utils::coord(220)));
    			this->mDebugInformation[20]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[20]->getContentSize().width / 2, Utils::coord(190)));
    			this->mDebugInformation[22]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[22]->getContentSize().width / 2, Utils::coord(490)));
    			this->mDebugInformation[24]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[24]->getContentSize().width / 2, Utils::coord(520)));
    			this->mDebugInformation[26]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[26]->getContentSize().width / 2, Utils::coord(550)));
    			this->mDebugInformation[28]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[28]->getContentSize().width / 2, Utils::coord(160)));
    			this->mDebugInformation[30]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[30]->getContentSize().width / 2, Utils::coord(130)));
    			this->mDebugInformation[32]->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(200) + this->mDebugInformation[32]->getContentSize().width / 2, Utils::coord(580)));
    		}
    	}
    	
        if(!this->mIsGameRunning) return;
        
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
            if(Processor::AWESOME_FRUIT != NULL)
            {
                this->mAwesomeLights->setCenterPosition(Processor::AWESOME_FRUIT->getCenterX(), Processor::AWESOME_FRUIT->getCenterY());
            }
            
            if(this->mAwesomeFruitTimeElapsed >= this->mAwesomeFruitTime)
            {
                this->mAwesomeFruitTimeElapsed = 0;
                this->mAwesomeFruitTime = 1.0;
                
                this->mIsAwesomeChalengeRunning = false;
                
                Processor::AWESOME_FRUIT = NULL;
                
                this->mFruitsLayer->stopAllActions();
                
                this->mFruitsLayer->runAction(CCScaleTo::create(0.3, 1.0));
                this->mFruitsLayer->runAction(CCRotateTo::create(0.3, 0.0));
                
                this->mFruitsLayer->runAction(CCMoveTo::create(0.2, ccp(0, 0)));
                
                Processor::FREEZY_STATUS = Processor::FREEZY_STATUS_END_SCALING;
            }
        }
        else if(Processor::AWESOME_FRUIT == NULL)
        {
            if(this->mAwesomeFruitTimeElapsed >= this->mAwesomeFruitTime)
            {
                switch(Processor::FREEZY_STATUS)
                {
                    case Processor::FREEZY_STATUS_NONE:
                        this->mAwesomeFruitTimeElapsed = 0;
                        this->mAwesomeFruitTime = INT_MAX;
                        
                        this->runAwesomeChalenge();
                    break;
                    case Processor::FREEZY_STATUS_END_SCALING:
                        this->mAwesomeFruitTimeElapsed = 0;
                        this->mAwesomeFruitTime = 0.1;
                        
                        this->mEffect[0]->setOpacity(255.0);
                        this->mEffect[1]->setOpacity(0.0);
                        
                        Processor::FREEZY_STATUS = 2;
                    break;
                    case Processor::FREEZY_STATUS_START_BLOW:
                        this->mAwesomeFruitTimeElapsed = 0;
                        this->mAwesomeFruitTime = 1.0;
                        
                        this->mEffect[0]->runAction(CCFadeTo::create(0.5, 0.0));
                        
                        this->mAwesomeLights->destroy();
                        
                        this->shake(1.0, 5.0);
                        
                        Processor::FREEZY_STATUS = 3;
                    break;
                    case Processor::FREEZY_STATUS_RETURN_TIME:
                        this->mAwesomeFruitTimeElapsed = 0;
                        this->mAwesomeFruitTime = Utils::randomf(15.0, 300.0);
                        
                        Processor::FREEZY_STATUS = 0;
                        Processor::FREEZY_TIME = 1.0;
                    break;
                }
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
                
                if(Processor::AWESOME_FRUIT != NULL)
                {
                    /*Processor::AWESOME_FRUIT->runAction(CCMoveTo::create(0.2, ccp(Processor::AWESOME_FRUIT->getCenterX() + Utils::randomf(-50.0, 50.0), Processor::AWESOME_FRUIT->getCenterY() + Utils::randomf(-50.0, 50.0))));*/
                    
                    this->mFruitsLayer->runAction(CCFollow::create(Processor::AWESOME_FRUIT, CCRectMake(-Utils::coord(184), -Utils::coord(152), Utils::coord(1280) + Utils::coord(368), Utils::coord(720) + Utils::coord(304))));
                }
            }
        }
    }
}

void Menu::switchScreen()
{
    switch(APPEND_STATUS)
    {
        case APPEND_STATUS_MAIN_MENU:
            this->mCircles[0]->create()->runAction(CCScaleTo::create(0.3, 1.0));
            this->mCircles[1]->create()->runAction(CCScaleTo::create(0.3, 1.0));
            this->mCircles[2]->create()->runAction(CCScaleTo::create(0.3, 1.0));
            this->mCircles[3]->create()->runAction(CCScaleTo::create(0.3, 1.0));
            
            this->mSoundButton->runAction(CCMoveTo::create(0.3, ccp(Options::CAMERA_WIDTH - Utils::coord(200), Options::CAMERA_HEIGHT - Utils::coord(64))));
            this->mMusicButton->runAction(CCMoveTo::create(0.3, ccp(Options::CAMERA_WIDTH - Utils::coord(100), Options::CAMERA_HEIGHT - Utils::coord(64))));
            
            this->mTwitterButton->runAction(CCRotateTo::create(0.2, 0));
            this->mFacebookButton->runAction(CCRotateTo::create(0.2, 0));
            break;
        case APPEND_STATUS_EXTRAS:
            this->mCircles[4]->create()->runAction(CCScaleTo::create(0.2, 1.0));
            this->mCircles[5]->create()->runAction(CCScaleTo::create(0.2, 1.0));
            ((Entity*) this->mExtrasLayer->getChildren()->objectAtIndex(0))->runAction(CCRotateTo::create(0.3, 0));
            this->mTwitterButton->runAction(CCRotateTo::create(0.2, -6.5));
            this->mFacebookButton->runAction(CCRotateTo::create(0.2, -8.0));
            break;
        case APPEND_STATUS_MODE:
            this->mCircles[6]->create()->runAction(CCScaleTo::create(0.3, 1.0));
            this->mCircles[7]->create()->runAction(CCScaleTo::create(0.3, 1.0));
            this->mCircles[8]->create()->runAction(CCScaleTo::create(0.3, 1.0));
            this->mCircles[9]->create()->runAction(CCScaleTo::create(0.3, 1.0));
            ((Entity*) this->mModeLayer->getChildren()->objectAtIndex(0))->runAction(CCRotateTo::create(0.3, 0));
            this->mTwitterButton->runAction(CCRotateTo::create(0.2, 6.5));
            this->mFacebookButton->runAction(CCRotateTo::create(0.2, 8.0));
            break;
        case APPEND_STATUS_GAME:
            this->startGame();
            break;
    }
}

void Menu::randomSlide()
{
    if(this->mSlide) return;
    
    this->mFruitsLayer->stopAllActions();
        
    this->mSlide = true;
    
    this->mSlideOperations = -10;
    
    this->mSlideVectorX = Utils::randomf(-Options::EFFECT_SLIDE_VECTOR_X, Options::EFFECT_SLIDE_VECTOR_X);
    this->mSlideVectorY = Utils::randomf(-Options::EFFECT_SLIDE_VECTOR_Y, Options::EFFECT_SLIDE_VECTOR_Y);
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