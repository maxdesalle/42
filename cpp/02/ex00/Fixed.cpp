/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:44:28 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/06 17:28:25 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixed_point_value(0)
{
	std::cout << "Default constructor called";
	std::cout << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called";
	std::cout << std::endl;
}

Fixed::Fixed(Fixed const &f)
{
	*this = f;
	std::cout << "Copy constructor called";
	std::cout << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &f)
{
	setRawBits(f.getRawBits());
	std::cout << "Assignation operator called";
	std::cout << std::endl;
	return (*this);
}

int		Fixed::getRawBits(void)	const
{
	std::cout << "getRawBits member function called";
	std::cout << std::endl;
	return (_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called";
	std::cout << std::endl;
	_fixed_point_value = raw;
}
