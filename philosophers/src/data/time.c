/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:29:11 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/20 10:41:33 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	sleeper(t_node *n, long ms)
{
	long	st;

	st = wtii();
	while (!death_check(n))
	{
		if ((wtii() - st) > ms)
			break ;
		usleep(50);
	}
	return (1);
}

long	wtii(void)
{
	long			millitime;
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	millitime = timestamp.tv_sec * 1000 + timestamp.tv_usec / 1000;
	return (millitime);
}
