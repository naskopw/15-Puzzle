#include "Gameboard.h"
#include <iostream>
#include<numeric>
#include <algorithm>
#include<chrono>
#include <random>
#include<stdexcept>
#include "../cocos2d.h"

void Gameboard::createParts()
{
	auto idPool = seedIds();
	auto currentId = idPool.cbegin();
	for (int row = 0; row < TOTAL_ROWS; row++) {
		for (int col = 0; col < TOTAL_COLUMNS; col++) {
			if (col != TOTAL_COLUMNS - 1 || row != TOTAL_ROWS - 1)
			{
				parts.push_back(PuzzlePart(*currentId, Position(col, row)));
				currentId++;
			}
		}
	}
}

std::vector<int> Gameboard::seedIds()
{
	std::vector<int> ids(TOTAL_PARTS);
	std::iota(ids.begin(), ids.end(), 1);
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	do
	{
		std::shuffle(ids.begin(), ids.end(), std::default_random_engine(static_cast<unsigned int>(seed)));
		CCLOG("%s", isSolvable(ids) ? "true" : "false");
	} while (!isSolvable(ids));

	return ids;
}

std::vector<PuzzlePart>& Gameboard::getPieces()
{

	std::cout << "WARNING: Remove this function and includes: " << __FUNCTION__ << std::endl;
	return parts;
}


void Gameboard::move(PuzzlePart& part)
{
	try {
		Position newEmptyPos(part.getCurrentPosition());
		part.move(emptyPos);
		emptyPos = newEmptyPos;
		for (auto& p : parts) {
			if (p.getId() == part.getId())
			{
				p.setPosition(part.getCurrentPosition());
			}
		}
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Gameboard::Gameboard() : emptyPos(TOTAL_ROWS - 1, TOTAL_COLUMNS - 1)
{
	parts.reserve(TOTAL_PARTS);
	createParts();
}


bool Gameboard::isSolved()
{
	std::sort(parts.begin(), parts.end());
	for (auto& part : parts)
	{

		float correctXPos = (part.getId() - 1) % TOTAL_COLUMNS;
		float correctYPos = (TOTAL_ROWS-1)-(part.getId() - 1) / TOTAL_ROWS;
		CCLOG("%d {%d, %d}", part.getId(), part.getCurrentPosition().x, part.getCurrentPosition().y);

		if (part.getCurrentPosition().x != correctXPos || part.getCurrentPosition().y != correctYPos)
		{
			return false;
		}
	}
	return (emptyPos.x == TOTAL_COLUMNS - 1 && emptyPos.y == 0);

}
bool Gameboard::isSolvable(const std::vector<int>& ids)
{
	int inversion;
	int totalInversion = 0;

	for (int i = 0; i < ids.size() - 1; i++) {
		inversion = 0;
		for (int j = i + 1; j < parts.size(); j++) {
			if (ids[i] > ids[j]) {
				inversion++;
			}
		}
		totalInversion += inversion;
	}

	if (TOTAL_COLUMNS % 2 != 0) {
		return totalInversion % 2 == 0;
	}
	else {
		if ((TOTAL_ROWS - emptyPos.y) % 2 == 0) {
			return totalInversion % 2 != 0;
		}
		else {
			return totalInversion % 2 == 0;
		}
	}
	return false;
}
