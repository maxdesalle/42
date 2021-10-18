/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:26:08 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 19:27:10 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name): _name(name)
{
	int	i;

	for (i = 0; i < 4; i += 1)
		_inventory[i] = nullptr;
	std::cout << "Character " << _name << " was constructed!";
	std::cout << std::endl;
}

Character::~Character(void)
{
	int	i;

	for (i = 0; i < 4; i += 1)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "Character " << _name << " was destructed!";
	std::cout << std::endl;
}

Character::Character(Character const &ref): _name(ref.getName() + "_copy")
{
	int	i;

	for (i = 0; i < 4; i += 1)
	{
		if (ref._inventory[i])
			_inventory[i] = ref._inventory[i]->clone();
	}
	std::cout << "Character " << _name << " was copy constructed!";
	std::cout << std::endl;
}

Character	&Character::operator=(Character const &ref)
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

void		Character::equip(AMateria *m)
{
	int	i;

	if (m == nullptr)
	{
		std::cout << "Nope, you have to equip SOMETHING!";
		std::cout << std::endl;
		return ;
	}
	for (i = 0; _inventory[i] != nullptr && i < 4; i += 1) {}
	if (i == 4)
	{
		std::cout << "Nope, you can't equip more than 4 Materia";
		std::cout << std::endl;
		return ;
	}
	_inventory[i] = m;
	std::cout << _name << " equipped in slot " << i << " Materia " << m->getType();
	std::cout << std::endl;
}

void		Character::unequip(int idx)
{
	if (idx < 0 || idx > 4 || _inventory[idx] == nullptr)
	{
		std::cout << "Nope, you can't unequip an invalid slot!";
		std::cout << std::endl;
		return ;
	}
	std::cout << _name << " unequippe in slot " << idx << " Materia " << _inventory[idx];
	std::cout << std::endl;
	_inventory[idx] = nullptr;
}

void		Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 4 || _inventory[idx] == nullptr)
	{
		std::cout << "Nope, you can't use an invalid slot!";
		std::cout << std::endl;
		return ;
	}
	std::cout << getName();
	_inventory[idx]->use(target);
}

std::string const	&Character::getName() const
{
	return (_name);
}
