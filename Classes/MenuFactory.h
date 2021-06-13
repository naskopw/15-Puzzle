#pragma once
#include "cocos2d.h"

template <typename Container>
class MenuFactory
{
public:
	static cocos2d::Menu* createMenu(Container& menuItems,
		const float menuItemSpacing);
};

template<typename Container>
inline cocos2d::Menu* MenuFactory<Container>::createMenu(Container& menuItems,
	const float menuItemSpacing)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto menu = Menu::create();
	for (std::size_t i = 0; i < menuItems.size(); i++) {
		menuItems[i]->setPosition(Point(visibleSize.width / 2 + origin.x,
			visibleSize.height / 2 - i * menuItemSpacing));
		menu->addChild(menuItems[i]);
	}
	menu->setPosition(Point::ZERO);
	return menu;
}