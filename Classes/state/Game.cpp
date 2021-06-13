#include "Game.h"

void Game::start()
{
	board = std::make_unique<Gameboard>();
}


const std::unique_ptr<Gameboard>& Game::getBoard()
{
	return board;
}