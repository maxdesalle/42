/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:44:28 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/13 18:02:01 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	message_print(DIAMONDTRAP, CONSTRUCTOR);
}

DiamondTrap::DiamondTrap(std::string name):	ClapTrap(name + "_clap_trap"),
											ScavTrap(name + "_clap_trap"),
											FlagTrap(name + "_clap_trap")
{
	message_print(DIAMONDTRAP, CONSTRUCTOR);
}

DiamondTrap::DiamondTrap(DiamondTrap const &diamond): ClapTrap(diamond.get_name()), ScavTrap(diamond.get_name()), FlagTrap(diamond.get_name())
{
	_name = diamond.get_name();
	_hitpoints = diamond.get_hitpoints();
	_attack_damage = diamond.get_attack_damage();
	_energy_points = diamond.get_energy_points();
}

DiamondTrap		&DiamondTrap::operator=(DiamondTrap const &diamond)
{
	set_name(diamond.get_name());
	set_hitpoints(diamond.get_hitpoints());
	set_energy_points(diamond.get_energy_points());
	set_attack_damage(diamond.get_attack_damage());
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	message_print(DIAMONDTRAP, DESTRUCTOR);
}

void			DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << get_type() << " " << get_name() << "! 👋";
	std::cout << std::endl;
}
