#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public :
		Fixed();
		Fixed(const int intNum);
		Fixed(const float floatNum);
		Fixed(const Fixed& origin);
		Fixed& operator=(const Fixed& other);
		bool operator<(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		Fixed& operator++();
		const Fixed operator++(int);
		Fixed& operator--();
		const Fixed operator--(int);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static Fixed&   min(Fixed &left, Fixed &right);
        static const Fixed&   min(const Fixed &left, const Fixed &right);
        static Fixed&   max(Fixed &left, Fixed &right);
        static const Fixed&   max(const Fixed &left, const Fixed &right);

	private :
		int _fixedPointNb;
		static const int _fractionBit;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif