/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:18:14 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 19:25:50 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:

		AMateria(void);
		virtual ~AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &ref);

		virtual std::string const	&getType(void) const;
		virtual AMateria*			clone(void) const = 0;
		virtual void				use(ICharacter &target);

	protected:

		const std::string			_type;
};

#endif
