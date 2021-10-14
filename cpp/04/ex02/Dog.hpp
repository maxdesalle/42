/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:10:48 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 17:58:48 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog: public Animal
{
	public:

		Dog(void);
		~Dog(void);
		Dog(Dog const &ref);
		Dog			&operator=(Dog const &ref);

		void		set_type(std::string type);

		std::string	get_type(void)		const;
		Brain		*get_brain(void)	const;

		void		makeSound(void)		const;

	private:

		std::string	_type;
		Brain		*brain;
};

#endif
