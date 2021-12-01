/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:14:41 by maxdesall         #+#    #+#             */
/*   Updated: 2021/12/01 11:31:36 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	template <class Iterator>
	class iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef ft::random_access_iterator_tag			iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef ft::random_access_iterator_tag			iterator_category;
	};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T										value_type;
		typedef Distance								difference_type;
		typedef Pointer									pointer;
		typedef Reference								reference;
		typedef Category								iterator_category;
	};

	template <class Iterator>
	class reverse_iterator
	{
		public:

			typedef Iterator											iterator_type;
			typedef ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef ft::iterator_traits<Iterator>::value_type			value_type;
			typedef ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef ft::iterator_traits<Iterator>::pointer				pointer;
			typedef ft::iterator_traits<Iterator>::reference			reference;

			reverse_iterator() {}
			reverse_iterator(iterator_type it): _it(it) {}
			explicit reverse_iterator(iterator_type it): _it(it) {}
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it): _it(rev_it.base()) {}

			iterator_type	base() const { return (_it); }

			private:

				iterator_type	_it;
	};
}

#endif
