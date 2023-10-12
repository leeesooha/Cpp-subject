#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a(2,2);
	Point b(5,6);
	Point c(6,4);

	Point p1(-1,1);
	Point p2(2,6);
	Point p3(4,4);
	Point p4(5,2);
	Point p5(0,0);

	if (bsp(a, b, c, p3) == true)
		std::cout << "OK!!!" << std::endl;
	else
		std::cout << "No inner" << std::endl;
	return (0);
}