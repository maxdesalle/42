/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:21:04 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/05 14:19:52 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n): _n(n)
{
}

Span::~Span(void)
{
}

Span::Span(Span const &ref): _n(ref.getN())
{
}

Span				&Span::operator=(Span const &ref)
{
	_n = ref.getN();
	return (*this);
}

void				Span::setN(unsigned int n)
{
	_n = n;
}

void				Span::setVec(std::vector<int> vec)
{
	_vec = vec;
}

unsigned int		Span::getN(void)	const
{
	return (_n);
}

std::vector<int>	Span::getVec(void)	const
{
	return (_vec);
}

void				Span::addNumber(int nbr)
{
	std::vector<int> vec = getVec();

	if (vec.size() > getN())
		throw ("Storage is full");
	else
	{
		vec.push_back(nbr);
		setVec(vec);
	}
}

int					Span::longestSpan(void)
{
	std::vector<int> 			vec = getVec();
	std::vector<int>::iterator	min = std::min_element(vec.begin(), vec.end());
	std::vector<int>::iterator	max = std::max_element(vec.begin(), vec.end());

	if (vec.size() == 0 || vec.size() == 1)
		throw ("Not enough numbers");

	return (*max - *min);
}

int					Span::shortestSpan(void)
{
	std::vector<int>			vec = getVec();
	std::vector<int>::iterator	max = std::max_element(vec.begin(), vec.end());
	int							span = *max;

	if (vec.size() == 0 || vec.size() == 1)
		throw ("Not enough numbers");

	for (size_t i = 1; i < vec.size(); i += 1)
		span = (std::abs(vec[i] - vec[i - 1]) < span) ? std::abs(vec[i] - vec[i - 1]): span;

	return (span);
}
