/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:09:38 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/22 11:28:54 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	one(CROCODILE);
	ScavTrap	two(LOUP);
	FlagTrap	three(TIGRE);
	DiamondTrap	four(ELEPHANT);

	std::cout << std::endl;

	one.attack(LOUP);
	two.takeDamage(5);
	two.attack(TIGRE);
	three.takeDamage(5);
	two.beRepaired(10);
	four.attack(CROCODILE);
	one.takeDamage(20);

	two.attack(ELEPHANT);
	four.takeDamage(20);
	two.attack(CROCODILE);
	one.takeDamage(20);
	one.beRepaired(10);

	four.attack(CROCODILE);

	two.guardGate();
	three.highFivesGuys();
	four.whoAmI();

	std::cout << std::endl;

	return (0);
}
