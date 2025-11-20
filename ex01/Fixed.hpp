#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int 				_fixed_number_value;
		static const int	_number_fractional_bits;

	public:
		Fixed();
		~Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &os,  Fixed const &fixed);

#endif