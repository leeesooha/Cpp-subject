#include "Fixed.hpp"
#include <iomanip>

int main(void)
{
	Fixed	a;
	Fixed	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << std::setw(30) << std::setfill('-') << "" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::setw(30) << std::setfill('-') << "" << std::endl;

	a = Fixed((float)10.11);
	b = Fixed( 5.05f ) * Fixed( 2 );
	Fixed	c( Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed	d( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed	e( Fixed( 5.05f ) + Fixed( 2 ) );
	std::cout  << "a:" << a << std::endl;
	std::cout  << "b:" << b << std::endl;
	std::cout  << "c:" << c << std::endl;
	std::cout  << "d:" << d << std::endl;
	std::cout  << "e:" << e << std::endl;
	std::cout  << "c = d + e  :  ";
	c = d + e;
	std::cout  << c.toFloat() << " = " << d.toFloat() << " + " << e.toFloat() << std::endl;
	
	std::cout  << "e--" << std::endl;
	std::cout << e-- << std::endl;
	std::cout << e << std::endl;
	std::cout << --e << std::endl;
	std::cout << e << std::endl;

	std::cout << "max(e, c)" << std::endl;
	std::cout << Fixed::max(e, c) << std::endl;
	std::cout << "min(e, c)" << std::endl;
	std::cout << Fixed::min(e, c) << std::endl;
	std::cout << std::setw(30) << std::setfill('-') << "" << std::endl;
	return (0);
}