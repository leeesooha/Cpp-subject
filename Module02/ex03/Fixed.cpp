#include "Fixed.hpp"

const int Fixed::_fractionBit = 8;

Fixed::Fixed () : _fixedPointNb(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& origin)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = origin;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
    {
        this->_fixedPointNb = other._fixedPointNb;
    }
	return (*this);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointNb);
}

void Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointNb = raw;
    return ;
}
//int
Fixed::Fixed (const int intNum) : _fixedPointNb(intNum)
{
    // std::cout << "Int constructor called" << std::endl;
    _fixedPointNb = intNum << _fractionBit;
}
//float
Fixed::Fixed (const float floatNum)
{
    // std::cout << "Float constructor called" << std::endl;
    _fixedPointNb = roundf(floatNum * (1 << _fractionBit));
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


//------------------operator overload----------------------------
bool Fixed::operator<(const Fixed& other)
{
    if (this->toInt() < other.toInt())
        return (true);
    return (false);
}

bool Fixed::operator>(const Fixed& other)
{
    if (this->toInt() > other.toInt())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& other)
{
    if (this->toInt() >= other.toInt())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& other)
{
    if (this->toInt() <= other.toInt())
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed& other)
{
    if (this->toInt() == other.toInt())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& other)
{
    if (this->toInt() != other.toInt())
        return (true);
    return (false);
}

//----------산술 연산자------------------
Fixed& Fixed::operator+(const Fixed& other)
{
    this->_fixedPointNb = (this->toInt() + other.toInt());
    return (*this);
}

int Fixed::operator-(const Fixed& other)
{
    return ((this->toInt() - other.toInt()));
}

Fixed& Fixed::operator*(const Fixed& other)
{
    this->_fixedPointNb = ((this->toFloat() * other.toFloat()) * 256);
    return (*this);
}

int Fixed::operator/(const Fixed& other)
{
    if (other.toInt() == 0)
        return (0);
    return ((this->toInt() / other.toInt()));
}
//prefix
Fixed& Fixed::operator++()
{
    Fixed copy(0.00390625f);
    this->_fixedPointNb = _fixedPointNb + copy.getRawBits();
    return (*this);
}

Fixed& Fixed::operator--()
{
    Fixed e(0.00390625f);
    this->_fixedPointNb = _fixedPointNb + e.getRawBits();
    return (*this);
}
//post
Fixed Fixed::operator++(int)
{
    Fixed e(0.00390625f);
    Fixed copy(*this);

    this->_fixedPointNb = _fixedPointNb + e.getRawBits();
    return (copy);
}

Fixed Fixed::operator--(int)
{
    Fixed e(0.00390625f);
    Fixed copy(*this);

    this->_fixedPointNb = _fixedPointNb - copy.getRawBits();
    return (*this);
}

Fixed&   Fixed::min(Fixed &left, Fixed &right)
{
    if (left <= right)
        return (left);
    else
        return (right);
    return (left);
}

Fixed&   Fixed::min(const Fixed &left, const Fixed &right)
{
   if (left.toInt() <= right.toInt())
    {
        return ((Fixed&)left);
    }
    else
    {
        return (Fixed&)right;
    }
}

Fixed&   Fixed::max(Fixed &left, Fixed &right)
{
    if (left <= right)
        return (left);
    else
        return (right);
    return (left);
}

Fixed&   Fixed::max(const Fixed &left, const Fixed &right)
{
   if (left.toInt() > right.toInt())
    {
        return (Fixed&)left;
    }
    else
    {
        return (Fixed&)right;
    }
}