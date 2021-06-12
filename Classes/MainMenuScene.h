#pragma once
#include "cocos2d.h"
class MainMenuScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	// implement the "static create()" method manually
	CREATE_FUNC(MainMenuScene);
private:
	int menuItemSpacing;
	void goToGameScene(cocos2d::Ref* sender);
	void exit(cocos2d::Ref* sender);
	void setMenuItems(const std::vector<cocos2d::MenuItemFont*>& menuItems);
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	void createMenu(std::vector<cocos2d::MenuItemFont*>& menuItems);
};
