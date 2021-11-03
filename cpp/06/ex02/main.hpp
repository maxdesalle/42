/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:27:01 by mdesalle          #+#    #+#             */
/*   Updated: 2021/10/28 14:54:11 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class Base
{
	public:

		virtual ~Base(void) {}
};

class A: public Base
{
};

class B: public Base
{
};

class C: public Base
{
};

#endif
