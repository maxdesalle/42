/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:58:35 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/05 17:07:48 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon): _weapon(weapon)
{
}

void				Weapon::setType(std::string input)
{
	_weapon = input;
}

std::string	const	&Weapon::getType(void)	const
{
	return (_weapon);
}
