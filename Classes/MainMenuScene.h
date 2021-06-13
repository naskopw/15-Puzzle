#pragma once
#include "cocos2d.h"
#include "MenuFactory.h"

class MainMenuScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	// implement the "static create()" method manually
	CREATE_FUNC(MainMenuScene);
private:
	typedef MenuFactory<std::vector<cocos2d::MenuItemFont*>> menuFactory;
	float menuItemSpacing = 10;
	void goToGameScene(cocos2d::Ref* sender);
	void exit(cocos2d::Ref* sender);
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	const char* const TITLE = "15 Puzzle";
};
