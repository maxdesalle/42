/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:57:01 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/05 14:33:08 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <array>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>

template< typename T >
int	easyfind(T c, int val)
{
	typename T::const_iterator	i;

	if ((i = std::find(c.begin(), c.end(), val)) == c.end())
		throw (std::runtime_error(std::to_string(val) + " not found in container"));
	else
		return (*i);
}

#endif
