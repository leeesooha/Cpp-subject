#include "Point.hpp"

Point::Point () : _x(0), _y(0)
{

}

Point::Point (const float x, const float y) : _x(x), _y(y)
{

}

Point::Point (const Point& origin)
{
	*this = origin;
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		this->~Point();
		new(this) Point(other.getX(), other.getY());
		return (*this);
	}
	return (*this);
}

Point::~Point ()
{
}

float Point::getX() const
{
	return (this->_x.toFloat());
}

float Point::getY() const
{
	return (this->_y.toFloat());
}