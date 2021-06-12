#include "GameScene.h"
#include "Definitions.h"
#include "model/Gameboard.h"
#include "PuzzlePartSprite.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
	return GameScene::create();
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	boardSizeX = visibleSize.width * BOARD_SCALE_SIZE;
	boardSizeY = visibleSize.height * BOARD_SCALE_SIZE;
	board = std::make_unique<Gameboard>();
	
	drawPuzzleParts();

	return true;
}


void GameScene::drawPuzzleParts()
{
	int pieceWidth = boardSizeX / TOTAL_COLUMNS;
	int pieceHeight = boardSizeY / TOTAL_ROWS;
	for (auto& part : board->getPieces())
	{
		parts.push_back(std::make_unique<PuzzlePartSprite>(part));
		auto& currentSprite = parts.at(parts.size() - 1);
		currentSprite->move(part.getCurrentPosition());
		this->addChild(currentSprite->getSprite());
	}
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		cocos2d::Vec2 p = touch->getLocation();

		for (auto& part : parts)
		{
			auto bb = part->getSprite()->getBoundingBox();
			if (bb.containsPoint(p))
			{
				board->move(*part->part);
				part->move(part->part->getCurrentPosition());
				return true;
			}
		}
		return false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}
