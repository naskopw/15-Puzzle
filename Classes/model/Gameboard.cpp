#include "Gameboard.h"
#include <iostream>
#include<numeric>
#include <algorithm>
#include<chrono>
#include <random>
#include<stdexcept>

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
	std::shuffle(ids.begin(), ids.end(), std::default_random_engine(static_cast<unsigned int>(seed)));
	
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
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Gameboard::Gameboard() : emptyPos(TOTAL_COLUMNS - 1, TOTAL_ROWS - 1)
{
	parts.reserve(TOTAL_PARTS);
	createParts();
}
