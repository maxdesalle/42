/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:54:28 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/04 14:15:38 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void) const
{
	std::cout << this->_name;
	std::cout << " BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

Zombie::Zombie(std::string name): _name(name)
{
	announce();
}

Zombie::~Zombie(void)
{
	std::cout << "Bye " << this->_name << " 👋" << std::endl;
}
