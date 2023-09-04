#ifndef __BUNKER_H
#define __BUNKER_H

#include "Texture.h"


using namespace SDLFramework;



class Bunker : public GameEntity
{
private:
    int hitCount;
    Texture* mInitialTexture;
    Texture* mDamagedTexture1;
    Texture* mDamagedTexture2;
    Texture* mCurrentTexture;

public:
    Bunker();
    ~Bunker();

    void onHit();

    void Render();
   
};




#endif // !__BUNKER_H
