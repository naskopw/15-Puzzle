#include "GameScene.h"
#include "GameOverScene.h"
#include "Definitions.h"

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
	setupOnTouchBeginHandler();
	return true;
}


void GameScene::drawScene()
{
	CCLOG("%d", sizeof(PuzzlePart));
	for (auto& part : game->getBoard()->getPieces())
	{
		sprites.push_back(std::make_unique<PuzzlePartSprite>(part));
		auto& currentSprite = sprites.at(sprites.size() - 1);
		currentSprite->move(part.getCurrentPosition());
		this->addChild(currentSprite->getSprite());
	}

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
