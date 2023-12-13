#include "RPN.hpp"

RPN::RPN()
{
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::~RPN()
{
}
