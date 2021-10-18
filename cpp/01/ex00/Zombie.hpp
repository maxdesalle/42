/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:49:01 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 14:13:08 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:

		Zombie(const std::string _name);
		~Zombie();
		
		void	announce( void ) const;

	private:

		const std::string	_name;
};

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );

#endif
