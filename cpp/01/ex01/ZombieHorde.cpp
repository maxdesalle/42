/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:28:50 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 14:16:33 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string	gen_random(const int len)
{
	int	i;
	std::string str;
	const char alpha[] = "abcdefghijklmnopqrstuvwxyz";

	srand(time(NULL));
	str.reserve(len);
	for (i = 0; i < len; i += 1)
		str += alpha[rand() % (sizeof(alpha) - 1)];

	return (str);
}

Zombie*	zombieHorde(const int N, std::string name)
{
	int	i;
	Zombie*	z;

	z = new Zombie[N];
	for (i = 0; i < N; i += 1)
	{
		sleep(1);
		z[i].set_name(gen_random(name.size()));
		z[i].announce();
	}
	return (&z[0]);
}
