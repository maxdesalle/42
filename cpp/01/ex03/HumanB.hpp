/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:46:48 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/05 17:01:44 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	public:

		HumanB(std::string name);
		HumanB(std::string name, Weapon &weapon);

		void	setWeapon(Weapon &weapon);
		void	attack(void)	const;

	private:

		std::string	_name;
		Weapon		*_weapon;	
};

#endif
