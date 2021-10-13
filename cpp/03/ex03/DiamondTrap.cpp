/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:44:28 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/13 11:33:11 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FlagTrap.hpp"

FlagTrap::FlagTrap(void)
{
	message_print(FLAGTRAP, CONSTRUCTOR);
}

FlagTrap::FlagTrap(std::string name): ClapTrap("FlagTrap", name, 100, 100, 30)
{
	set_hitpoints(100);
	set_energy_points(100);
	set_attack_damage(30);
	message_print(FLAGTRAP, CONSTRUCTOR);
}

FlagTrap::FlagTrap(FlagTrap const &flag): ClapTrap(flag.get_name())
{
	_name = flag.get_name();
	_hitpoints = flag.get_hitpoints();
	_attack_damage = flag.get_attack_damage();
	_energy_points = flag.get_energy_points();
}

FlagTrap		&FlagTrap::operator=(FlagTrap const &flag)
{
	set_name(flag.get_name());
	set_hitpoints(flag.get_hitpoints());
	set_energy_points(flag.get_energy_points());
	set_attack_damage(flag.get_attack_damage());
	return (*this);
}

FlagTrap::~FlagTrap(void)
{
	message_print(FLAGTRAP, DESTRUCTOR);
}

void			FlagTrap::highFivesGuys(void)
{
	std::cout << get_type() << " " << get_name();
	std::cout << " asks for a high five! ✋";
	std::cout << std::endl;
}
