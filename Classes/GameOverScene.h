#pragma once
#include <cocos2d.h>
#include <vector>
#include "MenuFactory.h"

class GameOverScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	// implement the "static create()" method manually
	CREATE_FUNC(GameOverScene);
private:
	typedef MenuFactory<std::vector<cocos2d::MenuItemFont*>> menuFactory;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	float menuItemSpacing = 10;
	void goToGameScene(cocos2d::Ref* sender);
	void exit(cocos2d::Ref* sender);
	const char* WIN_MSG = "You win!";
};
