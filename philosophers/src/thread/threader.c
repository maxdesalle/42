/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:53:45 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/16 17:07:33 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	*threadator(void *arg)
{
	t_node	*n;

	n = (t_node *)arg;
	if (n->p->id % 2 == 0)
		usleep(20);
	while (!death_check(n))
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
	if (threadkill(h))
		return (1);
	return (0);
}
