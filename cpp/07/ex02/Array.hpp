/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:53:39 by maxdesall         #+#    #+#             */
/*   Updated: 2021/11/04 17:44:07 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template< typename T >
class Array
{
	public:

		Array(void): _n(0), _arr(NULL) {}
		Array(unsigned int n): _n(n), _arr(new T[n]) {}
		~Array(void) { delete [] _arr; }

		Array(Array const &ref): _n(ref.size())
		{
			_arr = new T[_n];
			for (unsigned int i = 0; i < size(); i += 1)
				_arr[i] = (ref.getArr())[i];
		}

		Array	&operator=(Array const &ref)
		{
			delete [] _arr;
			_n = ref.size();
			_arr = new T[_n];
			for (unsigned int i = 0; i < _n; i += 1)
				_arr[i] = (ref.getArr())[i];
			return (*this);
		}

		T		&operator[](unsigned int i)
		{
			if (i > size() || i < 0)
				throw (std::exception());
			return (getArr()[i]);
		}

		T				*getArr(void)	const { return(_arr); }
		unsigned int	size(void) 		const { return (_n); }

	private:

		unsigned int	_n;
		T				*_arr;
};

template< typename T >
std::ostream	&operator<<(std::ostream &output, Array< T > const &ref)
{
	for (unsigned int i = 0; i < ref.size(); i += 1)
	{
		std::cout << (ref.getArr())[i];
		std::cout << std::endl;
	}
	return (output);
}

#endif
