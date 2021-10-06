/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:28:10 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/06 11:50:58 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

class	Karen
{
	public:

		typedef	void(Karen::*function_pointer)(void);

		void	complain(std::string level);

	private:

		void	info(void);
		void	debug(void);
		void	error(void);
		void	warning(void);
};

#endif
