#include "MainMenuScene.h"
#include "Definitions.h"
#include "GameScene.h"
#include <vector>
USING_NS_CC;

Scene* MainMenuScene::createScene()
{
	return MainMenuScene::create();
}


// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	menuItemSpacing = visibleSize.height / 18;
	auto backgroundSprite = Sprite::create(BACKGROUND_SPRITE_RESOURCE);
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	backgroundSprite->setScale(visibleSize.height / backgroundSprite->getContentSize().height);
	this->addChild(backgroundSprite);

	std::vector<MenuItemImage*> menuItems = {
		MenuItemImage::create(PLAY_BUTTON_SPRITE_RESOURCE,
		PLAY_BUTTON_SPRITE_RESOURCE,
		CC_CALLBACK_1(MainMenuScene::goToGameScene, this)),

		MenuItemImage::create(EXIT_BUTTON_SPRITE_RESOURCE,
		EXIT_BUTTON_SPRITE_RESOURCE,
		CC_CALLBACK_1(MainMenuScene::exit, this)),
	};

	auto menu = menuImageFactory::createMenu(menuItems, menuItemSpacing);
	this->addChild(menu);
	return true;
}

void MainMenuScene::goToGameScene(cocos2d::Ref* sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void MainMenuScene::exit(cocos2d::Ref* sender)
{
	Director::getInstance()->end();
}