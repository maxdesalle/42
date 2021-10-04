/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:49:01 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/04 17:26:19 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
#include <ctime>
#include <unistd.h>

class Zombie {

	public:

		Zombie(std::string _name);
		Zombie(void);
		~Zombie(void);
		
		void	announce( void ) const;
		void	set_name(std::string new_name);

	private:

		std::string	_name;
};

void	randomChump( std::string name );
Zombie*	newZombie(std::string name);
Zombie*	zombieHorde(int N, std::string name);

#endif
