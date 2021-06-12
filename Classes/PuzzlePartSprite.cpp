#include "PuzzlePartSprite.h"
#include "Definitions.h"

USING_NS_CC;

PuzzlePartSprite::PuzzlePartSprite(const PuzzlePart& part) :
	part(std::make_unique<PuzzlePart>(part)),
	sprite(cocos2d::Sprite::create(resourceName))
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	CCLOG("%d, {%d,%d}", part.getId(), part.getCurrentPosition().x, part.getCurrentPosition().y);
	int spriteXPos = (this->part->getId() - 1) % spriteSheetSize.first * spriteCellSize;
	int spriteYPos = (this->part->getId() - 1) / spriteSheetSize.first * spriteCellSize;
	sprite->setTextureRect(Rect(spriteXPos, spriteYPos, spriteCellSize, spriteCellSize));
}

cocos2d::Sprite* PuzzlePartSprite::getSprite()
{
	return sprite;
}

float PuzzlePartSprite::screenXPos(const Position& pos) const
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	float margin = visibleSize.width * (1.0f - BOARD_SCALE_SIZE) + origin.x;
	return margin+pos.x*spriteCellSize;
}

float PuzzlePartSprite::screenYPos(const Position& pos) const
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	float margin = visibleSize.height * (1 - BOARD_SCALE_SIZE) + origin.y;
	return margin + pos.y * spriteCellSize;
}

void PuzzlePartSprite::move(const Position& pos)
{
	//sprite->setPosition(screenXPos(pos), screenYPos(pos));
	auto action = MoveTo::create(ANIMATION_DURATION, Point(screenXPos(pos), screenYPos(pos)));
	sprite->runAction(action);
}
