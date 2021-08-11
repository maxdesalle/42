/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:42:12 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/11 16:42:33 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	assign(t_node *n, t_conf *c, int i)
{
	t_phil	*p;

	p = malloc(sizeof(t_phil));
	if (!p)
		return (0);
	n->c = c;
	n->p = p;
	n->p->id = i;
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
