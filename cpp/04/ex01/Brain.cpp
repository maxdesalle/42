/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:10:42 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/14 17:48:15 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	int	i;

	ideas = new std::string[MAX];
	for (i = 0; i < MAX; i += 1)
		ideas[i] = "<< idea >>";
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(void)
{
	delete [] ideas;
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const &ref)
{
	int	i;

	ideas = new std::string[MAX];
	for (i = 0; i < MAX; i += 1)
		ideas[i] = (ref.get_ideas())[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain		&Brain::operator=(Brain const &ref)
{
	int	i;

	for (i = 0; i < MAX; i += 1)
		ideas[i] = (ref.get_ideas())[i];
	std::cout << "Dog equal operator called" << std::endl;
	return (*this);
}

std::string	*Brain::get_ideas(void)	const
{
	return (ideas);
}
