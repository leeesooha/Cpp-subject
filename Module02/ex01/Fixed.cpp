#include "Fixed.hpp"

const int Fixed::_fractionBit = 8;

Fixed::Fixed () : _fixedPointNb(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
        setRawBits(other._fixedPointNb);
	return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return (this->_fixedPointNb);
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedPointNb = raw;
    return ;
}

Fixed::Fixed (const int intNum) : _fixedPointNb(intNum << _fractionBit)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float floatNum) : _fixedPointNb(roundf(floatNum * (1 << _fractionBit)))
{
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    return ((float)_fixedPointNb / (1 << _fractionBit));
}

int Fixed::toInt( void ) const
{
    return (_fixedPointNb >> _fractionBit);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
	return (out);
}