/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:18:39 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/25 16:29:04 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	Oscar("Oscar", 30);
	Form		AngelaForm("Angela's Form", 75, 150);
	try
	{
		Bureaucrat Creed("Creed", 0);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try
	{
		Form CreedForm("Creed's form", 393, 3);
	}
	catch (Form::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try
	{
		Oscar.signForm(AngelaForm);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try
	{
		AngelaForm.beSigned(Oscar);
	}
	catch (Form::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat Dwight("Dwight", 75);
		std::cout << Dwight;
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat Kevin("Kevin", 150);
		Kevin.decGrade();

	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	return (0);
}
