/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:18:25 by maxdesall         #+#    #+#             */
/*   Updated: 2021/09/23 15:26:35 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

# define PROGRAM_IS_RUNNING 1

class	Contact {

	public:

		void	set_first_name(std::string input);
		void	set_last_name(std::string input);
		void	set_nickname(std::string input);
		void	set_phone_number(std::string input);
		void	set_darkest_secret(std::string input);

		std::string	get_first_name() const;
		std::string	get_last_name() const;
		std::string	get_nickname() const;
		std::string	get_phone_number() const;
		std::string	get_darkest_secret() const;

	private:

		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

};

void		Contact::set_first_name(std::string input)
{
	first_name = input;
}

void		Contact::set_last_name(std::string input)
{
	last_name = input;
}

void		Contact::set_nickname(std::string input)
{
	nickname = input;
}

void		Contact::set_phone_number(std::string input)
{
	phone_number = input;
}

void		Contact::set_darkest_secret(std::string input)
{
	darkest_secret = input;
}

std::string	Contact::get_first_name() const
{
	return (first_name);
}

std::string	Contact::get_last_name()
{
	return (last_name);
}

std::string	Contact::get_nickname()
{
	return (nickname);
}

std::string	Contact::get_phone_number()
{
	return (phone_number);
}

std::string	Contact::get_darkest_secret()
{
	return (darkest_secret);
}

#endif
