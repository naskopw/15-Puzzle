#include "PuzzlePart.h"
#include "InvalidMoveException.h"

bool operator<(const PuzzlePart& a, const PuzzlePart& b)
{
	return a.getId() < b.getId();
}

bool PuzzlePart::canMoveTo(Position emptyPos) const
{
	return (std::abs(position.x - emptyPos.x) <= 1) && !(std::abs(position.y - emptyPos.y) >= 1) ||
		(!(std::abs(position.x - emptyPos.x) >= 1) && (std::abs(position.y - emptyPos.y) <= 1));
}

Position PuzzlePart::getCurrentPosition() const
{
	return position;
}

int PuzzlePart::getId() const
{
	return id;
}

void PuzzlePart::move(Position newPos)
{
	if (canMoveTo(newPos)) {
		position = newPos;
	}
	else
	{
		throw InvalidMoveException();
	}
}

void PuzzlePart::setPosition(Position emptyPos)
{
	position = emptyPos;
}
