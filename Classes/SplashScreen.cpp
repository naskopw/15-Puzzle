#include "SplashScreen.h"
#include "MainMenuScene.h"
#include "Definitions.h"

#include <AudioEngine.h>

USING_NS_CC;

Scene* SplashScreen::createScene()
{
    return SplashScreen::create();
}

// on "init" you need to initialize your instance
bool SplashScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    startAudio();
    this->scheduleOnce(CC_SCHEDULE_SELECTOR(SplashScreen::goToMainMenuScene), DISPLAY_TIME_SPLASH_SCENE);

    auto splashScreenSprite = Sprite::create(SPLASH_SCREEN_SPRITE_RESOURCE);
    splashScreenSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->addChild(splashScreenSprite);

    return true;
}

void SplashScreen::startAudio() const
{
    AudioEngine::play2d(THEME_SONG_RESOURCE, true);
}

void SplashScreen::goToMainMenuScene(float dt)
{
    auto scene = MainMenuScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


