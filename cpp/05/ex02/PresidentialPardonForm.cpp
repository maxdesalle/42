/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:34:17 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/26 18:21:28 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("Presidential form", 25, 5), _target("default target")
{
	std::cout << "A Presidential form was just constructed!";
	std::cout << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presidential form", 72, 45), _target(target)
{
	std::cout << "A Presidential form was just constructed!";
	std::cout << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "A Presidential form was just destructed!";
	std::cout << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref): Form(ref.getName(), ref.getSignGrade(), ref.getExecGrade()), _target(ref.getTarget())
{
	std::cout << "A Presidential form was just copy constructed!";
	std::cout << std::endl;
}

PresidentialPardonForm		&PresidentialPardonForm::operator=(PresidentialPardonForm const &ref)
{
	_target = ref.getTarget();
	return (*this);
}

std::string				PresidentialPardonForm::getTarget(void)						const
{
	return (_target);
}

void					PresidentialPardonForm::execute(Bureaucrat const &exec)		const
{
	if (!getSigned())
		throw (Form::UnsignedFormException());
	else if (exec.getGrade() > getExecGrade())
		throw (Form::GradeTooLowException());
	else
	{
		std::cout << _target << " was pardonned by Zafod Beeblebrox";
		std::cout << std::endl;
	}
}
