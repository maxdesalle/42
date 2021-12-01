/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:56:47 by maxdesall         #+#    #+#             */
/*   Updated: 2021/12/01 16:39:45 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace ft
{
	struct random_access_iterator_tag { };

	template<typename T>
	class random_access_iterator: public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:

			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef T*	pointer;
			typedef T&	reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

		private:
	};
}

#endif
