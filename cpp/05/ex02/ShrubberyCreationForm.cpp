/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:34:17 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/26 17:52:39 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("Shrubbery form", 145, 137), _target("default target")
{
	std::cout << "A Shrubbery form was just constructed!";
	std::cout << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Shrubbery form", 145, 137), _target(target)
{
	std::cout << "A Shrubbery form was just constructed!";
	std::cout << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "A Shrubbery form was just destructed!";
	std::cout << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref): Form(ref.getName(), ref.getSignGrade(), ref.getExecGrade()), _target(ref.getTarget())
{
	std::cout << "A Shrubbery form was just copy constructed!";
	std::cout << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref)
{
	_target = ref.getTarget();
	return (*this);
}

std::string				ShrubberyCreationForm::getTarget(void)						const
{
	return (_target);
}

void					ShrubberyCreationForm::execute(Bureaucrat const &exec)	const
{
	std::string	ascii_tree =
		"      '.,\n"
		"        'b      *\n"
		"         '$    #.\n"
		"          $:   #:\n"
		"          *#  @):\n"
		"          :@,@):   ,.**:'\n"
		",         :@@*: ..**'\n"
		" '#o.    .:(@'.@*\"'\n"
		"    'bq,..:,@@*'   ,*\n"
		"    ,p$q8,:@)'  .p*'\n"
		"   '    '@@Pp@@*'\n"
		"         Y7'.'\n"
		"        :@):.\n"
		"       .:@:'.\n"
		"     .::(@:.\n";

	if (!getSigned())
		throw (Form::UnsignedFormException());
	else if (exec.getGrade() > getExecGrade())
		throw (Form::GradeTooLowException());
	else
	{
		std::ofstream	file(_target);

		if (!file.is_open())
			throw (Form::InvalidFileException());
		else
			file << ascii_tree;
	}
}
