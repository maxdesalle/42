/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:18:39 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/26 18:35:07 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat				Oscar("Oscar", 30);
	ShrubberyCreationForm	shrubbery("shrubbery");
	RobotomyRequestForm		robotomy("robotomy");
	PresidentialPardonForm	presidential("presidential");

	shrubbery.beSigned(Oscar);
	Oscar.executeForm(shrubbery);
	Oscar.executeForm(robotomy);
	Oscar.executeForm(presidential);

	return (0);
}
