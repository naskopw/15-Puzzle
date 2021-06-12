#pragma once
#include<utility>
#include<string>
#include "cocos2d.h"
#include "model/PuzzlePart.h"
#include "model/Position.h"
#include "model/PuzzlePart.h"
#include <external/recast/DetourCrowd/DetourObstacleAvoidance.h>
#include "model/PuzzlePart.h"

class PuzzlePartSprite
{
public:
	const int spriteCellSize = 152;
	const std::pair<int, int> spriteSheetSize = std::make_pair(3, 5);
	const std::string resourceName = "parts.png";
	PuzzlePartSprite(const PuzzlePart& part);
	cocos2d::Sprite* getSprite();
	void move(const Position& pos);
	std::unique_ptr<PuzzlePart> part;
private:
	cocos2d::Sprite* sprite;
	float screenXPos(const Position& pos) const;
	float screenYPos(const Position& pos) const;
};