/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:11:10 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 17:39:09 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	set_type("WrongCat");
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &ref)
{
	set_type("WrongCat");
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat		&WrongCat::operator=(WrongCat const &ref)
{
	set_type(ref._type);
	std::cout << "WrongCat equal operator called" << std::endl;
	return (*this);
}

void			WrongCat::set_type(std::string type)
{
	_type = type;
}

std::string		WrongCat::get_type(void)	const
{
	return (_type);
}

void			WrongCat::makeSound(void)	const
{
	std::cout << "<< random wrongcat sound >>" << std::endl;
}
