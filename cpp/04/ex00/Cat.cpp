/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:11:10 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 17:38:51 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	set_type("Cat");
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &ref)
{
	set_type("Cat");
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat				&Cat::operator=(Cat const &ref)
{
	set_type(ref._type);
	std::cout << "Cat equal operator called" << std::endl;
	return (*this);
}

void			Cat::set_type(std::string type)
{
	_type = type;
}

std::string		Cat::get_type(void)	const
{
	return (_type);
}

void			Cat::makeSound(void)	const
{
	std::cout << "<< random cat sound >>" << std::endl;
}
