#ifndef CONST_SPARK
#define CONST_SPARK

#include "Spark.h"

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

Spark::Spark() :
    Entity("spark.png", 2, 3)
    {
        
    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void Spark::onCreate()
{
    Entity::onCreate();
        
    this->pVectorX = Utils::randomf(-1000.0, 1000.0);
    this->pVectorY = Utils::randomf(-1000.0, 1000.0);
        
    this->setScale(Utils::randomf(0.4, 1.5));
}
    
Spark* Spark::deepCopy()
{
    return new Spark();
}
    
void Spark::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
        
    pDeltaTime *= Processor::FREEZY_TIME;
        
    this->setCenterPosition(this->getCenterX() + this->pVectorX * pDeltaTime, this->getCenterY() + this->pVectorY * pDeltaTime);
        
    this->pVectorX = this->pVectorX > 0 ? this->pVectorX + this->pVectorX * 0.1 : this->pVectorX + this->pVectorX * 0.1;
    this->pVectorY = this->pVectorY > 0 ? this->pVectorY + this->pVectorY * 0.1 : this->pVectorY + this->pVectorY * 0.1;
        
    if(this->getCenterX() < 0 || this->getCenterX() > Options::CAMERA_WIDTH || this->getCenterY() < 0 || this->getCenterY() > Options::CAMERA_HEIGHT)
    {
        this->destroy();
    }
}

#endif