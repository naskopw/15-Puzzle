#pragma once
#include "cocos2d.h"

class SplashScreen : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(SplashScreen);
private:
    void GoToMainMenuScene(float dt);
};
