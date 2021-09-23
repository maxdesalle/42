/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:27:41 by maxdesall         #+#    #+#             */
/*   Updated: 2021/09/23 17:10:15 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void	value_print(std::string value)
{
	std::string	str;

	str = value;
	if (str.size() > 10)
	{
		str.resize(9);
		str += '.';
	}
	std::cout << std::setw(10) << str << "|";
}

static void	top_print_utils(std::string str)
{
	std::cout << std::setw(10) << str << "|";
}

static void	info_print(Contact contact)
{
	std::cout << "First Name: " << contact.get_first_name() << std::endl;
	std::cout << "Last Name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_darkest_secret() << std::endl;
}

static void	top_print(void)
{
	std::cout << std::endl;
	top_print_utils("Index");
	top_print_utils("First Name");
	top_print_utils("Last Name");
	top_print_utils("Nickname");
	std::cout << std::endl;
	top_print_utils("-----");
	top_print_utils("----------");
	top_print_utils("----------");
	top_print_utils("----------");
	std::cout << std::endl;
}

static void	search(Contact *contact, int i)
{
	int			j;
	int			value;
	std::string	line;

	j = 0;
	value = -1;
	top_print();
	while (j < i)
	{
		std::cout << std::setw(10) << j + 1 << "|";
		value_print(contact[j].get_first_name());
		value_print(contact[j].get_last_name());
		value_print(contact[j].get_nickname());
		std::cout << std::endl;
		j += 1;
	}
	std::cout << std::endl;
	std::cout << "What's the index number of the contact you are looking for?" << std::endl;
	std::getline(std::cin, line);
	if (!line.empty())
		value = stoi(line);
	if (value > 0 && value <= i)
		info_print(contact[value - 1]);
}

static void	add(Contact *contact, int *i)
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

int		main(void)
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
			add(&contact[i], &i);
		else if (line == "SEARCH")
			search(contact, j);
		else
			continue ;
		if (j != 7)
			j = i;
		if (i == 7)
			i = 0;
    }
	return (0);
}
