#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fix;
	static const int fract = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed& operator= (const Fixed &fixed);
	Fixed operator+ (const Fixed &fixed);
	Fixed operator- (const Fixed &fixed);
	Fixed operator* (const Fixed &fixed);
	Fixed operator/ (const Fixed &fixed);
	Fixed& operator++ (void);
	Fixed operator++ (int);
	Fixed& operator-- (void);
	Fixed operator-- (int);
	bool operator== (const Fixed &fixed);
	bool operator<= (const Fixed &fixed);
	bool operator< (const Fixed &fixed);
	bool operator>= (const Fixed &fixed);
	bool operator> (const Fixed &fixed);
	bool operator!= (const Fixed &fixed);
	static Fixed & max(Fixed &a, Fixed &b);
	static Fixed & min(Fixed &a, Fixed &b);
	static const Fixed & max(Fixed const &a, Fixed const &b);
	static const Fixed & min(Fixed const &a, Fixed const &b);	
	int toInt(void) const;
	float toFloat(void) const;
	int	getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream & os, Fixed const & i);

#endif