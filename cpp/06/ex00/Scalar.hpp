/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:59:44 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/27 19:17:35 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

#include <iostream>
#include <iomanip>
#include <limits.h>

class Scalar
{
	public:

		Scalar(void);
		Scalar(std::string str);
		~Scalar(void);
		Scalar(Scalar const &ref);
		Scalar		&operator=(Scalar const &ref);

		std::string	getStr(void)	const;

		operator	char();
		operator	int();
		operator	float();
		operator	double();

	private:

		std::string	_str;
};

#endif
