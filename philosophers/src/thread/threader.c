/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:53:45 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/13 13:53:51 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	*threadator(void *arg)
{
	t_node	*n;

	n = (t_node *)arg;
	while (!n->c->de)
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
	tmp = h;
	while (!h->c->de)
	{
		if (wtii() - tmp->p->ts >= tmp->c->td)
			h->c->de = 1;
		tmp = tmp->next;
	}
	i = 0;
	tmp = h;
	while (i < h->c->len)
	{
		pthread_join(tmp->p->pid, NULL);
		i += 1;
		tmp = tmp->next;
	}
	return (1);
}
