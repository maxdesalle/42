/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:10:48 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 12:04:39 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
	public:

		Animal(void);
		virtual				~Animal(void);
		Animal(Animal const &ref);
		Animal				&operator=(Animal const &ref);

		void				set_type(std::string type);

		virtual std::string	get_type(void)	const;

		virtual void		makeSound(void)	const;

	protected:

		std::string			_type;
};

#endif
