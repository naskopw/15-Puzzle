#pragma once
#include <vector>
#include <memory>
#include "cocos2d.h"
#include "PuzzlePartSprite.h"
#include "state/Game.h"

class GameScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	void drawScene();
	std::vector<std::unique_ptr<PuzzlePartSprite>> sprites;
	std::unique_ptr<Game> game;
	void setupOnTouchBeginHandler();
	void updateTimer(float dt);
	cocos2d::Sprite* timerSprite = nullptr;
	cocos2d::Label* timerLabel = nullptr;
	long timer = 0;
	void setupTimer();
};
