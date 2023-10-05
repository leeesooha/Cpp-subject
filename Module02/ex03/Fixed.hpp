#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public :
		Fixed();
		Fixed(const int intNum);
		Fixed(const float floatNum);
		Fixed(const Fixed& origin);
		Fixed& operator=(const Fixed& other);
		bool operator<(const Fixed& other);
		bool operator>(const Fixed& other);
		bool operator>=(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator!=(const Fixed& other);
		Fixed& operator+(const Fixed& other);
		int operator-(const Fixed& other);
		Fixed& operator*(const Fixed& other);
		int operator/(const Fixed& other);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static Fixed&   min(Fixed &left, Fixed &right);
        static Fixed&   min(const Fixed &left, const Fixed &right);
        static Fixed&   max(Fixed &left, Fixed &right);
        static Fixed&   max(const Fixed &left, const Fixed &right);

	private :
		int _fixedPointNb;
		static const int _fractionBit;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif