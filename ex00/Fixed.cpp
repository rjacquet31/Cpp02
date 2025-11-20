#include "Fixed.hpp"

const int Fixed::_number_fractional_bits = 8;

Fixed::Fixed() : _fixed_number_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment constructor called\n";
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (_fixed_number_value);
}

void Fixed::setRawBits(int const raw)
{
	_fixed_number_value = raw;
}