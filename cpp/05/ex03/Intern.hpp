/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:40:53 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/26 19:12:34 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
	public:

		Intern(void);
		~Intern(void);
		Intern(Intern const &ref);
		Intern	&operator=(Intern const &ref);

		Form	*makeForm(std::string name, std::string target);
};

std::ostream	&operator<<(std::ostream &output, Intern const &ref);

#endif
