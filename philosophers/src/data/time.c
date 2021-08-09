/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:29:11 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/09 10:14:05 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long	wtii(void)
{
	long			millitime;
	struct timeval	timestamp;

	if (gettimeofday(&timestamp, NULL) == -1)
		return (0);
	millitime = timestamp.tv_sec * 1000 + timestamp.tv_usec / 1000;
	return (millitime);
}
