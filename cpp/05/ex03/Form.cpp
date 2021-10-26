/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:11:26 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/26 17:50:41 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("default form"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "A " << _name << "was just constructed!";
	std::cout << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade): _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw (Form::GradeTooHighException());
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw (Form::GradeTooLowException());
	else
	{
		std::cout << "A " << _name << " was just constructed!";
		std::cout << std::endl;
	}
}

Form::~Form(void)
{
	std::cout << "A " << _name << " was just destroyed!";
	std::cout << std::endl;
}

Form::Form(Form const &ref): _name("another " + ref.getName()), _signed(ref.getSigned()), _sign_grade(ref.getSignGrade()), _exec_grade(ref.getExecGrade())
{
	std::cout << "A " << _name << " was just copy constructed!";
	std::cout << std::endl;
}

Form	&Form::operator=(Form const &ref)
{
	setSigned(ref.getSigned());
	return (*this);
}

std::string	const	Form::getName(void)						const
{
	return (_name);
}

bool				Form::getSigned(void)					const
{
	return (_signed);
}

int					Form::getSignGrade(void)				const
{
	return (_sign_grade);
}

int					Form::getExecGrade(void)				const
{
	return (_exec_grade);
}

void				Form::setSigned(const bool signature)
{
	std::cout << "A " << "'s signature was set to " << signature;
	_signed = signature;
}

void				Form::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > _sign_grade)
	{
		throw (Form::GradeTooLowException());
		return ;
	}
	_signed = true;
	std::cout << "A " << _name << " was just signed by bureaucrat " << ref.getName() << ".";
	std::cout << std::endl;
}

const char			*Form::Exception::what()				const throw()
{
	return ("FormException");
}

const char			*Form::GradeTooLowException::what()		const throw()
{
	return ("the grade is too low");
}

const char			*Form::GradeTooHighException::what()	const throw()
{
	return ("the grade is too high");
};

const char			*Form::UnsignedFormException::what()	const throw()
{
	return ("the form isn't signed");
};

const char			*Form::FailureException::what()	const throw()
{
	return ("failure");
};

const char			*Form::InvalidFileException::what()	const throw()
{
	return ("the file could not be opened");
};

std::ostream		&operator<<(std::ostream &output, Form const &ref)
{
	output << "Form \"" << ref.getName() << "\" has sign grade " << ref.getSignGrade() << " and execution grade " << ref.getExecGrade() << " and signature set to " << ref.getSigned() << ".";
	output << std::endl;
	return (output);
}
