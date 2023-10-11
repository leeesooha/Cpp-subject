#include "Point.hpp"

bool checkSignEquality(Fixed const num1, Fixed const num2)
{
	Fixed zero;

	if (num1 > zero && num2 > zero)
		return (true);
	else if (num1 < zero && num2 < zero)
		return (true);
	return (false);
}

Fixed outer_product(Point const a, Point const b)
{
	Fixed k;
	k = (a.getX() * b.getY()) - (a.getY() * b.getX());
	std::cout << k.toFloat() << std::endl;

	return (Fixed(a.getX() * b.getY()) - (a.getY() * b.getX()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed k;

	Point vec_ab(b.getX() - a.getX(), b.getY() - a.getY());
	Point vec_ac(c.getX() - a.getX(), c.getY() - a.getY());
	Point vec_ba(a.getX() - b.getX(), a.getY() - b.getY());
	Point vec_bc(c.getX() - b.getX(), c.getY() - b.getY());
	Point vec_ca(a.getX() - c.getX(), a.getY() - c.getY());
	Point vec_cb(b.getX() - c.getX(), b.getY() - c.getY());
	Point vec_ap(point.getX() - a.getX(), point.getY() - a.getY());
	Point vec_bp(point.getX() - b.getX(), point.getY() - b.getY());
	Point vec_cp(point.getX() - c.getX(), point.getY() - c.getY());


	if (checkSignEquality(outer_product(vec_ab, vec_ac), outer_product(vec_ab, vec_ap)) == false)
		return (false);
	else if (checkSignEquality(outer_product(vec_ba, vec_bc), outer_product(vec_ba, vec_bp)) == false)
		return (false);
	else if (checkSignEquality(outer_product(vec_ca, vec_cb), outer_product(vec_ca, vec_cp)) == false)
		return (false);
	return (true);
}
