/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:10:48 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/22 10:58:02 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define SCAVTRAP "ScavTrap"

class	ScavTrap: public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &scav);
		~ScavTrap(void);

		ScavTrap		&operator=(ScavTrap const &c);

		void			guardGate();
		void			attack(std::string const & target);
};

#endif
