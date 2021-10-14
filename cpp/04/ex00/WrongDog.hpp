/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:10:48 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 12:28:31 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include "WrongAnimal.hpp"

class	WrongDog: public WrongAnimal
{
	public:

		WrongDog(void);
		~WrongDog(void);
		WrongDog(WrongDog const &ref);
		WrongDog	&operator=(WrongDog const &ref);

		void		set_type(std::string type);

		std::string	get_type(void)	const;

		void		makeSound(void)	const;

	private:

		std::string	_type;
};

#endif
