#pragma once
#include "cocos2d.h"

template <typename Container>
class MenuFactory
{
public:
	static cocos2d::Menu* createMenu(Container& menuItems,
		const cocos2d::Color3B& color,
		const float menuItemSpacing);

	static cocos2d::Sprite* createTitle(const char* msg,
		const char* font,
		const float fontSize,
		const cocos2d::Color3B& color,
		const cocos2d::Point& position);

};

template<typename Container>
inline cocos2d::Menu* MenuFactory<Container>::createMenu(Container& menuItems,
	const cocos2d::Color3B& color,
	const float menuItemSpacing)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto menu = Menu::create();
	for (std::size_t i = 0; i < menuItems.size(); i++) {
		menuItems[i]->setColor(color);
		menuItems[i]->setPosition(Point(visibleSize.width / 2 + origin.x,
			visibleSize.height / 2 + origin.y - i * menuItemSpacing));
		menu->addChild(menuItems[i]);
	}
	menu->setPosition(Point::ZERO);
	return menu;
}

template<typename Container>
inline cocos2d::Sprite* MenuFactory<Container>::createTitle(const char* msg,
	const char* font,
	const float fontSize,
	const cocos2d::Color3B& color,
	const cocos2d::Point& position)
{
	auto sprite = Sprite::create();
	auto label = Label::createWithSystemFont(msg, font, fontSize);
	label->setColor(color);
	sprite->setPosition(position);
	sprite->addChild(label);
	return sprite;
}