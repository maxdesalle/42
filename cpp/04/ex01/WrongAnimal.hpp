/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:10:48 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 12:09:08 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	public:

		WrongAnimal(void);
		~WrongAnimal(void);
		WrongAnimal(WrongAnimal const &ref);
		WrongAnimal	&operator=(WrongAnimal const &ref);

		void		set_type(std::string type);

		std::string	get_type(void)	const;

		void		makeSound(void)	const;

	protected:

		std::string	_type;
};

#endif
