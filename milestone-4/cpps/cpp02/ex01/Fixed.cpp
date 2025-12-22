#include "Fixed.hpp"

Fixed::Fixed() : _raw_bits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) : _raw_bits(value << _fraction)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value) : _raw_bits(roundf(value * (1 << _fraction)))
{
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other) : _raw_bits(other._raw_bits)
{
	std::cout << "Copy constructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
		return *this;

	this->_raw_bits = other._raw_bits;

	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return _raw_bits;
}

void	Fixed::setRawBits(int const raw)
{
	_raw_bits = raw;
}


float	Fixed::toFloat(void) const
{
	return static_cast<float>(_raw_bits) / (1 << _fraction);
}

int	Fixed::toInt(void) const
{
	return _raw_bits >> _fraction;
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
		return os;
}

bool	Fixed::operator>(const Fixed& other) const
{
	return this->_raw_bits > other._raw_bits;
}

bool	Fixed::operator<(const Fixed& other) const
{
	return this->_raw_bits < other._raw_bits;
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return this->_raw_bits >= other._raw_bits;
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return this->_raw_bits <= other._raw_bits;
}

bool	Fixed::operator==(const Fixed& other) const
{
	return this->_raw_bits == other._raw_bits;
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return this->_raw_bits != other._raw_bits;
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_raw_bits + other._raw_bits);
	return result;
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_raw_bits - other._raw_bits);
	return result;
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->_raw_bits * other._raw_bits) / (1 << _fraction));
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->_raw_bits / other._raw_bits) * (1 << _fraction));
	return result;
}