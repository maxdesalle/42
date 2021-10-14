/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:11:10 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 17:39:15 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog(void)
{
	set_type("WrongDog");
	std::cout << "WrongDog constructor called" << std::endl;
}

WrongDog::~WrongDog(void)
{
	std::cout << "WrongDog destructor called" << std::endl;
}

WrongDog::WrongDog(WrongDog const &ref)
{
	set_type("WrongDog");
	std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog				&WrongDog::operator=(WrongDog const &ref)
{
	set_type(ref._type);
	std::cout << "WrongDog equal operator called" << std::endl;
	return (*this);
}

void			WrongDog::set_type(std::string type)
{
	_type = type;
}

std::string		WrongDog::get_type(void)	const
{
	return (_type);
}

void			WrongDog::makeSound(void)	const
{
	std::cout << "<< random wrongdog sound >>" << std::endl;
}
