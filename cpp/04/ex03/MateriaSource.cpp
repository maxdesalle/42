/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:31:46 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 19:46:09 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	int	i;

	for (i = 0; i < 4; i += 1)
		_inventory[i] = nullptr;
	std::cout << "MateriaSource was constructed!";
	std::cout << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	int	i;

	for (i = 0; i < 4; i += 1)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "MateriaSource was destructed!";
	std::cout << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &ref)
{
	int	i;

	for (i = 0; i < 4; i += 1)
	{
		if (ref._inventory[i])
			_inventory[i] = ref._inventory[i]->clone();
	}
	std::cout << "MateriaSource was copy constructed!";
	std::cout << std::endl;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &ref)
{
	int	i;

	for (i = 0; i < 4; i += 1)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (ref._inventory[i])
			_inventory[i] = ref._inventory[i]->clone();
	}
	return (*this);
}

void			MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	for (i = 0; _inventory[i] != nullptr && i < 4; i += 1) {}
	if (i == 4)
	{
		std::cout << "Nope, you can't learn more than 4 Materia";
		std::cout << std::endl;
		return ;
	}
	_inventory[i] = m;
	std::cout << m->getType() << " learned something!";
	std::cout << std::endl;
}

AMateria		*MateriaSource::createMateria(std::string const &type)
{
	int	i;
	int	indicator;

	indicator = 0;
	for (i = 0; _inventory[i] != nullptr && i < 4; i += 1)
	{
		if (_inventory[i]->getType() == type)
		{
			std::cout << _inventory[i]->getType() << " was created!";
			std::cout << std::endl;
			indicator = 1;
			break ;
		}
	}

	if (indicator == 1)
		return (_inventory[i])->clone();
	else
	{
		std::cout << type << " is unknown!";
		std::cout << std::endl;
		return (nullptr);
	}
}
