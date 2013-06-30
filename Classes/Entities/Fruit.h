#ifndef CONST_FRUIT_H
#define CONST_FRUIT_H

#include "cocos2d.h"

#include "ImpulseEntity.h"
#include "Part.h"
#include "Cutter.h"

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
    
    	Entity* mLight;
        Entity* mShadow;

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
    
        static int const TYPE_DANGER = 0;
        static int const TYPE_PINEAPPLE = 1;
        static int const TYPE_STRAWBERRY = 2;
        static int const TYPE_WATERMELON = 3;
        static int const TYPE_BANANA = 4;
        static int const TYPE_GRAPES = 5;

        static bool SPECIAL_EXIST;

		// ===========================================================
		// Fields
        // ===========================================================
    
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