/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:22:21 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 19:46:40 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): _type("Cure")
{
	std::cout << _type << "successfully constructed!";
	std::cout << std::endl;
}

Cure::~Cure(void)
{
	std::cout << _type << "successfully destroyed!";
	std::cout << std::endl;
}

Cure::Cure(Cure const &ref): _type(ref.getType())
{
	std::cout << _type << "successfully copy constructed";
	std::cout << std::endl;
}

Cure	&Cure::operator=(Cure const &ref)
{
	std::cout << "successfully assigned " << ref.getType();
	std::cout << std::endl;
	return (*this);
}

std::string const	&Cure::getType(void)	const
{
	return (_type);
}

Cure					*Cure::clone(void)	const
{
	Cure	*ptr = new Cure;
	return (ptr);
}

void				Cure::use(ICharacter &target)
{
	std::cout << " * heals " << target.getName() << "'s wounds *";
	std::cout << std::endl;
}
