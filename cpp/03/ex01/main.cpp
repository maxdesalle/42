/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:09:38 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/12 17:45:21 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	one(CROCODILE);
	ScavTrap	two(LOUP);

	std::cout << std::endl;

	one.attack(LOUP);
	two.takeDamage(5);
	two.beRepaired(10);

	two.attack(CROCODILE);
	one.takeDamage(20);
	one.beRepaired(10);

	two.guardGate();

	std::cout << std::endl;

	return (0);
}
