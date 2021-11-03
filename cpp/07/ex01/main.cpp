/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:25:59 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/03 11:40:47 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int			intarr[5] = { 1, 2, 3, 4, 5 };
	std::string	strarr[5] = { "crocodile", "loup", "tigre", "elephant", "chien" };

	std::cout << "before: ";
	for (size_t i = 0; i < 5; i += 1)
		std::cout << strarr[i];
	std::cout << std::endl;
	std::cout << "after: ";
	iter(strarr, 5, inc);
	for (size_t i = 0; i < 5; i += 1)
		std::cout << strarr[i];
	std::cout << std::endl << std::endl;

	std::cout << "before: ";
	for (size_t i = 0; i < 5; i += 1)
		std::cout << intarr[i];
	std::cout << std::endl;
	std::cout << "after: ";
	iter(intarr, 5, inc);
	for (size_t i = 0; i < 5; i += 1)
		std::cout << intarr[i];
	std::cout << std::endl;
	return (0);
}
