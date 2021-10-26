/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:39:41 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/26 17:50:53 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class Form;

class RobotomyRequestForm: public Form
{
	public:

		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &ref);
		RobotomyRequestForm		&operator=(RobotomyRequestForm const &ref);

		std::string				getTarget(void)							const;

		void					execute(Bureaucrat const &exec)			const;

	private:

		std::string				_target;
};

#endif
