#include "GameOverScene.h"
#include "Definitions.h"

#include <AudioEngine.h>

USING_NS_CC;

Scene* GameOverScene::createScene()
{
    return GameOverScene::create();
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    return true;
}
