/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:23:55 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 17:24:56 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMateriaSource_HPP
# define IMateriaSource_HPP

#include "AMateria.hpp"

class IMateriaSource
{
	public:

		virtual ~IMateriaSource() {}
		virtual AMateria* createMateria(std::string const & type) = 0;
		virtual void learnMateria(AMateria*) = 0;
};

#endif
