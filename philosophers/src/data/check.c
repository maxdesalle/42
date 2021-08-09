/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:24:52 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/09 12:03:20 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	is_nbr(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (!is_num(str[i]))
			return (0);
		i += 1;
	}
	return (1);
}

int	valcheck(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < FOUR_ARG || argc > FIVE_ARG)
		return (0);
	while (i < argc)
	{
		if (!is_nbr(argv[i]))
			return (0);
		i += 1;
	}
	return (1);
}
