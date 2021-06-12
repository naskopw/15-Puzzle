#pragma once
#include "../Definitions.h"
#include <array>
#include "PuzzlePart.h"
#include <vector>
#include "Position.h"
class Gameboard
{
private:
	std::vector<PuzzlePart> parts;
	std::array<std::array<int, TOTAL_COLUMNS>, TOTAL_ROWS> board;
	void createParts();
	Position emptyPos;
	std::vector<int> seedIds();
public:
	std::vector<PuzzlePart>& getPieces();
	void move(PuzzlePart&);
	Gameboard();
};

