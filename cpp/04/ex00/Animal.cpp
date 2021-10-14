/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:11:10 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 11:54:58 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	set_type("Animal");
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &ref)
{
	set_type("Animal");
	*this = ref;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal			&Animal::operator=(Animal const &ref)
{
	set_type(ref._type);
	std::cout << "Animal equal operator called" << std::endl;
	return (*this);
}

void			Animal::set_type(std::string type)
{
	_type = type;
}

std::string		Animal::get_type(void)	const
{
	return (_type);
}

void			Animal::makeSound(void)	const
{
	std::cout << "<< random animal sound >>" << std::endl;
}
