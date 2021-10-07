/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:44:28 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/07 15:18:32 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixed_point_value(0)
{
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const int f)
{
	setRawBits(f << _fractional_bits);
}

Fixed::Fixed(const float f)
{
	setRawBits((int)roundf(f * (1 << _fractional_bits)));
}

Fixed::Fixed(Fixed const &f)
{
	*this = f;
}

int 			Fixed::operator>(Fixed const &f)	const
{
	return (getRawBits() > f.getRawBits());
}

int 			Fixed::operator<(Fixed const &f)	const
{
	return (getRawBits() < f.getRawBits());
}

int 			Fixed::operator>=(Fixed const &f)	const
{
	return (getRawBits() >= f.getRawBits());
}

int 			Fixed::operator<=(Fixed const &f)	const
{
	return (getRawBits() <= f.getRawBits());
}

int 			Fixed::operator==(Fixed const &f)	const
{
	return (getRawBits() == f.getRawBits());
}

int 			Fixed::operator!=(Fixed const &f)	const
{
	return (getRawBits() != f.getRawBits());
}

Fixed 			Fixed::operator*(Fixed const &f)	const
{
	Fixed	value(toFloat() * f.toFloat());
	return (value);
}

Fixed 			Fixed::operator/(Fixed const &f)	const
{
	Fixed	value(toFloat() / f.toFloat());
	return (value);
}

Fixed 			Fixed::operator+(Fixed const &f)	const
{
	Fixed	value(toFloat() + f.toFloat());
	return (value);
}

Fixed 			Fixed::operator-(Fixed const &f)	const
{
	Fixed	value(toFloat() - f.toFloat());
	return (value);
}

Fixed			&Fixed::operator=(Fixed const &f)
{
	setRawBits(f.getRawBits());
	return (*this);
}

Fixed			&Fixed::operator++(void)
{
	_fixed_point_value += 1;
	return (*this);
}

Fixed			&Fixed::operator--(void)
{
	_fixed_point_value -= 1;
	return (*this);
}

Fixed			Fixed::operator++(int)
{
	Fixed	tmp = *this;

	_fixed_point_value += 1;
	return (tmp);
}

Fixed			Fixed::operator--(int)
{
	Fixed	tmp = *this;

	_fixed_point_value -= 1;
	return (tmp);
}

Fixed			&Fixed::min(Fixed &x, Fixed&y)
{
	if (x.getRawBits() > y.getRawBits())
		return (y);
	else
		return (x);
}

Fixed			&Fixed::max(Fixed &x, Fixed&y)
{
	if (x.getRawBits() > y.getRawBits())
		return (x);
	else
		return (y);
}

const Fixed		&Fixed::min(Fixed const &x, Fixed const &y)
{
	if (x.getRawBits() > y.getRawBits())
		return (y);
	else
		return (x);
}

const Fixed		&Fixed::max(Fixed const &x, Fixed const &y)
{
	if (x.getRawBits() > y.getRawBits())
		return (x);
	else
		return (y);
}

int				Fixed::toInt(void)			const
{
	return (getRawBits() >> _fractional_bits);
}

float			Fixed::toFloat(void)		const
{
	return ((float)(getRawBits()) / 256.0);
}

int				Fixed::getRawBits(void)		const
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
