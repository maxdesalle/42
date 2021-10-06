/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:10:48 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/06 17:10:21 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:

		Fixed(void);
		~Fixed(void);

		Fixed(Fixed const &f);

		Fixed 	&operator=(Fixed const &f);

		int		getRawBits(void)	const;
		void	setRawBits(int const raw);

	private:

		int					_fixed_point_value;
		static const int	_fractional_bits = 8;
};

#endif
