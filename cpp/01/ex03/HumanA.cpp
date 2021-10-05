/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:01:59 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/05 17:08:14 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
}

void	HumanA::attack(void)	const
{
	std::cout << this->_name;
	std::cout << " attacks with his ";
	std::cout << this->_weapon.getType();
	std::cout << std::endl;
}
