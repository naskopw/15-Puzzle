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
	backgroundSprite->setScale(visibleSize.height/backgroundSprite->getContentSize().height);
	this->addChild(backgroundSprite);

	auto titleSprite = Sprite::create(TITLE_SPRITE_RESOURCE);
	titleSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize().height));

	this->addChild(titleSprite);

	MenuItemFont::setFontName(MENU_PREFERED_FONT_RESOURCE);
	std::vector<MenuItemFont*> menuItems = {
		MenuItemFont::create("Play", CC_CALLBACK_1(MainMenuScene::goToGameScene, this)),
		MenuItemFont::create("Exit", CC_CALLBACK_1(MainMenuScene::exit, this)),
	};
	createMenu(menuItems);
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


void MainMenuScene::createMenu(std::vector<cocos2d::MenuItemFont*>& menuItems) {
	auto menu = Menu::create();
	for (std::size_t i = 0; i < menuItems.size(); i++) {
		menuItems[i]->setColor(Color3B(0, 0, 0));
		menuItems[i]->setPosition(Point(visibleSize.width / 2 + origin.x,
			visibleSize.height / 2 + origin.y-i*menuItemSpacing));
		menu->addChild(menuItems[i]);
	}
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
}