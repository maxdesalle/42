/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:44:28 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/12 17:48:25 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void			message_print(std::string type, int option)
{
	switch (option)
	{
		case (CONSTRUCTOR):
			std::cout << type << " constructed";
			break;
		case (DESTRUCTOR):
			std::cout << type << " destructed";
			break;
	}
	std::cout << std::endl;
}

ClapTrap::ClapTrap(void)
{
	message_print(CLAPTRAP, CONSTRUCTOR);
}

ClapTrap::ClapTrap(std::string name): _name(name)
{
	set_type("ClapTrap");
	set_hitpoints(10);
	set_energy_points(10);
	set_attack_damage(0);
	message_print(CLAPTRAP, CONSTRUCTOR);
}

ClapTrap::ClapTrap(std::string type, std::string name, unsigned int hitpoints, unsigned int energy_points, unsigned int attack_damage): _type(type), _name(name), _hitpoints(hitpoints), _energy_points(energy_points), _attack_damage(attack_damage)
{
	message_print(CLAPTRAP, CONSTRUCTOR);
}

ClapTrap::ClapTrap(ClapTrap const &clap)
{
	*this = clap;
}

ClapTrap		&ClapTrap::operator=(ClapTrap const &clap)
{
	set_type(clap.get_type());
	set_name(clap.get_name());
	set_hitpoints(clap.get_hitpoints());
	set_energy_points(clap.get_energy_points());
	set_attack_damage(clap.get_attack_damage());
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	message_print(CLAPTRAP, DESTRUCTOR);
}

void			ClapTrap::set_type(std::string const type)
{
	_type = type;
}

void			ClapTrap::set_name(std::string const name)
{
	_name = name;
}

void			ClapTrap::set_hitpoints(unsigned int const hitpoints)
{
	if (_type == "ClapTrap" && hitpoints > 10)
		_hitpoints = 10;
	else if (_type == "ScavTrap" && hitpoints > 100)
		_hitpoints = 100;
	else
		_hitpoints = hitpoints;
}

void			ClapTrap::set_energy_points(unsigned int const energy_points)
{
	_energy_points = energy_points;
}

void			ClapTrap::set_attack_damage(unsigned int const attack_damage)
{
	_attack_damage = attack_damage;
}

std::string		ClapTrap::get_type(void)			const
{
	return (_type);
}

std::string		ClapTrap::get_name(void)			const
{
	return (_name);
}

unsigned int	ClapTrap::get_hitpoints(void)		const
{
	return (_hitpoints);
}

unsigned int	ClapTrap::get_energy_points(void)	const
{
	return (_energy_points);
}

unsigned int	ClapTrap::get_attack_damage(void)	const
{
	return (_attack_damage);
}

void			ClapTrap::attack(std::string const &target)
{
	if (get_hitpoints() == 0)
	{
		std::cout << get_type() << " " << get_name();
		std::cout << " cannot attack because he is already dead!";
		std::cout << std::endl;
		return ;
	}
	if (get_energy_points() > 2)
	{
		std::cout << get_type() << " " << get_name() << " attack " << target;
		std::cout << ", causing " << get_attack_damage() << " points of damage!";
		std::cout << std::endl;
		set_energy_points(get_energy_points() - 2);
	}
	else
	{
		std::cout << get_type() << " " << get_name() << " tries to attack " << target;
		std::cout << " but doesn't have enough energy points!";
		std::cout << std::endl;
	}
	std::cout << get_name() << ": " << "HP - " << get_hitpoints();
	std::cout << " / EP - " << get_energy_points();
	std::cout << std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (get_hitpoints() == 0)
	{
		std::cout << "Stop!";
		std::cout << " " << get_type() << " " << get_name();
		std::cout << " is already dead!";
		std::cout << std::endl;
		return ;
	}
	if (amount > get_hitpoints())
		set_hitpoints(0);
	else
		set_hitpoints(get_hitpoints() - amount);
	std::cout << get_type() << " " << get_name() << " lost " << amount << " hitpoints";
	std::cout << std::endl;
	std::cout << get_name() << ": " << "HP - " << get_hitpoints();
	std::cout << " / EP - " << get_energy_points();
	std::cout << std::endl;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (get_hitpoints() == 0)
	{
		std::cout << get_type() << " " << get_name();
		std::cout << " cannot be repaired because he is already dead!";
		std::cout << std::endl;
		return ;
	}
	set_hitpoints(get_hitpoints() + amount);
	std::cout << get_type() << " " << get_name() << " is repaired";
	std::cout << std::endl;
	std::cout << get_name() << ": " << "HP - " << get_hitpoints();
	std::cout << " / EP - " << get_energy_points();
	std::cout << std::endl;
}
