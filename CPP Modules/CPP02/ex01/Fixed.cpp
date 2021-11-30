#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fix = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fix = (value << fract);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fix = roundf(value * (1 << fract));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	_fix = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return(this->_fix);
}

void Fixed::setRawBits( int const fix)
{
	this->_fix = fix;
}

int Fixed::toInt(void)const
{
	return(_fix >> fract);
}

float Fixed::toFloat(void)const
{
	return  ((float)_fix / (1 << fract));
}

std::ostream& operator<<(std::ostream & os, Fixed const & i)
{
	return(os << (i.toFloat()));
}
