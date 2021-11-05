/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:11:35 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/05 14:19:21 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
#include <algorithm>

class Span
{
	public:

		Span(unsigned int n);
		~Span(void);
		Span(Span const &ref);
		Span			&operator=(Span const &ref);

		void				setN(unsigned int n);
		void				setVec(std::vector<int> vec);

		unsigned int		getN(void)		const;
		std::vector<int>	getVec(void)	const;

		void			addNumber(int nbr);
		int				longestSpan(void);
		int				shortestSpan(void);
	
	private:

		unsigned int		_n;
		std::vector<int>	_vec;
};

#endif
