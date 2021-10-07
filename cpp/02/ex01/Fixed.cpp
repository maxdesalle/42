/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:44:28 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/07 12:24:50 by maxdesall        ###   ########.fr       */
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

Fixed::Fixed(const int f)
{
	std::cout << "Int constructor called";
	std::cout << std::endl;
	setRawBits(f << _fractional_bits);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called";
	std::cout << std::endl;
	setRawBits((int)roundf(f * (1 << _fractional_bits)));
}

Fixed::Fixed(Fixed const &f)
{
	std::cout << "Copy constructor called";
	std::cout << std::endl;
	*this = f;
}

Fixed			&Fixed::operator=(Fixed const &f)
{
	std::cout << "Assignation operator called";
	std::cout << std::endl;
	setRawBits(f.getRawBits());
	return (*this);
}

int				Fixed::toInt(void)		const
{
	return (getRawBits() >> _fractional_bits);
}

float			Fixed::toFloat(void)	const
{
	return ((float)(getRawBits()) / 256.0);
}

int				Fixed::getRawBits(void)	const
{
	return (_fixed_point_value);
}

void			Fixed::setRawBits(int const raw)
{
	_fixed_point_value = raw;
}

std::ostream	&operator<<(std::ostream &output, const Fixed &f)
{
	return (output << f.toFloat());
}
