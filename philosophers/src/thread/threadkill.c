/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadkill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:01:38 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/16 17:10:34 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	destruction(t_node *tmp)
{
	pthread_mutex_lock(&tmp->c->death);
	if (!tmp->c->de)
	{
		tmp->c->de = 1;
		pthread_mutex_lock(&tmp->c->wri);
		death(tmp);
		pthread_mutex_unlock(&tmp->c->wri);
	}
	pthread_mutex_unlock(&tmp->c->death);
	return (1);
}
	
static int	differ(t_node *tmp)
{
	pthread_mutex_lock(&tmp->c->eat);
	if ((wtii() - tmp->p->ts) >= tmp->c->td)
	{
		destruction(tmp);
		pthread_mutex_unlock(&tmp->c->eat);
		return (1);
	}
	pthread_mutex_unlock(&tmp->c->eat);
	return (0);
}

static int	threadparser(t_node *h)
{
	t_node	*tmp;

	tmp = h;
	while (!death_check(h))
	{
		if (differ(tmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	death_check(t_node *n)
{
	pthread_mutex_lock(&n->c->death);
	if (n->c->de)
	{
		pthread_mutex_unlock(&n->c->death);
		return (1);
	}
	pthread_mutex_unlock(&n->c->death);
	return (0);
}

int	threadkill(t_node *h)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = h;
	pthread_mutex_lock(&h->c->end);
	if (threadparser(h))
	{
		i = 0;
		tmp = h;
		while (i < h->c->len)
		{
			pthread_join(tmp->p->pid, NULL);
			i += 1;
			tmp = tmp->next;
		}
		pthread_mutex_unlock(&h->c->end);
		return (1);
	}
	pthread_mutex_unlock(&h->c->end);
	return (0);
}
