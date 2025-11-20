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
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif