/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:23:52 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 19:26:23 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria constructed";
	std::cout << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << "AMateria constructed";
	std::cout << std::endl;
}

AMateria::AMateria(AMateria const &ref): _type(ref._type)
{
	std::cout << "AMateria copy constructed";
	std::cout << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructed";
	std::cout << std::endl;
}

std::string	const	&AMateria::getType(void)	const
{
	return (_type);
}

void		AMateria::use(ICharacter &target)
{
	std::cout << "AMateria used for character ";
	std::cout << target.getName();
	std::cout << std::endl;
}
