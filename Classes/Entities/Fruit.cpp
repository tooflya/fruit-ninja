#ifndef CONST_FRUIT
#define CONST_FRUIT

#include "Fruit.h"

#include "Menu.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

bool Fruit::SPECIAL_EXIST = false;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Fruit::Fruit() :
    ImpulseEntity("fruits.png", 6, 3)
    {
        this->mLight = new Entity("light.png", 1, 2);
        this->mShadow = NULL;

        this->mTimeUntilDown = 0.22;

        this->mSoundEffect = 0;
        this->mLifes = -1;

        this->mSpecial = false;
        this->mAwesome = false;
        
        this->mMarkTime = 0.1;
        this->mMarkTimeElapsed = 0;
    }

// ===========================================================
// Methods
// ===========================================================

void Fruit::fall(float pVectorX, float pVectorY, bool pMustReverse)
{
    this->mIsGone = true;
    
    this->mGoneVectorX = pVectorX;
    this->mGoneVectorY = pVectorY;
}

void Fruit::update(float pDeltaTime)
{
    if(!this->isVisible()) return;
    
    ImpulseEntity::update(pDeltaTime);

    Menu* menu = (Menu*) this->getParent()->getParent()->getParent();
    
    if(this->getCenterY() < -Utils::coord(200))
    {
        this->destroy();
    }
    
    bool collides = false;
    
    for(int i = 0; i < 10; i++)
    {
        if(this->isCollideWithPoint(Processor::TOUCH_COORDINATES[i].x, Processor::TOUCH_COORDINATES[i].y))
        {
            collides = true;
            
            if(this->mAwesome)
            {
                if(this->mLifes > 0 && menu->mFruitsLayer->getScaleX() == 1.0)
                {
                    collides = false;
                }
            }
        }
    }
    
    if(this->mAwesome)
    {
        if(Processor::FREEZY_TIME == 1.0 && this->mLifes > 0)
        {
            collides = true;
            
            this->mLifes = -1;
        }
    }
    
    if(this->mMustBeDestroy)
    {
        this->mLifes = -1;
        
        collides = true;
    }
    
    if(collides)
    {
        if(this->mAwesome)
        {
            menu->hitedAwesome();
        }
        
        if(this->mLifes >= 0)
        {
            if(this->getScaleX() == 1)
            {
                this->mLifes++;

                if(this->mLifes == 1)
                {
                    menu->mSpecialLabel->setVisible(true);
                    menu->mSpecialLabelScore->setVisible(true);
                }
                
                char text[256];
                sprintf(text, "%d points", 100 * this->mLifes);
                menu->mSpecialLabelScore->setString(text);

                menu->addScore(100 * this->mLifes);

                this->setScale(1.3);
                this->runAction(CCScaleTo::create(0.2, 1));

                sprintf(text, "combo-%d.mp3", this->mLifes);
                SimpleAudioEngine::sharedEngine()->playEffect(text);

                switch(this->mType)
                {
                    case 1:
                        SimpleAudioEngine::sharedEngine()->playEffect("impact-apple.ogg");
                    break;
                    case 2:
                        SimpleAudioEngine::sharedEngine()->playEffect("impact-apple.ogg");
                    break;
                    case 3:
                        SimpleAudioEngine::sharedEngine()->playEffect("impact-banana.ogg");
                    break;
                    case 4:
                        SimpleAudioEngine::sharedEngine()->playEffect("impact-coconut.ogg");
                    break;
                    case 5:
                        SimpleAudioEngine::sharedEngine()->playEffect("impact-watermelon.ogg");
                    break;
                    case 6:
                        SimpleAudioEngine::sharedEngine()->playEffect("impact-kiwifruit.ogg");
                    break;
                    case 7:
                        SimpleAudioEngine::sharedEngine()->playEffect("squash.mp3");
                    break;
                    case 8:
                        SimpleAudioEngine::sharedEngine()->playEffect("squash.mp3");
                    break;
                    case 9:
                        SimpleAudioEngine::sharedEngine()->playEffect("squash.mp3");
                    break;
                    case 10:
                        SimpleAudioEngine::sharedEngine()->playEffect("impact-orange.ogg");
                    break;
                    case 11:
                        SimpleAudioEngine::sharedEngine()->playEffect("squash.mp3");
                    break;
                    case TYPE_DANGER:
                        menu->mParticlesTypeDanger->setPosition(this->getCenterX(), this->getCenterY());
                        menu->mParticlesTypeDanger->resetSystem();

                        SimpleAudioEngine::sharedEngine()->playEffect("explosion.mp3");
                    break;
                }
                
                menu->mDropsManager->init(this->getCenterX(), this->getCenterY(),this->mType);

                if(this->mLifes == 8)
                {
                    if(this->mAwesome)
                    {
                        this->mLifes = 7;
                    }
                    else
                    {
                        this->mLifes = -1;
                    }
                }
            }
        }
        else
        {
            this->destroy();

            if(this->mType != TYPE_DANGER)
            {
                menu->updateCounter();
                menu->addScore(10);
            }
            else
            {
                if(!this->mMustBeDestroy)
                {
                    menu->removeLife();
                }
            }

            switch(this->mType)
            {
                case 1:
                    SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-apple.ogg");
                break;
                case 2:
                    SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-apple.ogg");
                break;
                case 3:
                    SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-banana.ogg");
                break;
                case 4:
                    SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-coconut.ogg");
                break;
                case 5:
                    SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-watermelon.ogg");
                break;
                case 6:
                    SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-kiwifruit.ogg");
                break;
                case 7:
                    SimpleAudioEngine::sharedEngine()->playEffect("Sound/squash.mp3");
                break;
                case 8:
                    SimpleAudioEngine::sharedEngine()->playEffect("Sound/squash.mp3");
                break;
                case 9:
                    SimpleAudioEngine::sharedEngine()->playEffect("Sound/squash.mp3");
                break;
                case 10:
                    SimpleAudioEngine::sharedEngine()->playEffect("Sound/impact-orange.ogg");
                break;
                case 11:
                    SimpleAudioEngine::sharedEngine()->playEffect("Sound/squash.mp3");
                break;
                case TYPE_DANGER:
                    menu->mParticlesTypeDanger->setPosition(this->getCenterX(), this->getCenterY());
                    menu->mParticlesTypeDanger->resetSystem();

                    SimpleAudioEngine::sharedEngine()->playEffect("Sound/explosion.mp3");
                break;
            }
            
            menu->mDropsManager->init(this->getCenterX(), this->getCenterY(),this->mType);
            
            int u = 1;
            
            if(this->mAwesome)
            {
                u = 20;
            }
            
            int padding = 0;
            
            for(int i = 0; i < u; i++)
            {
                Entity* splash = menu->mSplashes->create();
                
                if(u == 1)
                {
                    splash->setCenterPosition(this->getCenterX(), this->getCenterY());
                }
                else
                {
                    float x, y;
                    
                    if(i == 0)
                    {
                        x = this->getCenterX();
                        y = this->getCenterY();
                    }
                    else if(i < 5)
                    {
                        x = this->getCenterX() - Utils::coord(100.0) * padding;
                        y = this->getCenterY() + Utils::coord(100.0) * padding;
                    }
                    else if(i < 9)
                    {
                        x = this->getCenterX() + Utils::coord(100.0) * padding;
                        y = this->getCenterY() + Utils::coord(100.0) * padding;
                    }
                    else if(i < 13)
                    {
                        x = this->getCenterX() - Utils::coord(100.0) * padding;
                        y = this->getCenterY() - Utils::coord(100.0) * padding;
                    }
                    else if(i < 17)
                    {
                        x = this->getCenterX() + Utils::coord(100.0) * padding;
                        y = this->getCenterY() - Utils::coord(100.0) * padding;
                    }
                    else if(i < 18)
                    {
                        x = this->getCenterX();
                        y = this->getCenterY() + Utils::coord(300.0);
                    }
                    else if(i < 19)
                    {
                        x = this->getCenterX();
                        y = this->getCenterY() - Utils::coord(300.0);
                    }
                    else if(i < 20)
                    {
                        x = this->getCenterX() + Utils::coord(300.0);
                        y = this->getCenterY();
                    }
                    else if(i < 21)
                    {
                        x = this->getCenterX() - Utils::coord(300.0);
                        y = this->getCenterY();
                    }
                    else
                    {
                        x = 0;
                        y = 0;
                    }
                    
                    splash->setCenterPosition(x, y);
                    
                    padding++;
                    
                    if(i == 0 || i == 4 || i == 8 || i == 12 || i == 16) padding = 1;
                }

                switch(this->mType)
                {
                    case 1:
                        splash->setColor(ccc3(181.0, 40.0, 46.0));
                        break;
                    case 2:
                        splash->setColor(ccc3(193.0, 214.0, 47.0));
                        break;
                    case 3:
                        splash->setColor(ccc3(251.0, 226.0, 22.0));
                        break;
                    case 4:
                        splash->setColor(ccc3(255.0, 255.0, 255.0));
                        break;
                    case 5:
                        splash->setColor(ccc3(237.0, 51.0, 65.0));
                        break;
                    case 6:
                        splash->setColor(ccc3(119.0, 190.0, 68.0));
                        break;
                    case 7:
                        splash->setColor(ccc3(247.0, 207.0, 58.0));
                        break;
                    case 8:
                        splash->setColor(ccc3(47.0, 165.0, 72.0));
                        break;
                    case 9:
                        splash->setColor(ccc3(250.0, 166.0, 50.0));
                        break;
                    case 10:
                        splash->setColor(ccc3(244.0, 107.0, 37.0));
                        break;
                    case 11:
                        splash->setColor(ccc3(225.0, 204.0, 33.0));
                        break;
                    case TYPE_DANGER:
                        splash->destroy();
                        break;
                }
            }

            if(this->mType != TYPE_DANGER)
            {
                int u;
                
                if(this->mAwesome)
                {
                    u = 10;
                }
                else
                {
                    u = 2;
                }
                
                for(int i = 0; i < u; i++)
                {
                    Part* part = (Part*) menu->mParts->create();

                    part->setCurrentFrameIndex(i == 0 ? this->getCurrentFrameIndex() * 3 : this->getCurrentFrameIndex() * 3 + Utils::random(1, 2));
                    part->setCenterPosition(this->getCenterX() + Utils::coord(Utils::randomf(-50.0, 50.0)), this->getCenterY() + Utils::coord(Utils::randomf(-50.0, 50.0)));

                    part->mRotateImpulse = this->mRotateImpulse;
                    part->mImpulsePower = this->mImpulsePower;
                    part->mSideImpulse = i == 0 ? this->mSideImpulse : -this->mSideImpulse;
                    part->mWeight = this->mWeight;

                    part->mType = this->mType;
                    
                    if(this->mAwesome || this->mMustBeDestroy)
                    {
                        part->setAwesome(i, u);
                        
                        part->mRotateImpulse = Utils::randomf(-500.0, 500.0);
                    }
                }
                
                if(this->mAwesome)
                {
                    for(int i = 0; i < menu->mFruits->getCount(); i++)
                    {
                        ((Fruit*) menu->mFruits->objectAtIndex(i))->mMustBeDestroy = true;
                    }
                }
            }

            // Critical hit

            if(this->mImpulsePower > Utils::coord(500) && this->mType != TYPE_DANGER)
            {
                SimpleAudioEngine::sharedEngine()->playEffect("Sound/critical.ogg");

                menu->mCriticalHits->create()->setCenterPosition(this->getCenterX(), this->getCenterY());

                int frame = Utils::random(0, 5);

                for(int i = 0; i < 200; i++)
                {
                    Entity* spark = (Entity*) menu->mSparks->create();
                    spark->setCurrentFrameIndex(frame);
                    spark->setCenterPosition(this->getCenterX(), this->getCenterY());
                }

                menu->addScore(1000);
            }
        }
    }
    
    if(this->getCenterY() < -Utils::coord(200) && this->mImpulsePower <= 0.0f)
    {
        this->destroy();

        if(this->mType != TYPE_DANGER)
        {
            SimpleAudioEngine::sharedEngine()->playEffect("Sound/lose_life.mp3");

            menu->removeLife();
        }
    }

    if(this->mSpecial || this->mAwesome)
    {
        this->mLight->setCenterPosition(this->getCenterX(), this->getCenterY());
        this->mLight->setRotation(this->mLight->getRotation() + 3.0);
    }
    
    if(this->mShadow != NULL)
    {
        this->mShadow->setCenterPosition(this->getCenterX() - Utils::coord(20.0), this->getCenterY() - Utils::coord(70));
    }
    
    this->mMarkTimeElapsed += pDeltaTime;
    
    if(this->mMarkTimeElapsed >= this->mMarkTime)
    {
        this->mMarkTimeElapsed = 0;
        
        menu->mMarks->create()->setCenterPosition(this->getCenterX(), this->getCenterY());
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Fruit::setSpecialChalenge()
{
    if(this->mType == TYPE_DANGER)
    {
        this->destroy();
    }

    this->setCenterPosition(Utils::random(0, 1) == 0 ? 0 : Options::CAMERA_WIDTH, Utils::randomf(Options::CAMERA_CENTER_Y - Utils::coord(300), Options::CAMERA_CENTER_Y - Utils::coord(100)));
    
    this->mSideImpulse   = Utils::coord(Utils::randomf(300.0f, 600.0f));
    this->mRotateImpulse = Utils::randomf(-360.0f, 360.0f);
    this->mImpulsePower = Utils::coord(1000.0f);
    
    this->mSideImpulse = this->getCenterX() < Options::CAMERA_CENTER_X ? -this->mSideImpulse : this->mSideImpulse;

    if(this->mSpecial)
    {
        SPECIAL_EXIST = false;
        Processor::SPECIAL_FRUIT = NULL;

        Menu* menu = (Menu*) this->getParent()->getParent()->getParent();

        menu->mSpecialLabel->setVisible(false);
        menu->mSpecialLabelScore->setVisible(false);
        
        this->mLifes = -1;
    }

    this->mSpecial = false;
    this->mLight->destroy();
}

void Fruit::setAwesomeChalenge()
{
    if(this->mType == TYPE_DANGER)
    {
        
    }
    else
    {
    
        this->mLight->create()->setCurrentFrameIndex(1);
    
        Processor::AWESOME_FRUIT = this;
    
        this->mAwesome = true;
        
        this->mLifes = 0;
    }
}

void Fruit::onCreate()
{
    ImpulseEntity::onCreate();
    
    this->mSpecial = false;
    this->mAwesome = false;

    this->mType = Utils::random(0, 14);
    
    this->mIsDown = false;
    this->mTimeUntilDownElapsed = 0;
    this->mWeight = Utils::coord(1200.0f);
    this->mImpulsePower = Utils::coord(1200.0f);
    
    this->mIsGone = false;
    this->mMustBeDestroy = false;
    
    this->setCenterPosition(Utils::randomf(0, Options::CAMERA_WIDTH), Utils::randomf(-180.0, 0.0));
    
    this->mSideImpulse   = Utils::coord(Utils::randomf(100.0f, 300.0f));
    this->mRotateImpulse = Utils::randomf(-360.0f, 360.0f);
    
    this->mSideImpulse = this->getCenterX() < Options::CAMERA_CENTER_X ? -this->mSideImpulse : this->mSideImpulse;
    
    this->setCurrentFrameIndex(this->mType);

    if(this->mType == TYPE_DANGER)
    {
        this->mSoundEffect = SimpleAudioEngine::sharedEngine()->playEffect("throw-bomb.ogg");
        this->mSoundEffect = SimpleAudioEngine::sharedEngine()->playEffect("bomb-fuse.ogg");
    }
    else
    {
        this->mSoundEffect = SimpleAudioEngine::sharedEngine()->playEffect("throw-fruit.ogg");
    }

    if(this->mLight->getParent() == false)
    {
        this->getParent()->getParent()->addChild(this->mLight, 0);
    }

    // Special?

    if(Utils::probably(25) && this->mType != TYPE_DANGER && !SPECIAL_EXIST)
    {
        this->mSpecial = true;

        this->mLight->create()->setCurrentFrameIndex(0);

        this->mLifes = 0;

        SPECIAL_EXIST = true;
        Processor::SPECIAL_FRUIT = this;
    }
    else
    {
        this->mLifes = -1;
    }
    
    if(this->mShadow != NULL) // TODO: Remove this.
    {
        this->mShadow->destroy();
        this->mShadow = NULL;
    }
    
    Menu* menu = (Menu*) this->getParent()->getParent()->getParent();
    
    this->mShadow = menu->mShadows->create();
}

void Fruit::onDestroy()
{
    ImpulseEntity::onDestroy();

    if(this->mSoundEffect != 0)
    {
        SimpleAudioEngine::sharedEngine()->stopEffect(this->mSoundEffect);
    }

    if(this->mSpecial)
    {
        SPECIAL_EXIST = false;
        Processor::SPECIAL_FRUIT = NULL;

        Menu* menu = (Menu*) this->getParent()->getParent()->getParent();

        menu->mSpecialLabel->setVisible(false);
        menu->mSpecialLabelScore->setVisible(false);
    }

    this->mSpecial = false;
    this->mLight->destroy();
    
    if(this->mShadow != NULL)
    {
        this->mShadow->destroy();
        this->mShadow = NULL;
    }
}

Fruit* Fruit::deepCopy()
{
    return new Fruit();
}

void Fruit::onEnter()
{
    Entity::onEnter();
}

void Fruit::draw()
{
    Entity::draw();
    /*CCPoint vertices2[4] = { ccp(0,0), ccp(this->getWidth(),0), ccp(0,this->getHeight()), ccp(0,this->getHeight()) };
   

    CC_PROFILER_START_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");

    CCAssert(!m_pobBatchNode, "If CCSprite is being rendered by CCSpriteBatchNode, CCSprite#draw SHOULD NOT be called");

    CC_NODE_DRAW_SETUP();

    ccGLBlendFunc( m_sBlendFunc.src, m_sBlendFunc.dst );

    if (m_pobTexture != NULL)
    {
        ccGLBindTexture2D( m_pobTexture->getName() );
        ccGLEnableVertexAttribs( kCCVertexAttribFlag_PosColorTex );
    }
    else
    {
        ccGLBindTexture2D(0);
        ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position | kCCVertexAttribFlag_Color );
    }

#define kQuadSize sizeof(m_sQuad.bl)
#ifdef EMSCRIPTEN
    long offset = 0;
    setGLBufferData(&m_sQuad, 4 * kQuadSize, 0);
#else
    long offset = (long)&m_sQuad;
#endif // EMSCRIPTEN

    // vertex
    int diff = offsetof( ccV3F_C4B_T2F, vertices2);
    glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, kQuadSize, (void*) (offset + diff));

    if (m_pobTexture != NULL)
    {
        // texCoods
        diff = offsetof( ccV3F_C4B_T2F, texCoords);
        glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, kQuadSize, (void*)(offset + diff));
    }
    
    // color
    diff = offsetof( ccV3F_C4B_T2F, colors);
    glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE, kQuadSize, (void*)(offset + diff));


    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    CHECK_GL_ERROR_DEBUG();*/
}

#endif