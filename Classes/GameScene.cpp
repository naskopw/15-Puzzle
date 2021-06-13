#include "GameScene.h"
#include "GameOverScene.h"
#include "Definitions.h"
#include <string>
#include <sstream>
#include <time.h>

USING_NS_CC;

Scene* GameScene::createScene()
{
	return GameScene::create();
}


bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	game = std::make_unique<Game>();
	game->start();
	drawScene();
	this->schedule(CC_SCHEDULE_SELECTOR(GameScene::updateTimer), 1.0f);
	setupOnTouchBeginHandler();
	return true;
}


void GameScene::drawScene()
{
	for (auto& part : game->getBoard()->getPieces())
	{
		sprites.push_back(std::make_unique<PuzzlePartSprite>(part));
		auto& currentSprite = sprites.at(sprites.size() - 1);
		currentSprite->move(part.getCurrentPosition());
		this->addChild(currentSprite->getSprite());
	}
	setupTimer();
}

void GameScene::setupOnTouchBeginHandler()
{
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		for (auto& sprite : sprites)
		{
			auto bb = sprite->getSprite()->getBoundingBox();
			if (bb.containsPoint(touch->getLocation()))
			{
				game->getBoard()->move(*sprite->part);
				sprite->move(sprite->part->getCurrentPosition());
				if (game->getBoard()->isSolved())
				{
					auto scene = GameOverScene::createScene();
					Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
				}
				return true;
			}
		}
		return false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameScene::updateTimer(float dt)
{
	timer++;
	std::time_t seconds(timer);
	tm* p = gmtime(&seconds);
	std::stringstream ss;
	ss << p->tm_hour << ':' << p->tm_min << ':' << p->tm_sec;
	timerLabel->setString(ss.str());
}

void GameScene::setupTimer()
{
	timerSprite = Sprite::create();
	timerSprite->setPosition(visibleSize.width * 0.85F + origin.x, visibleSize.height / 2 + origin.y);
	timerLabel = Label::createWithSystemFont("0:0:0", MENU_PREFERED_FONT_RESOURCE, 42);
	timerSprite->addChild(timerLabel);
	this->addChild(timerSprite);
}
