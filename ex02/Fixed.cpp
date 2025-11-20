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
    return (float)_fixed_number_value / (float)(1 << _number_fractional_bits);
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);	
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);	
}

bool Fixed::operator>(const Fixed &other) const
{
	return (_fixed_number_value > other._fixed_number_value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_fixed_number_value < other._fixed_number_value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_fixed_number_value >= other._fixed_number_value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_fixed_number_value <= other._fixed_number_value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_fixed_number_value == other._fixed_number_value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_fixed_number_value != other._fixed_number_value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(toFloat() / other.toFloat()));
}

Fixed Fixed::operator++(void)
{
	_fixed_number_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed Fixed::operator--(void)
{
	_fixed_number_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}
