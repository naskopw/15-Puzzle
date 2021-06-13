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
	void createParts();
	Position emptyPos;
	std::vector<int> seedIds();
	bool isSolvable(const std::vector<int>& ids);
public:
	bool isSolved();
	std::vector<PuzzlePart>& getPieces();
	void move(PuzzlePart&);
	Gameboard();
};

