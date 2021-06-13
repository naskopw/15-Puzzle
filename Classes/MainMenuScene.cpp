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
	menuItemSpacing = visibleSize.height / 22;
	auto backgroundSprite = Sprite::create(BACKGROUND_SPRITE_RESOURCE);
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	backgroundSprite->setScale(visibleSize.height / backgroundSprite->getContentSize().height);
	this->addChild(backgroundSprite);

	
	auto titleSprite = menuFactory::createTitle(TITLE,
		MENU_PREFERED_FONT_RESOURCE,
		36,
		Color3B(0, 0, 0),
		Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + menuItemSpacing * 4));

	this->addChild(titleSprite);

	MenuItemFont::setFontName(MENU_PREFERED_FONT_RESOURCE);
	std::vector<MenuItemFont*> menuItems = {
		MenuItemFont::create("Play", CC_CALLBACK_1(MainMenuScene::goToGameScene, this)),
		MenuItemFont::create("Exit", CC_CALLBACK_1(MainMenuScene::exit, this)),
	};

	auto menu = menuFactory::createMenu(menuItems, Color3B(0, 0, 0), menuItemSpacing);
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