#include "PuzzlePartSprite.h"
#include "Definitions.h"

USING_NS_CC;

PuzzlePartSprite::PuzzlePartSprite(const PuzzlePart& part) :
	part(std::make_unique<PuzzlePart>(part)),
	sprite(cocos2d::Sprite::create(PARTS_SPRITE_SHEET_RESOURCE))
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	float spriteXPos = (this->part->getId() - 1) % spriteSheetSize.first * spriteCellSize;
	float spriteYPos = (this->part->getId() - 1) / spriteSheetSize.first * spriteCellSize;
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
	float margin = (visibleSize.width - TOTAL_COLUMNS*spriteCellSize + origin.x)/2;
	return margin + (static_cast<float>(pos.x)+0.5F) * spriteCellSize;
}

float PuzzlePartSprite::screenYPos(const Position& pos) const
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	float margin = visibleSize.height * BOARD_SCALE_SIZE + origin.y;
	return margin - (static_cast<float>(pos.y)+0.5F) * spriteCellSize;
}

void PuzzlePartSprite::move(const Position& pos)
{
	sprite->setPosition(Point(screenXPos(pos), screenYPos(pos)));
}
