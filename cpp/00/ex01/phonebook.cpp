/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:27:41 by maxdesall         #+#    #+#             */
/*   Updated: 2021/09/21 18:36:44 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void	question(Contact *contact, int *i)
{
	std::string	line;

	std::cout << "What's his/her first name?" << std::endl;
	std::getline(std::cin, line);
	(*contact).set_first_name(line);
	std::cout << "What's his/her last name?" << std::endl;
	std::getline(std::cin, line);
	(*contact).set_last_name(line);
	std::cout << "What's his/her nickname?" << std::endl;
	std::getline(std::cin, line);
	(*contact).set_nickname(line);
	std::cout << "What's his/her phone number?" << std::endl;
	std::getline(std::cin, line);
	(*contact).set_phone_number(line);
	std::cout << "What's his/her darkest secret?" << std::endl;
	std::getline(std::cin, line);
	(*contact).set_darkest_secret(line);
	*i += 1;
}

int			main(int argc, char **argv)
{
	int			i;
	int			j;
	Contact 	contact[8];
	std::string	line;

	i = 0;
	j = 0;
	while (PROGRAM_IS_RUNNING)
	{
		std::cout << "Please input one of the following commands: SEARCH / ADD / EXIT" << std::endl;
		std::getline(std::cin, line);
		if (line == "EXIT")
			exit(EXIT_SUCCESS);
		else if (line == "ADD")
			question(&contact[i], &i);
		else if (line == "SEARCH")
			continue ;
		else
			continue ;
    }
	return (0);
}
