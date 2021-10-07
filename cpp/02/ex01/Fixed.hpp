/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:10:48 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/07 12:17:41 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:

		Fixed(void);
		~Fixed(void);

		Fixed(Fixed const &f);
		Fixed(int const value);
		Fixed(float const value);

		Fixed 	&operator=(Fixed const &f);

		int		toInt(void)			const;
		int		getRawBits(void)	const;
		float	toFloat(void)		const;

		void	setRawBits(int const raw);

	private:

		int					_fixed_point_value;
		static const int	_fractional_bits = 8;
};

std::ostream	&operator<<(std::ostream &output, const Fixed &f);

#endif
