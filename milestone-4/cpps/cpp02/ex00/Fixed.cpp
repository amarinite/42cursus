#include "Fixed.hpp"

Fixed::Fixed() : raw_bits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other) : raw_bits(other.raw_bits)
{
	std::cout << "Copy constructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
		return *this;

	this->raw_bits = other.raw_bits;

	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return raw_bits;
}

void	Fixed::setRawBits(int const raw)
{
	raw_bits = raw;
}
