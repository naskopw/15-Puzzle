#include "GameOverScene.h"
#include "Definitions.h"
#include "GameScene.h"

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

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	menuItemSpacing = visibleSize.height / 22;

	auto backgroundSprite = Sprite::create(BACKGROUND_SPRITE_RESOURCE);
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	backgroundSprite->setScale(visibleSize.height / backgroundSprite->getContentSize().height);
	this->addChild(backgroundSprite);

	MenuItemFont::setFontName(MENU_PREFERED_FONT_RESOURCE);

	auto winSprite = menuFactory::createTitle(WIN_MSG,
		MENU_PREFERED_FONT_RESOURCE,
		36,
		Color3B(0, 0, 0),
		Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + menuItemSpacing * 4));
	this->addChild(winSprite);

	std::vector<MenuItemFont*> menuItems = {
		MenuItemFont::create("Play again", CC_CALLBACK_1(GameOverScene::goToGameScene, this)),
		MenuItemFont::create("Exit", CC_CALLBACK_1(GameOverScene::exit, this)),
	};
	auto menu = menuFactory::createMenu(menuItems, Color3B(0, 0, 0), menuItemSpacing);
	this->addChild(menu);

	return true;
}

void GameOverScene::goToGameScene(cocos2d::Ref* sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void GameOverScene::exit(cocos2d::Ref* sender)
{
	Director::getInstance()->end();
}
