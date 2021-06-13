#pragma once
#include <vector>
#include <utility>
#include <string>
#include "cocos2d.h"
#include "state/PuzzlePart.h"
#include "state/Position.h"
#include "state/PuzzlePart.h"

class PuzzlePartSprite
{
public:
	const float spriteCellSize = 152;
	const std::pair<int, int> spriteSheetSize = std::make_pair(4, 4);
	PuzzlePartSprite(const PuzzlePart& part);
	cocos2d::Sprite* getSprite();
	void move(const Position& pos);
	std::unique_ptr<PuzzlePart> part;
private:
	cocos2d::Sprite* sprite;
	float screenXPos(const Position& pos) const;
	float screenYPos(const Position& pos) const;
};