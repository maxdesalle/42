/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:19:05 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/25 16:24:11 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:

		Bureaucrat(void);
		Bureaucrat(std::string const name, int const grade);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const &ref);
		Bureaucrat	&operator=(Bureaucrat const &ref);

		void				setGrade(int const grade);

		int					getGrade(void)	const;
		std::string	const	getName(void)	const;

		void				incGrade(void);
		void				decGrade(void);

		void				signForm(Form &ref);

		class Exception: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooHighException: public Bureaucrat::Exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException: public Bureaucrat::Exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:

		std::string const	_name;
		int					_grade;
};

std::ostream				&operator<<(std::ostream &output, Bureaucrat const &ref);

#endif
