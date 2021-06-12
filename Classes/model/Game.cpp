#include "Game.h"

void Game::start()
{
	board = std::make_unique<Gameboard>();
}

bool Game::isSolved()
{
	return false;
}

const std::unique_ptr<Gameboard>& Game::getBoard()
{
	return board;
}
