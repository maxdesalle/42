/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:44:17 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/26 19:13:38 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "An innocent intern was just constructed!";
	std::cout << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "An innocent intern was just destructed!";
	std::cout << std::endl;
}

Intern::Intern(Intern const &ref)
{
	std::cout << "An innocent intern was just copy constructed using intern " << ref;
	std::cout << std::endl;
}

Intern	&Intern::operator=(Intern const &ref)
{
	std::cout << ref << " (just printing this for the sake of doing something";
	return (*this);
}

static Form	*shrubbery(std::string target)
{
	Form	*shrubbery_form = new ShrubberyCreationForm(target);
	return (shrubbery_form);
}

static Form	*robotomy(std::string target)
{
	Form	*robotomy_form = new RobotomyRequestForm(target);
	return (robotomy_form);
}

static Form	*presidential(std::string target)
{
	Form	*presidential_form = new PresidentialPardonForm(target);
	return (presidential_form);
}

Form	*Intern::makeForm(std::string name, std::string target)
{
	int			i = 0;
	Form		*form = nullptr;
	Form		*(*function[3])(std::string target) = { shrubbery, robotomy, presidential };
	std::string	options[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };

	for (i = 0; i < 3; i += 1)
	{
		if (name == options[i])
			form = function[i](target);
	}
	if (!form)
		throw (Form::Exception());
	else
	{
		std::cout << "Intern creates " << *form;
		std::cout << std::endl;
	}
	return (form);
}

std::ostream		&operator<<(std::ostream &output, Intern const &ref)
{
	(void)ref;
	output << "some random useless intern";
	output << std::endl;
	return (output);
}
