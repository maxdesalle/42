/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:22:21 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/19 10:42:36 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): _type("ice")
{
	std::cout << _type << " successfully constructed!";
	std::cout << std::endl;
}

Ice::~Ice(void)
{
	std::cout << _type << " successfully destroyed!";
	std::cout << std::endl;
}

Ice::Ice(Ice const &ref): _type(ref.getType())
{
	std::cout << _type << " successfully copy constructed";
	std::cout << std::endl;
}

Ice	&Ice::operator=(Ice const &ref)
{
	std::cout << "successfully assigned " << ref.getType();
	std::cout << std::endl;
	return (*this);
}

std::string const	&Ice::getType(void)	const
{
	return (_type);
}

Ice					*Ice::clone(void)	const
{
	Ice	*ptr = new Ice;
	return (ptr);
}

void				Ice::use(ICharacter &target)
{
	std::cout << " * shoots an ice bolt at " << target.getName() << " *";
	std::cout << std::endl;
}
