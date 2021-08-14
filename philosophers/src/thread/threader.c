/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:53:45 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/14 11:37:09 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	*threadator(void *arg)
{
	t_node	*n;

	n = (t_node *)arg;
	if (n->p->id % 2 == 0)
		usleep(20);
	while (!n->c->de)
		actionator(n);
	return (NULL);
}

int	threader(t_node *h)
{
	int		i;
	int		time;
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
	tmp = h;
	while (!h->c->de)
	{
		pthread_mutex_lock(&tmp->p->te);
		time = wtii() - tmp->p->ts;
		pthread_mutex_unlock(&tmp->p->te);
		if (time >= tmp->c->td)
		{
			h->c->de = 1;
			pthread_mutex_lock(&tmp->c->wri);
			death(tmp);
			pthread_mutex_unlock(&tmp->c->wri);
		}
		tmp = tmp->next;
	}
	return (1);
}
