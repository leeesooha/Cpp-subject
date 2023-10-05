#include "Point.hpp"

Point::Point () : _x(0), _y(0)
{

}

Point::Point (Fixed x, Fixed y) : _x(x), _y(y)
{

}

Point::Point (const Point& origin)
{
	// if (this != &origin)
	// {
	// 	;
	// }
    *this = origin;
}

Point& Point::operator=(const Point& other)
{
	return (*this);
}

Point::~Point ()
{
}