/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:20:55 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/05 18:40:20 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <iterator>

template < typename T >
class MutantStack: public std::stack< T, std::deque<T> >
{
	public:

		typedef typename std::deque<T>::iterator		iterator;
		typedef typename std::deque<T>::const_iterator	const_iterator;

		iterator	begin(void) { return (this->c.begin()); }
		iterator	end(void) { return (this->c.end()); }

		const_iterator	cbegin(void)	const { return (this->c.cbegin); }
		const_iterator	cend(void)		const { return (this->c.cend); }
};

#endif
