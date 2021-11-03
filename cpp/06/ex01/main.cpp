/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:29:09 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/28 10:19:48 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data
{
	int	value;
};

uintptr_t	serialize(Data	*ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data	*s1 = new Data;


	s1->value = 5;

	uintptr_t	ptr = serialize(s1);
	Data		*s2 = deserialize(ptr);

	std::cout << "Structure 1 address and value: " << s1 << " / " << s1->value;
	std::cout << std::endl;
	std::cout << "Structure 2 address and value: " << s2 << " / " << s1->value;
	std::cout << std::endl;
	return (0);
}
