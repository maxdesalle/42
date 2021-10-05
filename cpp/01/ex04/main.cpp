/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:47:48 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/05 19:44:48 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	std::ifstream	file(argv[1]);
	std::string		buffer;

	while (std::getline(file, buffer))
		std::cout << buffer.find(argv[2]) << std::endl;

	file.close();
	return (0);
}
