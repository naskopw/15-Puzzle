#pragma once
#include "Position.h"
#include<ostream>
class PuzzlePart
{
private:
	int id;
	Position position;
public:
	PuzzlePart(int id, Position p) : id(id), position(p) {}
	bool canMoveTo(Position emptyPos) const;
	Position getCurrentPosition() const;
	int getId() const;
	void move(Position emptyPos);
	void setPosition(Position emptyPos);
	friend std::ostream& operator<<(std::ostream& os, const PuzzlePart& p);
	friend bool operator< (const PuzzlePart& a, const PuzzlePart& b);
};

