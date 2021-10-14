/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:45:33 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 18:26:41 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	int				i;
	const Animal	*array[10];

	std::cout << std::endl;
	for (i = 0; i < 5; i += 1)
		array[i] = new Cat();

	std::cout << std::endl;
	for (i = 5; i < 10; i += 1)
		array[i] = new Dog();

	std::cout << std::endl;
	for (i = 0; i < 10; i += 1)
		delete array[i];

	std::cout << std::endl;
	std::cout << "LEAK REPORT 👇";
	std::cout << std::endl;
	std::cout << std::endl;

	system("leaks animal");

	return (0);
}
