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
        Entity* mWhiteEffect;

		Entity* test;

		CCLayer* mMainMenuLayer;
		CCLayer* mTopLayer;
        CCLayer* mBottomLayer;
    
        bool mShaking;
    
        float mShakeDuration;
        float mShakeIntensity;
        float mShakeDurationElapsed;
    
        bool mSlide;
    
        int mSlideOperations;
    
        float mSlideVectorX;
        float mSlideVectorY;

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
		CCLabelTTF* mScore;

		bool mIsGameRunning;

		bool mDebugInformationNeed;

		CCLabelTTF* mDebugInformation[32];

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
    
		static int FRUITS;
		static int SCORE;
		static int LIFES;

		// ===========================================================
		// Fields
		// ===========================================================

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
    
        DropsManager* mDropsManager;
    
    	CCParticleSystemQuad* mParticlesTypeDanger;

		CCLabelTTF* mSpecialLabel;
        CCLabelTTF* mSpecialLabelScore;
    
        CCLayer* mFruitsLayer;

		// ===========================================================
		// Constructors
		// ===========================================================

		Menu();

		// ===========================================================
		// Methods
		// ===========================================================

		void startGame();
		void updateCounter();
		void addScore(int pScore);
		void removeLife();
		void runSpecialChalenge();
        void runAwesomeChalenge();
		void stopSpecialChalenge();
        void hitedAwesome();
    
        void shake(float d, float i);
    
        void randomSlide();
    
        void hitedAwesomeLast();
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================

		void update(float pDeltaTime);

		void onEnter();
};

#endif