#include "Fixed.hpp"

const int Fixed::_fractionBit = 8;

Fixed::Fixed () : _fixedPointNb(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& origin)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = origin;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
    {
        this->_fixedPointNb = other._fixedPointNb;
    }
	return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointNb);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointNb = raw;
    return ;
}

Fixed::Fixed (const int intNum) : _fixedPointNb(intNum)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float floatNum)
{
    std::cout << "Float constructor called" << std::endl;
    floatNum
    toFloat();
}

float Fixed::toFloat( void ) const
{
    return (0);
}

int Fixed::toInt( void ) const
{
    return (1);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    // std::cout << "operator overload called" << std::endl;
    // out << fixed.toFloat();
	return (out);
}