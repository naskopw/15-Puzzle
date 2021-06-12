#include "PuzzlePart.h"
#include<stdexcept>
std::ostream& operator<<(std::ostream& os, const PuzzlePart& p)
{
	os << p.id << " {" << p.position.x << "," << p.position.y << "}";
	return os;
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
	else {
		throw std::runtime_error("Error while moving");
	}
}
