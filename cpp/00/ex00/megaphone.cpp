/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:17:53 by maxdesall         #+#    #+#             */
/*   Updated: 2021/09/20 16:24:40 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	up_print(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (char)toupper(argv[i][j]);
			j += 1;
		}
		std::cout << " ";
		i += 1;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		up_print(argc, argv);
	std::cout << std::endl;
	return (0);
}
