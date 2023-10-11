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
        this->setRawBits(other._fixedPointNb);
        // this->_fixedPointNb = other._fixedPointNb;
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
    // _fixedPointNb = intNum << _fractionBit;
    this->setRawBits(intNum << this->_fractionBit);
}
//float
Fixed::Fixed (const float floatNum)
{
    // std::cout << "Float constructor called" << std::endl;
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


//------------------operator overload----------------------------
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

//----------산술 연산자------------------
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
//prefix
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
//post
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