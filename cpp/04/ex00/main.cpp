/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:45:33 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 12:30:06 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main(void)
{
	const Animal		*meta =	new Animal();
	const Animal		*j = 	new Dog();
	const Animal		*i = 	new Cat();
	const WrongAnimal	*h =	new WrongAnimal();
	const WrongAnimal	*g =	new WrongDog();
	const WrongAnimal	*f =	new WrongCat();

	std::cout << j->get_type() << " " << std::endl;
	std::cout << i->get_type() << " " << std::endl;

	std::cout << std::endl;
	std::cout << g->get_type() << " " << std::endl;
	std::cout << f->get_type() << " " << std::endl;

	std::cout << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();

	std::cout << std::endl;
	h->makeSound();
	g->makeSound();
	f->makeSound();

	std::cout << std::endl;
	delete	meta;
	delete	i;
	delete	j;
	delete	h;
	delete	g;
	delete	f;
	return (0);
}
