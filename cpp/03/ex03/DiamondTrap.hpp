/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:10:48 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/13 12:40:20 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"

# define FLAGTRAP "DiamondTrap"

class	DiamondTrap: public ClapTrap
{
	public:

		using			FragTrap::_hitpoints;
		using			FragTrap::_attack_damage;
		using			ScavTrap::_energy_points;

		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &flag);
		~DiamondTrap(void);

		DiamondTrap		&operator=(DiamondTrap const &c);

		void			whoAmI(void);
	private:

		std::string		_name;
};

#endif
