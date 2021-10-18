/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:15:13 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 19:21:08 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:

		virtual 					~ICharacter(void) {};

		virtual void				use(int idx, ICharacter& target) = 0;
		virtual void				equip(AMateria *m) = 0;
		virtual void				unequip(int idx) = 0;

		virtual std::string const	&getName()	const = 0;

	protected:

		std::string const	_name;
};

#endif
