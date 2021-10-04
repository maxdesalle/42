/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:49:01 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/04 14:24:52 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

	public:

		Zombie(std::string _name);
		~Zombie();
		
		void	announce( void ) const;

	private:

		std::string	_name;
};

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );

#endif
