/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:39:41 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/26 17:48:46 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iomanip>
#include <fstream>
#include "Form.hpp"

class Form;

class ShrubberyCreationForm: public Form
{
	public:

		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &ref);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &ref);

		std::string				getTarget(void)							const;

		void					execute(Bureaucrat const &exec)			const;

	private:

		std::string				_target;
};

#endif
