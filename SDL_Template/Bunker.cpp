#include "Bunker.h"

Bunker::Bunker()
{
    hitCount = 0;
    mInitialTexture = new Texture("one.png");
    mInitialTexture->Parent(this);
   
    mDamagedTexture1 = new Texture("two.png");
    mDamagedTexture1->Parent(this);
   

    mDamagedTexture2 = new Texture("three.png");
    mDamagedTexture2->Parent(this);
  
    mCurrentTexture = mInitialTexture;
}

Bunker::~Bunker()
{
    delete mInitialTexture;
    mInitialTexture = nullptr;
    delete mDamagedTexture1;
    mDamagedTexture1 = nullptr;
    delete mDamagedTexture2;
    mDamagedTexture2 = nullptr;
}

void Bunker::onHit() {
    hitCount++;
    switch (hitCount) {
    case 1:
        // Switch to first damaged texture
        mCurrentTexture = mDamagedTexture1;
        break;
    case 2:
        // Switch to second damaged texture
        mCurrentTexture = mDamagedTexture2;
        break;
    case 3:
        // Remove the bunker
        this->Active(false); // or equivalent to remove it
        break;
    }
}

void Bunker::Render() {
    if (this->Active()) {
        mCurrentTexture->Render();
    }
}

