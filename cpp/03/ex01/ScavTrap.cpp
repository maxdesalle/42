/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:44:28 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/22 10:57:11 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	message_print(SCAVTRAP, CONSTRUCTOR);
}

ScavTrap::ScavTrap(std::string name): ClapTrap("ScavTrap", name, 100, 50, 20)
{
	set_hitpoints(100);
	set_energy_points(50);
	set_attack_damage(20);
	message_print(SCAVTRAP, CONSTRUCTOR);
}

ScavTrap::ScavTrap(ScavTrap const &scav): ClapTrap(scav.get_name())
{
	_name = scav.get_name();
	_hitpoints = scav.get_hitpoints();
	_attack_damage = scav.get_attack_damage();
	_energy_points = scav.get_energy_points();
}

ScavTrap		&ScavTrap::operator=(ScavTrap const &scav)
{
	set_name(scav.get_name());
	set_hitpoints(scav.get_hitpoints());
	set_energy_points(scav.get_energy_points());
	set_attack_damage(scav.get_attack_damage());
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	message_print(SCAVTRAP, DESTRUCTOR);
}

void			ScavTrap::guardGate(void)
{
	std::cout << get_type() << " " << get_name() << " ";
	std::cout << "entered gatekeeper mode!";
	std::cout << std::endl;
	set_energy_points(50);
	std::cout << get_name() << ": " << "HP - " << get_hitpoints();
	std::cout << " / EP - " << get_energy_points();
	std::cout << std::endl;
}

void			ScavTrap::attack(std::string const &target)
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
		std::cout << get_type() << " " << get_name() << " makes a super massive ultra mega hyper giga attack on " << target;
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
