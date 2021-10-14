/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:11:10 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 18:00:07 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	set_type("Dog");
	brain = new Brain;
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &ref)
{
	set_type(ref._type);
	brain = new Brain(*(ref.get_brain()));
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog				&Dog::operator=(Dog const &ref)
{
	set_type(ref._type);
	if (brain)
		delete brain;
	brain = new Brain;
	std::cout << "Dog equal operator called" << std::endl;
	return (*this);
}

void			Dog::set_type(std::string type)
{
	_type = type;
}

Brain			*Dog::get_brain(void)	const
{
	return (brain);
}

std::string		Dog::get_type(void)		const
{
	return (_type);
}

void			Dog::makeSound(void)	const
{
	std::cout << "<< random dog sound >>" << std::endl;
}
