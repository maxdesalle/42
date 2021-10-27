/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:02:12 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/27 19:17:10 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Only one argument is allowed";
		std::cout << std::endl;
		return (0);
	}
	
	std::string	arg = argv[1];
	Scalar		convert(arg);

	char		c;
	int			i;
	float		f;
	double		d;

	std::cout << std::fixed << std::setprecision(1);

	c = static_cast<char>(convert);
	i = static_cast<int>(convert);
	f = static_cast<float>(convert);
	d = static_cast<double>(convert);

	return (0);
}
