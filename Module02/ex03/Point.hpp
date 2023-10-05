#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	public :
		Point();
		Point(Fixed x, Fixed y);
		Point(const Point& origin);
		Point& operator=(const Point& other);
		Point::~Point ();

	private :
		Fixed const _x;
		Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif