/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:09:38 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/22 11:11:02 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int	main(void)
{
	ClapTrap	one(CROCODILE);
	ScavTrap	two(LOUP);
	FlagTrap	three(TIGRE);

	std::cout << std::endl;

	one.attack(LOUP);
	two.takeDamage(5);
	two.attack(TIGRE);
	three.takeDamage(5);
	two.beRepaired(10);

	two.attack(CROCODILE);
	one.takeDamage(20);
	one.beRepaired(10);

	three.attack(LOUP);

	two.guardGate();
	three.highFivesGuys();

	std::cout << std::endl;

	return (0);
}
