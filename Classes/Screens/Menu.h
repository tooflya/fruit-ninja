#ifndef CONST_MENU_H
#define CONST_MENU_H

#include "cocos2d.h"

#include "Screen.h"
#include "Fruit.h"
#include "Part.h"
#include "Splash.h"
#include "Label.h"
#include "BatchEntityManager.h"

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

		float mSpecialChalengeTime;
		float mSpecialChalengeTimeElapsed;

		bool mIsSpecialChalengeRunning;

		float mTimeBeforeRestartElapsed;

		Entity* mBackground;
		Entity* mCounter;

		Entity* test;

		CCLayer* mMainMenuLayer;
		CCLayer* mTopLayer;
		CCLayer* mBottomLayer;

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

		CCLabelTTF* mDebugInformation[16];

		float mDebugUpdateTime;
		float mDebugUpdateTimeElapsed;

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

		class Spark : public Entity
		{
		protected:
			float pVectorX;
			float pVectorY;

		public:
			Spark() : Entity("spark.png", 2, 3)
			{
			}

			void onCreate()
			{
				Entity::onCreate();

				this->pVectorX = Utils::randomf(-1000.0, 1000.0);
				this->pVectorY = Utils::randomf(-1000.0, 1000.0);

				this->setScale(Utils::randomf(0.4, 1.5));
			}

			Spark* deepCopy()
			{
				return new Spark();
			}

			void update(float pDeltaTime)
			{
				Entity::update(pDeltaTime);

				this->setCenterPosition(this->getCenterX() + this->pVectorX * pDeltaTime, this->getCenterY() + this->pVectorY * pDeltaTime);
				
				this->pVectorX = this->pVectorX > 0 ? this->pVectorX + this->pVectorX * 0.1 : this->pVectorX + this->pVectorX * 0.1;
				this->pVectorY = this->pVectorY > 0 ? this->pVectorY + this->pVectorY * 0.1 : this->pVectorY + this->pVectorY * 0.1;

				if(this->getCenterX() < 0 || this->getCenterX() > Options::CAMERA_WIDTH || this->getCenterY() < 0 || this->getCenterY() > Options::CAMERA_HEIGHT)
				{
					this->destroy();
				}
			}
		};

		// ===========================================================
		// Constants
		// ===========================================================

		static CCPoint mTouchCoordinate;

		static int FRUITS;
		static int SCORE;
		static int LIFES;

		static Entity* SPECIAL_FRUIT;

		// ===========================================================
		// Fields
		// ===========================================================

		BatchEntityManager* mFruits;
		BatchEntityManager* mParts;
		BatchEntityManager* mSplashes;
		BatchEntityManager* mLifes;
		BatchEntityManager* mCriticalHits;
		BatchEntityManager* mSparks;
    
    	CCParticleSystemQuad* mParticlesTypeDanger;
    	CCParticleSystemQuad* mParticlesTypeFruits;

		CCLabelTTF* mSpecialLabel;
		CCLabelTTF* mSpecialLabelScore;

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
		void stopSpecialChalenge();
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================

		void update(float pDeltaTime);

		void onEnter();
};

#endif