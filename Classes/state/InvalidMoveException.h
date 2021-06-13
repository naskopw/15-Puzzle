#pragma once
#include <stdexcept>

class InvalidMoveException : public std::runtime_error
{
	std::string what_message;
public:
	InvalidMoveException(const std::string& what = "") : std::runtime_error(what) {}
};