/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:44:28 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/22 11:10:05 by mdesalle         ###   ########.fr       */
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

void			FlagTrap::attack(std::string const &target)
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
		std::cout << get_type() << " " << get_name() << " throws up on " << target;
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
