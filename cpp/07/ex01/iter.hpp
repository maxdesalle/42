/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:09:55 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/03 11:35:37 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template< typename T >
void	iter(T *arr, size_t len, T f(T))
{
	for (size_t i = 0; i < len; i += 1)
		arr[i] = f(arr[i]);
}

template< typename T >
T		inc(T value)
{
	return (value + value);
}

#endif
