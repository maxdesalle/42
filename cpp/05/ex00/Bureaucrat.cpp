/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:08:22 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/19 17:22:56 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("useless bureaucrat"), _grade(150)
{
	std::cout << "A " << _name << " with grade " << _grade << " was just constructed!";
	std::cout << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "A " << _name << " with grade " << _grade << " was just destructed!";
	std::cout << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref): _name("another " + ref.getName()), _grade(ref.getGrade())
{
	std::cout << "An " << _name << " with grade " << _grade << " was just copy constructed!";
	std::cout << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &ref)
{
	setGrade(ref.getGrade());
	return (*this);
}

Bureaucrat::Bureaucrat(std::string const name, int const grade): _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
	{
		_grade = grade;
		std::cout << "A " << _name << " with grade " << _grade << " was just constructed!";
		std::cout << std::endl;
	}
}

int					Bureaucrat::getGrade(void)	const
{
	return (_grade);
}

std::string const	Bureaucrat::getName(void)	const
{
	return (_name);
}

void				Bureaucrat::incGrade(void)
{
	if (getGrade() == 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		setGrade(getGrade() - 1);
}

void				Bureaucrat::decGrade(void)
{
	if (getGrade() == 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		setGrade(getGrade() + 1);
}

void				Bureaucrat::setGrade(int const grade)
{
	_grade = grade;
}

const char			*Bureaucrat::Exception::what() const throw()
{
	return ("An exceptional error took place.");
}

const char			*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Nope! You can't get a grade below 1!");
}

const char			*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Nope! You can't get a grade above 150!");
}

std::ostream		&operator<<(std::ostream &output, Bureaucrat const &ref)
{
	output << ref.getName() << " has grade " << ref.getGrade();
	output << std::endl;
	return (output);
}
