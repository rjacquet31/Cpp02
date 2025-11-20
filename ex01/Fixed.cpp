#include "Fixed.hpp"
#include <cmath>

const int Fixed::_number_fractional_bits = 8;

Fixed::Fixed() : _fixed_number_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int number)
{
	_fixed_number_value = number << _number_fractional_bits;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float number)
{

	_fixed_number_value = static_cast<int>(number * (1 << _number_fractional_bits));
	std::cout << "Float constructor called" << std::endl;
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
	return (_fixed_number_value);
}

void Fixed::setRawBits(int const raw)
{
	_fixed_number_value = raw;
}

float Fixed::toFloat(void) const
{
    return roundf((float)_fixed_number_value / (float)(1 << _number_fractional_bits) * 10000.0f) / 10000.0f;
}

int Fixed::toInt(void) const
{
	return (_fixed_number_value >> _number_fractional_bits);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
    os << fixed.toFloat();
    return os;
}