/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:10:13 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 19:17:50 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure: public AMateria
{
	public:

		Cure(void);
		~Cure(void);
		Cure(Cure const &ref);

		Cure 				&operator=(Cure const &ref);
		void				use(ICharacter& target);

		std::string const	&getType(void)	const;
		Cure				*clone(void)	const;
	
	private:

		std::string			_type;
};

#endif
