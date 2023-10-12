#include "Fixed.hpp"

const int Fixed::_fractionBit = 8;

Fixed::Fixed () : _fixedPointNb(0)
{
}

Fixed::Fixed (const Fixed& origin)
{
    *this = origin;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
        this->setRawBits(other._fixedPointNb);
	return (*this);
}

Fixed::~Fixed()
{
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

Fixed::Fixed (const int intNum) : _fixedPointNb(intNum)
{
    this->setRawBits(intNum << this->_fractionBit);
}

Fixed::Fixed (const float floatNum)
{
    this->setRawBits(roundf(floatNum * (1 << this->_fractionBit)));
}

float Fixed::toFloat( void ) const
{
    return ((float)this->_fixedPointNb / (1 << this->_fractionBit));
}

int Fixed::toInt( void ) const
{
    return (this->_fixedPointNb >> this->_fractionBit);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
	return (out);
}


bool Fixed::operator<(const Fixed& other) const
{
    if (this->_fixedPointNb < other._fixedPointNb)
        return (true);
    return (false);
}

bool Fixed::operator>(const Fixed& other) const
{
    if (this->_fixedPointNb > other._fixedPointNb)
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& other) const
{
    if (this->_fixedPointNb >= other._fixedPointNb)
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& other) const
{
    if (this->_fixedPointNb <= other._fixedPointNb)
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed& other) const
{
    if (this->_fixedPointNb == other._fixedPointNb)
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& other) const
{
    if (this->_fixedPointNb != other._fixedPointNb)
        return (true);
    return (false);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
    this->setRawBits(++this->_fixedPointNb);
    return (*this);
}

Fixed& Fixed::operator--()
{
    this->setRawBits(--this->_fixedPointNb);
    return (*this);
}

const Fixed Fixed::operator++(int)
{
    Fixed copy(*this);

    this->_fixedPointNb++;
    return (copy);
}

const Fixed Fixed::operator--(int)
{
    Fixed copy(*this);

    this->_fixedPointNb--;
    return (copy);
}

Fixed&   Fixed::min(Fixed &left, Fixed &right)
{
    if (left > right)
        return (right);
    else
        return (left);
}

const Fixed&   Fixed::min(const Fixed &left, const Fixed &right)
{
    if (left > right)
        return (right);
    else
        return (left);
}

Fixed&   Fixed::max(Fixed &left, Fixed &right)
{
    if (left < right)
        return (right);
    else
        return (left);
}

const Fixed&   Fixed::max(const Fixed &left, const Fixed &right)
{
    if (left < right)
        return (right);
    else
        return (left);
}