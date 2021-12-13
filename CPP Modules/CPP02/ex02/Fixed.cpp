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

Fixed & Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	_fix = fixed.getRawBits();
	return (*this);
}

Fixed Fixed::operator+ (const Fixed &fixed)
{
	Fixed ret;

	ret.setRawBits(_fix + fixed._fix);
	return(ret);
}

Fixed Fixed::operator- (const Fixed &fixed)
{
	Fixed ret;

	ret.setRawBits(_fix - fixed._fix);
	return(ret);
}

Fixed Fixed::operator* (const Fixed &fixed)
{
	Fixed ret;

	ret.setRawBits((_fix * fixed._fix) >> 8);
	return(ret);
}

Fixed Fixed::operator/ (const Fixed &fixed)
{
	Fixed ret(this->toFloat() / fixed.toFloat());
	return(ret);
}

Fixed & Fixed::operator++ () //++a
{
	_fix++;
	return(*this);
}

Fixed Fixed::operator++ (int) //a++
{
	Fixed temp(*this);
	++*this;
	return(temp);
}

Fixed & Fixed::operator-- () //--a
{
	_fix--;
	return(*this);
}

Fixed Fixed::operator-- (int) //a--
{
	Fixed temp(*this);
	--*this;
	return(temp);
}

bool Fixed::operator== (const Fixed &fixed)
{
	return(_fix == fixed._fix && fract == fixed.fract);
}

bool Fixed::operator<= (const Fixed &fixed)
{
	return(_fix <= fixed._fix);
}

bool Fixed::operator< (const Fixed &fixed)
{
	return(_fix < fixed._fix);
}

bool Fixed::operator> (const Fixed &fixed)
{
	return(_fix > fixed._fix);
}

bool Fixed::operator>= (const Fixed &fixed)
{
	return(_fix >= fixed._fix);
}

bool Fixed::operator!= (const Fixed &fixed)
{
	return(_fix != fixed._fix || fract != fixed.fract);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	return(a._fix > b._fix ? a : b);
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	return(a._fix < b._fix ? a : b);
}

const Fixed & Fixed::max(Fixed const &a, Fixed const &b)
{
	return(a._fix > b._fix ? a : b);
}

const Fixed & Fixed::min(Fixed const &a, Fixed const &b)
{
	return(a._fix < b._fix ? a : b);
}