/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:29:18 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 19:18:20 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	public:

		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(MateriaSource const &ref);
		MateriaSource &operator=(MateriaSource const &ref);
		
		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);

	private:
		AMateria	*_inventory[4];
};

#endif
