#include <numeric>
#include <algorithm>
#include <chrono>
#include <random>
#include "Gameboard.h"
#include "InvalidMoveException.h"

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
	} while (!isSolvable(ids));

	return ids;
}

std::vector<PuzzlePart>& Gameboard::getPieces()
{
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
	catch (const InvalidMoveException&)
	{
		//Invalid move, nothing happens
	}
}

Gameboard::Gameboard() : emptyPos(TOTAL_ROWS - 1, TOTAL_COLUMNS - 1)
{
	parts.reserve(TOTAL_PARTS);
	createParts();
}


bool Gameboard::isSolved()
{
	for (auto& part : parts)
	{
		float correctXPos = static_cast<float>((part.getId() - 1) % TOTAL_COLUMNS);
		float correctYPos = static_cast<float>((part.getId() - 1) / TOTAL_ROWS);
		if (part.getCurrentPosition().x != correctXPos || part.getCurrentPosition().y != correctYPos)
		{
			return false;
		}
	}
	return (emptyPos.x == TOTAL_COLUMNS - 1 && emptyPos.y == TOTAL_ROWS - 1);

}
bool Gameboard::isSolvable(const IdCollection& ids)
{
	int totalInversions = countInversions(ids);
	if (TOTAL_COLUMNS % 2 != 0) {
		return totalInversions % 2 == 0;
	}
	if ((TOTAL_ROWS - emptyPos.y) % 2 == 0) {
		return totalInversions % 2 != 0;
	}
	else {
		return totalInversions % 2 == 0;
	}
	return false;
}

int Gameboard::countInversions(const IdCollection& ids)
{
	int totalInversions = 0;
	for (std::size_t row = 0; row < ids.size() - 1; row++) {
		int inversion = 0;
		for (std::size_t col = row + 1; col < ids.size(); col++) {
			if (ids[row] > ids[col]) {
				inversion++;
			}
		}
		totalInversions += inversion;
	}
	return totalInversions;
}
