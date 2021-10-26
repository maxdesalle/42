/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:34:17 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/26 17:51:39 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("Robotomy form", 72, 45), _target("default target")
{
	std::cout << "A Robotomy form was just constructed!";
	std::cout << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Robotomy form", 72, 45), _target(target)
{
	std::cout << "A Robotomy form was just constructed!";
	std::cout << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "A Robotomy form was just destructed!";
	std::cout << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref): Form(ref.getName(), ref.getSignGrade(), ref.getExecGrade()), _target(ref.getTarget())
{
	std::cout << "A Robotomy form was just copy constructed!";
	std::cout << std::endl;
}

RobotomyRequestForm		&RobotomyRequestForm::operator=(RobotomyRequestForm const &ref)
{
	_target = ref.getTarget();
	return (*this);
}

std::string				RobotomyRequestForm::getTarget(void)						const
{
	return (_target);
}

void					RobotomyRequestForm::execute(Bureaucrat const &exec)	const
{
	if (!getSigned())
		throw (Form::UnsignedFormException());
	else if (exec.getGrade() > getExecGrade())
		throw (Form::GradeTooLowException());
	else
	{
		if (!(std::rand() % 2))
		{
			std::cout << _target << " has been robotomized successfully";
			std::cout << std::endl;
		}
		else
			throw Form::FailureException();
	}
}
