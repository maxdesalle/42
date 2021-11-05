/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:38:34 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/05 14:33:17 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	const int	max = 5;

	std::array<int, 5>	arr = { 0, 1, 2, 3, 4 };
	std::vector<int>	vec;
	std::list<int>		lst;

	for (size_t i = 0; i < 5; i += 1)
		vec.push_back(i);
	for (size_t i = 0; i < 5; i += 1)
		lst.push_back(i);

	for (size_t i = 0; i < max; i += 1)
	{
		std::cout << easyfind(arr, i) << std::endl;
		std::cout << easyfind(vec, i) << std::endl;
		std::cout << easyfind(lst, i) << std::endl;
	}
	try
	{
		easyfind(arr, -1);
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what();
		std::cout << std::endl;
	}
	return (0);
}
