/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:31:05 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/06 11:59:36 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void	Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. ";
	std::cout << "You don’t put enough! ";
	std::cout << "If you did I would not have to ask for it!";
	std::cout << std::endl;
}

void	Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I just love it!";
	std::cout << std::endl;
}

void	Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << std::endl;
	std::cout << "I’ve been coming here for years and you just started working here last month.";
	std::cout << std::endl;
}

void	Karen::complain(std::string level)
{
	int					i;
	std::string			tag[4] = { "info", "debug", "error", "warning" };
	function_pointer	function[4] = { &Karen::info, &Karen::debug, &Karen::error, &Karen::warning };

	for (i = 0; i < 4; i += 1)
	{
		if (tag[i] == level)
			(this->*(function[i]))();
	}
}
