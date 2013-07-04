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

const ccColor3B Fruit::FRUITS_COLORS[Options::FRUITS_COUNT + 2] =
{
    ccc3(0.0, 0.0, 0.0),
    ccc3(181.0, 40.0, 46.0),
    ccc3(193.0, 214.0, 47.0),
    ccc3(251.0, 226.0, 22.0),
    ccc3(255.0, 255.0, 255.0),
    ccc3(255.0, 0.0, 0.0),
    ccc3(74.0, 165.0, 72.0),
    ccc3(247.0, 218.0, 62.0),
    ccc3(74.0, 165.0, 72.0),
    ccc3(255.0, 166.0, 50.0),
    ccc3(249.0, 161.0, 27.0),
    ccc3(225.0, 200.0, 33.0),
    ccc3(255.0, 181.0, 38.0),
    ccc3(241.0, 237.0, 150.0),
    ccc3(227.0, 37.0, 37.0),
    ccc3(189.0, 1.0, 28.0)
};

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
        
        this->mMarkTime = 0.02;
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
    
    if(!this->isVisible()) return;
    
    ImpulseEntity::update(pDeltaTime);

    Menu* menu = (Menu*) this->getParent()->getParent()->getParent();
    
    if(this->getCenterY() < -Utils::coord(200))
    {
        this->destroy();
    }
    
    bool collides = false;
    
    float angle = 0;
    
    for(int i = 0; i < 10; i++)
    {
        if(this->isCollideWithPoint(Processor::TOUCH_INFORMATION[i].position.x, Processor::TOUCH_INFORMATION[i].position.y) && Processor::TOUCH_INFORMATION[i].slice)
        {
            collides = true;
            
            Processor::TOUCH_INFORMATION[i].slice = false;
            
            if(this->mAwesome)
            {
                if(this->mLifes > 0 && menu->mFruitsLayer->getScaleX() == 1.0)
                {
                    collides = false;
                }
            }
            
            CCPoint diff = ccpSub(
                                  ccp(this->getCenterX(), this->getCenterY()),
                                  ccp(Processor::TOUCH_INFORMATION[i].position.x, Processor::TOUCH_INFORMATION[i].position.y)
                                  );
            angle = -CC_RADIANS_TO_DEGREES(atan2f(diff.y, diff.x));
        }
    }
    
    if(this->mAwesome)
    {
        if(this->mLifes > 0 && menu->mFruitsLayer->getScaleX() < Options::AWESOME_SCALE_APPEAR)
        {
            collides = false;
        }
        
        if(Processor::FREEZY_STATUS == Processor::FREEZY_STATUS_START_BLOW && this->mLifes > 0)
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
        if(this->getScaleX() == 1)
        {
            if(this->mAwesome)
            {
                if(this->mLifes > 0)
                {
                    Cutter* cutter = (Cutter*) menu->mAwCutters->create();
                
                    cutter->setCenterPosition(this->getCenterX(), this->getCenterY());
                    cutter->setRotation(angle);
                }
            }
            else
            {
                Cutter* cutter = (Cutter*) menu->mCutters->create();
                
                cutter->setCenterPosition(this->getCenterX(), this->getCenterY());
                cutter->setRotation(angle);
            }
        }
        
        if(this->mAwesome)
        {
            if(this->mLifes == -1)
            {
                menu->hitedAwesomeLast();
            }
            else
            {
                menu->hitedAwesome();
            }
        }
        
        if(this->mLifes >= 0)
        {
            if(this->getScaleX() == 1.0)
            {
                this->mLifes++;

                if(this->mSpecial)
                {
                    if(this->mLifes == 1)
                    {
                        menu->mSpecialLabel->setVisible(true);
                        menu->mSpecialLabelScore->setVisible(true);
                    }
                
                    char text[256];
                    sprintf(text, "%d points", 100 * this->mLifes);
                    menu->mSpecialLabelScore->setString(text);
                }
                
                menu->addScore(100 * this->mLifes);

                this->setScale(1.3);
                this->runAction(CCScaleTo::create(0.15, 1));

                SimpleAudioEngine::sharedEngine()->playEffect(Options::COMBO[this->mLifes]);

                switch(this->mType)
                {
                    case Options::TYPE_REDAPPLE:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_APPLE);
                        break;
                    case Options::TYPE_GREENAPPLE:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_APPLE);
                        break;
                    case Options::TYPE_BANANA:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_BANANA);
                        break;
                    case Options::TYPE_COCONUT:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_COCONUT);
                        break;
                    case Options::TYPE_WATERMELON:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_WATERMELON);
                        break;
                    case Options::TYPE_KIWIFRUIT:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_KIWIFRUIT);
                        break;
                    case Options::TYPE_LEMON:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                        break;
                    case Options::TYPE_LIME:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                        break;
                    case Options::TYPE_MANGO:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                        break;
                    case Options::TYPE_PEAR:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                        break;
                    case Options::TYPE_ORANGE:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_ORANGE);
                        break;
                    case Options::TYPE_PINEAPPLE:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                        break;
                    case Options::TYPE_STARFRUIT:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                        break;
                    case Options::TYPE_STRAWBERRY:
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                        break;
                    case Options::TYPE_DANGER:
                        menu->mParticlesTypeDanger->setPosition(this->getCenterX(), this->getCenterY());
                        menu->mParticlesTypeDanger->resetSystem();

                        SimpleAudioEngine::sharedEngine()->playEffect(Options::EXPLOSION);
                    break;
                }
                
                if(this->mType != Options::TYPE_BANANA && this->mType != Options::TYPE_DANGER)
                {
                    menu->mDropsManager->init(this->getCenterX(), this->getCenterY(),this->mType);
                }

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

            if(this->mType != Options::TYPE_DANGER)
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
                case Options::TYPE_REDAPPLE:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_APPLE);
                    break;
                case Options::TYPE_GREENAPPLE:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_APPLE);
                    break;
                case Options::TYPE_BANANA:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_BANANA);
                    break;
                case Options::TYPE_COCONUT:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_COCONUT);
                    break;
                case Options::TYPE_WATERMELON:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_WATERMELON);
                    break;
                case Options::TYPE_KIWIFRUIT:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_KIWIFRUIT);
                    break;
                case Options::TYPE_LEMON:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                    break;
                case Options::TYPE_LIME:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                    break;
                case Options::TYPE_MANGO:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                    break;
                case Options::TYPE_PEAR:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::IMPACT_ORANGE);
                    break;
                case Options::TYPE_PINEAPPLE:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                    break;
                case Options::TYPE_STARFRUIT:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                    break;
                case Options::TYPE_STRAWBERRY:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                    break;
                case Options::TYPE_ORANGE:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                    break;
                case Options::TYPE_GARNET:
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SQUASH);
                    break;
                case Options::TYPE_DANGER:
                    menu->mParticlesTypeDanger->setPosition(this->getCenterX(), this->getCenterY());
                    menu->mParticlesTypeDanger->resetSystem();

                    SimpleAudioEngine::sharedEngine()->playEffect(Options::EXPLOSION);
                break;
            }
            
            if(this->mType != Options::TYPE_BANANA && this->mType != Options::TYPE_DANGER)
            {
                menu->mDropsManager->init(this->getCenterX(), this->getCenterY(),this->mType);
            }
            
            int u = 1;
            
            if(this->mAwesome)
            {
                u = 20;
            }
            
            int padding = 0;
            
            
            if(this->mType != Options::TYPE_BANANA && this->mType != Options::TYPE_DANGER)
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
                    default:
                        splash->setColor(Fruit::FRUITS_COLORS[this->mType]);
                        break;
                    case Options::TYPE_DANGER:
                        splash->destroy();
                        break;
                }
            }

            if(this->mType != Options::TYPE_DANGER)
            {
                if(this->mAwesome)
                {
                    Part* part;
                    Particles* particle;
                    
                    // #-1
                    part = (Part*) menu->mParts->create();
                    
                    part->setCurrentFrameIndex(this->mType * 3 + 2);
                    part->setCenterPosition(this->getCenterX() - Utils::coord(25), this->getCenterY() + Utils::coord(25));
                    part->setScaleY(-1);
                    part->setAwesomeByVectors(-30.0, 20.0);
                    
                    // #-2
                    part = (Part*) menu->mParts->create();
                    
                    part->setCurrentFrameIndex(this->mType * 3 + 2);
                    part->setCenterPosition(this->getCenterX() + Utils::coord(25), this->getCenterY() + Utils::coord(25));
                    part->setScaleX(-1);
                    part->setScaleY(-1);
                    part->setAwesomeByVectors(30.0, 20.0);
                    
                    // #-3
                    part = (Part*) menu->mParts->create();
                    
                    part->setCurrentFrameIndex(this->mType * 3 + 2);
                    part->setCenterPosition(this->getCenterX() - Utils::coord(25), this->getCenterY() - Utils::coord(15));
                    part->setAwesomeByVectors(-30.0, -20.0);
                    
                    // #-4
                    part = (Part*) menu->mParts->create();
                    
                    part->setCurrentFrameIndex(this->mType * 3 + 2);
                    part->setCenterPosition(this->getCenterX() + Utils::coord(25), this->getCenterY() - Utils::coord(15));
                    part->setScaleX(-1);
                    part->setAwesomeByVectors(30.0, -20.0);
                    
                    // #1
                    part = (Part*) menu->mParts->create();
                    
                    part->setCurrentFrameIndex(this->mType * 3 + 1);
                    part->setCenterPosition(this->getCenterX() - Utils::coord(25), this->getCenterY() + Utils::coord(45));
                    part->setAwesomeByVectors(-15.0, 30.0);
                    
                    // #2
                    part = (Part*) menu->mParts->create();
                    
                    part->setCurrentFrameIndex(this->mType * 3 + 1);
                    part->setCenterPosition(this->getCenterX() + Utils::coord(25), this->getCenterY() + Utils::coord(45));
                    part->setScaleX(-1);
                    part->setAwesomeByVectors(15.0, 30.0);
                    
                    // #3
                    part = (Part*) menu->mParts->create();
                    
                    part->setCurrentFrameIndex(this->mType * 3);
                    part->setCenterPosition(this->getCenterX() - Utils::coord(35), this->getCenterY() - Utils::coord(25));
                    part->setAwesomeByVectors(-15.0, -30.0);
                    
                    // #4
                    part = (Part*) menu->mParts->create();
                    
                    part->setCurrentFrameIndex(this->mType * 3);
                    part->setCenterPosition(this->getCenterX() + Utils::coord(35), this->getCenterY() - Utils::coord(25));
                    part->setScaleX(-1);
                    part->setAwesomeByVectors(15.0, -30.0);
                    
                    for(int i = 0; i < 8; i++)
                    {
                        particle = (Particles*) menu->mParticles->create();
                        
                        particle->setCenterPosition(this->getCenterX(), this->getCenterY());
                        particle->setType(Particles::TYPE_GARNET_CORE_SMALL);
                        particle->setAwesome(i, 8);
                    }
                }
                else
                {
                    for(int i = 0; i < 2; i++)
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
                }
                
                                
                if(this->mAwesome)
                {
                    for(int i = 0; i < menu->mFruits->getCount(); i++)
                    {
                        ((Fruit*) menu->mFruits->objectAtIndex(i))->mMustBeDestroy = true;
                    }
                    
                    menu->mWaves->create()->setCenterPosition(this->getCenterX(), this->getCenterY());
                }
            }
            else
            {
                menu->shake(0.5, 5.0);
            }

            // Critical hit

            if(this->mImpulsePower > Utils::coord(500) && this->mType != Options::TYPE_DANGER)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::CRITICAL);

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

        if(this->mType != Options::TYPE_DANGER)
        {
            SimpleAudioEngine::sharedEngine()->playEffect(Options::LOSE_LIFE);

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
        
        Entity* entity = menu->mMarks->create();
        
        entity->setCenterPosition(this->getCenterX(), this->getCenterY());
        
        if(this->mType == Options::TYPE_DANGER)
        {
            entity->setColor(ccc3(255.0, 0.0, 0.0));
        }
        else
        {
            entity->setColor(ccc3(255.0, 255.0, 255.0));
        }
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Fruit::setSpecialChalenge()
{
    if(this->mType == Options::TYPE_DANGER)
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
    if(this->mType == Options::TYPE_DANGER)
    {
        
    }
    else
    {
        this->mType = Options::TYPE_GARNET;
        
        this->setCurrentFrameIndex(this->mType);
        
        this->mLight->create()->setCurrentFrameIndex(1);
    
        Processor::AWESOME_FRUIT = this;
    
        this->mAwesome = true;
        this->mSpecial = false;
        
        this->mLifes = 0;
    }
}

void Fruit::onCreate()
{
    ImpulseEntity::onCreate();
    
    this->mSpecial = false;
    this->mAwesome = false;

    this->mType = Utils::random(0, Options::FRUITS_COUNT);
    
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

    if(this->mType == Options::TYPE_DANGER)
    {
        this->mSoundEffect = SimpleAudioEngine::sharedEngine()->playEffect(Options::THROW_BOMB);
        this->mSoundEffect = SimpleAudioEngine::sharedEngine()->playEffect(Options::BOMB_FUSE);
    }
    else
    {
        this->mSoundEffect = SimpleAudioEngine::sharedEngine()->playEffect(Options::THROW_FRUIT);
    }

    if(this->mLight->getParent() == false)
    {
        this->getParent()->getParent()->addChild(this->mLight, 0);
    }

    // Special?

    if(Utils::probably(25) && this->mType != Options::TYPE_DANGER && !SPECIAL_EXIST)
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
}

#endif