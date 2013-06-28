#ifndef CONST_LABEL
#define CONST_LABEL

#include "Label.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Label::Label(const char* pFileName, int pHorizontalFramesCount, int pVerticalFramesCount) :
	Entity(pFileName, pHorizontalFramesCount, pVerticalFramesCount)
	{
	}

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

void Label::onCreate()
{
	Entity::onCreate();

	this->mTime = 1.0;
	this->mTimeElapsed = 0;

	this->setOpacity(255.0);
}

void Label::update(float pDeltaTime)
{
	Entity::update(pDeltaTime);

	if(!this->isVisible()) return;

	this->mTimeElapsed += pDeltaTime;

	if(this->mTimeElapsed >= this->mTime)
	{
		this->mTime = 10.0;

		this->runAction(CCFadeTo::create(0.5, 0.0));
	}

	if(this->getOpacity() <= 0)
	{
		this->destroy();
	}
}

Label* Label::deepCopy()
{
	return new Label(this->getTextureFileName(), this->mHorizontalFramesCount, this->mVerticalFramesCount);
}

#endif