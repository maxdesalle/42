/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:39:41 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/25 16:24:02 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

		Form(void);
		Form(std::string name, int sign_grade, int exec_grade);
		~Form(void);
		Form(Form const &ref);
		Form &operator=(Form const &ref);

		std::string	const	getName(void)		const;
		bool				getSigned(void)		const;
		int					getSignGrade(void)	const;
		int					getExecGrade(void)	const;

		void				setSigned(const bool signature);

		void				beSigned(Bureaucrat &ref);

		class Exception: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooHighException: public Form::Exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException: public Form::Exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:

		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;
};

std::ostream	&operator<<(std::ostream &output, Form const &ref);

#endif
