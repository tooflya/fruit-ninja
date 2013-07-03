#ifndef CONST_FRUIT_H
#define CONST_FRUIT_H

#include "cocos2d.h"

#include "ImpulseEntity.h"
#include "Part.h"
#include "Cutter.h"
#include "Particles.h"

using namespace cocos2d;

class Fruit : public ImpulseEntity
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

    	CCParticleSystemQuad* mParticlesTypeDanger;
    	CCParticleSystemQuad* mParticlesTypePineApple;
    	CCParticleSystemQuad* mParticlesTypeStrawberry;
    	CCParticleSystemQuad* mParticlesTypeWatermelon;
    	CCParticleSystemQuad* mParticlesTypeBanana;
    	CCParticleSystemQuad* mParticlesTypeGrapes;

    	int mSoundEffect;

    	int mLifes;

    	bool mSpecial;
        bool mAwesome;
    
        float mMarkTime;
        float mMarkTimeElapsed;

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

        static bool SPECIAL_EXIST;
    
        static ccColor3B const FRUITS_COLORS[Options::FRUITS_COUNT + 2];

		// ===========================================================
		// Fields
        // ===========================================================
    
        Entity* mLight;
        Entity* mShadow;
    
        int mType;
    
        bool mIsGone;
    
        bool mIsDown;
    
        float mGoneVectorX;
        float mGoneVectorY;
    
        float mTimeUntilDown;
        float mTimeUntilDownElapsed;
    
        bool mMustBeDestroy;

		// ===========================================================
		// Constructors
		// ===========================================================
    
        Fruit();

		// ===========================================================
		// Methods
		// ===========================================================
    
        void fall(float pVectorX, float pVectorY, bool pMustReverse);
        void update(float pDelta);
        void draw();

        void setSpecialChalenge();
        void setAwesomeChalenge();
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
    
        virtual void onCreate();
        virtual void onDestroy();
    
        virtual Fruit* deepCopy();

        void onEnter();
};

#endif