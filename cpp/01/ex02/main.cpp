/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:41:02 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/04 17:49:05 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str;

	str = "HI THIS IS BRAIN";

	std::string	&strref = str;
	std::string	*strptr = &str;

	std::cout << "address" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "strptr: " << strptr << std::endl;
	std::cout << "strref: " << &strref << std::endl << std::endl;

	std::cout << "value" << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << "strptr: " << *strptr << std::endl;
	std::cout << "strref: " << strref << std::endl;
	return (0);
}
