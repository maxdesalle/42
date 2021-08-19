/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:42:12 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/19 18:22:28 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	forker(t_node *h)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = h;
	while (i < h->c->len)
	{
		tmp->p->lf = &tmp->prev->p->rf;
		i += 1;
		tmp = tmp->next;
	}
	return (1);
}

int	assign(t_node *n, t_conf *c, int i)
{
	t_phil	*p;

	p = malloc(sizeof(t_phil));
	if (!p)
		return (0);
	n->c = c;
	n->p = p;
	n->p->lf = NULL;
	n->p->id = i;
	if (pthread_mutex_init(&n->p->rf, NULL))
		return (0);
	else
		n->c->dc += 1;
	return (1);
}

t_node	*create(void)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->next = NULL;
	n->prev = NULL;
	return (n);
}
