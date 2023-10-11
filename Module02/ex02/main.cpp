#include "Fixed.hpp"

int main(void)
{
	Fixed a;
		 
	Fixed  b( Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed  c( Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed  d( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed  e( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout  << "c:" << c << std::endl;
	std::cout  << "d:" << d << std::endl;
	std::cout  << "e:" << e << std::endl;
	std::cout  << "c = d + e:" << std::endl;
	c = d + e;
	std::cout << "c:" << c << std::endl;
	std::cout << "d:" << d << std::endl;
	std::cout << "e:" << e << std::endl;

	std::cout  << "e--" << std::endl;
	std::cout << e-- << std::endl;
	std::cout << e << std::endl;
	std::cout << --e << std::endl;
	std::cout << e << std::endl;

	std::cout << "max" << std::endl;
	std::cout << Fixed::max(e, c) << std::endl;
	std::cout << "min" << std::endl;
	std::cout << Fixed::min(e, c) << std::endl;
	return (0);
}