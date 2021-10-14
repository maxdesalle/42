/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:10:48 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 17:58:58 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat: public Animal
{
	public:

		Cat(void);
		~Cat(void);
		Cat(Cat const &ref);
		Cat			&operator=(Cat const &ref);

		void		set_type(std::string type);

		std::string	get_type(void)		const;
		Brain		*get_brain(void)	const;

		void		makeSound(void)		const;

	private:

		std::string	_type;
		Brain		*brain;
};

#endif
