#pragma once
#include "Gameboard.h"
#include "PuzzlePart.h"
#include <memory>
class Game 
{
private:
	std::unique_ptr<Gameboard> board;
public:
	Game() = default;
	void start();
	const std::unique_ptr<Gameboard>& getBoard();
};
