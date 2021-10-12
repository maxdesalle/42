/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:09:38 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/12 12:01:33 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	one(CROCODILE);
	ClapTrap	two(LOUP);

	std::cout << std::endl;

	one.attack(LOUP);
	two.takeDamage(5);
	two.beRepaired(10);

	two.attack(CROCODILE);
	one.takeDamage(20);
	one.beRepaired(10);

	std::cout << std::endl;

	return (0);
}
