/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:54:28 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 14:11:44 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void) const
{
	std::cout << _name;
	std::cout << " BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

Zombie::Zombie(std::string name): _name(name)
{
	announce();
}

Zombie::~Zombie(void)
{
	std::cout << "Bye " << _name << " 👋" << std::endl;
}
