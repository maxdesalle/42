/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:26:17 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/03 10:35:19 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template< typename T >
void	swap(T & x, T & y)
{
	T	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template< typename T >
T		min(T const & x, T const & y)
{
	return (x < y ? x : y);
}

template< typename T >
T		max(T const & x, T const & y)
{
	return (x > y ? x : y);
}

#endif
