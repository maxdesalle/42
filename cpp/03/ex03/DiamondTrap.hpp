/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:10:48 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/22 11:28:12 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FlagTrap.hpp"

# define DIAMONDTRAP "DiamondTrap"

class	DiamondTrap: public ScavTrap, public FlagTrap
{
	public:

		using			FlagTrap::_hitpoints;
		using			FlagTrap::_attack_damage;
		using			ScavTrap::_energy_points;
		using			ScavTrap::attack;

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
