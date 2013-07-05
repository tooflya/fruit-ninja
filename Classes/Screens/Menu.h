#ifndef CONST_MENU_H
#define CONST_MENU_H

#include "cocos2d.h"

#include "Screen.h"
#include "Fruit.h"
#include "Part.h"
#include "Splash.h"
#include "Label.h"
#include "BatchEntityManager.h"
#include "DropsManager.h"
#include "Processor.h"
#include "Spark.h"
#include "Drop.h"
#include "Mark.h"
#include "Cutter.h"
#include "Wave.h"
#include "Heart.h"
#include "Particles.h"
#include "Circle.h"
#include "CircleFruit.h"
#include "CirclePart.h"

class SoundButton;
class MusicButton;
class PauseSoundButton;
class PauseMusicButton;
class TwitterButton;
class FacebookButton;
class PauseButton;
class RestartButton;
class ContinueButton;

using namespace cocos2d;

class Menu : public Screen
{
	protected:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

		// ===========================================================
		// Fields
		// ===========================================================
    bool mScreenSwitched;
    void switchScreen();
		int mFruitRemaning;

		float mFruitTime;
        float mFruitTimeElapsed;
    
        float mAwesomeFruitTime;
        float mAwesomeFruitTimeElapsed;

		float mSpecialChalengeTime;
		float mSpecialChalengeTimeElapsed;

		bool mIsSpecialChalengeRunning;
        bool mIsAwesomeChalengeRunning;

		float mTimeBeforeRestartElapsed;

		Entity* mBackground;
		Entity* mCounter;
        Entity* mEffect[2];
    
        PauseButton* mPauseButton;
        RestartButton* mRestartButton;
        ContinueButton* mContinueButton;
        PauseSoundButton* mPauseSoundButton;
        PauseMusicButton* mPauseMusicButton;

		Entity* test;

        CCLayer* mMainMenuLayer;
        CCLayer* mExtrasLayer;
        CCLayer* mModeLayer;
		CCLayer* mTopLayer;
        CCLayer* mBottomLayer;
        CCLayer* mPauseLayer;
    
        bool mShaking;
    
        float mShakeDuration;
        float mShakeIntensity;
        float mShakeDurationElapsed;
    
        bool mSlide;
    
        int mSlideOperations;
    
        float mSlideVectorX;
        float mSlideVectorY;
    
        SoundButton* mSoundButton;
        MusicButton* mMusicButton;
        TwitterButton* mTwitterButton;
        FacebookButton* mFacebookButton;
    
        Circle* mCircles[16];

		// ===========================================================
		// Constructors
		// ===========================================================

		// ===========================================================
		// Methods
		// ===========================================================

		// ===========================================================
		// Virtual Methods
		// ===========================================================

	private:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

		// ===========================================================
		// Fields
		// ===========================================================

		CCLabelTTF* mFruitsSlashed;
		CCLabelTTF* mBestFruitsSlashed;

		bool mIsGameRunning;

		bool mDebugInformationNeed;

		CCLabelTTF* mDebugInformation[64];

		float mDebugUpdateTime;
		float mDebugUpdateTimeElapsed;
    
        float mFpsSum;
        int mFpsCount;

		// ===========================================================
		// Constructors
		// ===========================================================

		// ===========================================================
		// Methods
		// ===========================================================
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================

	public:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================
    
        static int APPEND_STATUS;
    
        static const int APPEND_STATUS_MAIN_MENU = 1;
        static const int APPEND_STATUS_EXTRAS = 2;
        static const int APPEND_STATUS_MODE = 3;
        static const int APPEND_STATUS_GAME = 4;
    
		static int FRUITS;
		static int SCORE;
		static int LIFES;

		// ===========================================================
		// Fields
		// ===========================================================
    
        BatchEntityManager* mCirclesManager;
        BatchEntityManager* mCirclesFruits;
        BatchEntityManager* mCirclesParts;
        BatchEntityManager* mCirclesCutters;
        BatchEntityManager* mCirclesSplashes;
    
        DropsManager* mCirclesDropsManager;
    
		BatchEntityManager* mFruits;
		BatchEntityManager* mParts;
		BatchEntityManager* mSplashes;
		BatchEntityManager* mLifes;
		BatchEntityManager* mCriticalHits;
        BatchEntityManager* mSparks;
        BatchEntityManager* mShadows;
        BatchEntityManager* mMarks;
        BatchEntityManager* mCutters;
        BatchEntityManager* mAwCutters;
        BatchEntityManager* mWaves;
        BatchEntityManager* mParticles;
    
        DropsManager* mDropsManager;
    
        Entity* mAwesomeLights;
    
    	CCParticleSystemQuad* mParticlesTypeDanger;

		CCLabelTTF* mSpecialLabel;
        CCLabelTTF* mSpecialLabelScore;
    
        CCLayer* mFruitsLayer;
    
        Entity* mMenuDecorations[4];

		// ===========================================================
		// Constructors
		// ===========================================================

		Menu();

		// ===========================================================
		// Methods
		// ===========================================================

		void startGame();
		void updateCounter();
		void removeLife();
		void runSpecialChalenge();
        void runAwesomeChalenge();
		void stopSpecialChalenge();
        void hitedAwesome();
    
        void shake(float d, float i);
    
        void randomSlide();
    
        void hitedAwesomeLast();
    
        void switchPause();
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================

		void update(float pDeltaTime);

		void onEnter();
};

#endif