/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:22:01 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 19:09:38 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
	public:

		Character(std::string name);
		~Character(void);
		Character(Character const &ref);
		Character &operator=(Character const &ref);

		std::string const	&getName()	const;

		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

	private:

		AMateria			*_inventory[4];
		std::string const	_name;
};

#endif
