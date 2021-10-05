/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:41:03 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/05 17:07:37 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class		Weapon
{
	public:

		Weapon(std::string weapon);

		void				setType(std::string input);

		std::string const	&getType(void)	const;

	private:

		std::string	_weapon;
};

#endif
