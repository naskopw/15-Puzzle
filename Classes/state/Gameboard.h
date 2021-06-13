#pragma once
#include "../Definitions.h"
#include <vector>
#include "PuzzlePart.h"
#include "Position.h"
class Gameboard
{
private:
	using IdCollection = const std::vector<int>;
	std::vector<PuzzlePart> parts;
	void createParts();
	Position emptyPos;
	std::vector<int> seedIds();
	bool isSolvable(const IdCollection& ids);
	int countInversions(const IdCollection& ids);
public:
	bool isSolved();
	std::vector<PuzzlePart>& getPieces();
	void move(PuzzlePart&);
	Gameboard();
};

