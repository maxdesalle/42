/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:53:45 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/20 10:40:40 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	stopper(t_node *n)
{
	pthread_mutex_lock(&n->c->stex);
	if (n->c->ee == (n->c->ct / n->c->len) && n->c->ee != 0)
	{
		pthread_mutex_unlock(&n->c->stex);
		return (0);
	}
	pthread_mutex_unlock(&n->c->stex);
	return (1);
}

static void	*threadator(void *arg)
{
	t_node	*n;

	n = (t_node *)arg;
	if (n->p->id % 2 == 0 && n->c->len > 1)
		sleeper(n, n->c->te / 10);
	if (n->c->len == 1)
	{
		status(n, LEFT_FORK);
		return (NULL);
	}
	while (!death_check(n) && stopper(n))
		actionator(n);
	return (NULL);
}

int	threader(t_node *h)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = h;
	while (i < h->c->len)
	{
		if (pthread_create(&tmp->p->pid, NULL, threadator, tmp))
			return (0);
		i += 1;
		tmp = tmp->next;
	}
	sleeper(h, h->c->td + 1);
	if (threadkill(h))
		return (1);
	return (0);
}
