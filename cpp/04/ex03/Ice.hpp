/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:10:13 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 19:24:36 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:

		Ice(void);
		~Ice(void);
		Ice(Ice const &ref);

		Ice 				&operator=(Ice const &ref);
		void				use(ICharacter &target);

		std::string const	&getType(void)	const;
		Ice					*clone(void)	const;
	
	private:

		std::string			_type;
};

#endif
