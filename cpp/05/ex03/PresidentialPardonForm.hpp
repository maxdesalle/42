/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:39:41 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/26 17:57:37 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class Form;

class PresidentialPardonForm: public Form
{
	public:

		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &ref);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &ref);

		std::string				getTarget(void)							const;

		void					execute(Bureaucrat const &exec)			const;

	private:

		std::string				_target;
};

#endif
