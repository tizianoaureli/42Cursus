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
	int toInt(void) const;
	float toFloat(void) const;
	int	getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream & os, Fixed const & i);

#endif