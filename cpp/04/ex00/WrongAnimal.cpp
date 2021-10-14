/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:11:10 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 17:39:03 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	set_type("WrongAnimal");
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &ref)
{
	set_type("WrongAnimal");
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal		&WrongAnimal::operator=(WrongAnimal const &ref)
{
	set_type(ref._type);
	std::cout << "WrongAnimal equal operator called" << std::endl;
	return (*this);
}

void			WrongAnimal::set_type(std::string type)
{
	_type = type;
}

std::string		WrongAnimal::get_type(void)	const
{
	return (_type);
}

void			WrongAnimal::makeSound(void)	const
{
	std::cout << "<< random wronganimal sound >>" << std::endl;
}
