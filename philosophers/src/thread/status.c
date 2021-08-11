/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:26:52 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/11 16:10:09 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	task(int option)
{
	if (option == LEFT_FORK || option == RIGHT_FORK)
		write(STDOUT, "has taken a fork\n", 17);
	else if (option == IS_EATING)
		write(STDOUT, "is eating\n", 10);
	else if (option == IS_SLEEPING)
		write(STDOUT, "is sleeping\n", 12);
	else if (option == IS_THINKING)
		write(STDOUT, "is thinking\n", 12);
	else
		return (0);
	return (1);
}

static int	prefix(int id)
{
	timestamp = wtii() - n->c->st;
	if (!timestamp)
		return (0);
	ft_putnbr(timestamp);
	write(STDOUT, " ", 1);
	ft_putnbr(id);
	write(STDOUT, " ", 1);
	return (1);
}

int	status(t_node *n, int option)
{
	if (!prefix(n->p->id))
		return (0);
	if (!task(option))
		return (0);
	return (1);
}
