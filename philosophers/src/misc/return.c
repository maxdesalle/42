/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:30:22 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/19 18:30:20 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	textroy(t_node *h)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = h;
	if (h->c->ndc > 0)
		pthread_mutex_destroy(&tmp->c->eat);
	if (h->c->ndc > 1)
		pthread_mutex_destroy(&tmp->c->wri);
	if (h->c->ndc > 2)
		pthread_mutex_destroy(&tmp->c->end);
	if (h->c->ndc > 3)
		pthread_mutex_destroy(&tmp->c->stex);
	if (h->c->ndc > 4)
		pthread_mutex_destroy(&tmp->c->death);
	while (i < h->c->dc)
	{
		pthread_mutex_destroy(&tmp->p->rf);
		tmp = tmp->next;
		i += 1;
	}
	return (1);
}

int	normal(t_node *h)
{
	int		len;
	t_node	*tmp;

	textroy(h);
	len = h->c->len;
	free(h->c);
	while (len > 0)
	{
		tmp = h;
		h = tmp->next;
		free(tmp->p);
		free(tmp);
		len -= 1;
	}
	exit(EXIT_SUCCESS);
	return (1);
}

int	error(t_node *h)
{
	int		len;
	t_node	*tmp;

	if (h)
	{
		textroy(h);
		len = h->c->len;
		free(h->c);
		while (len > 0 && h != NULL)
		{
			tmp = h;
			h = tmp->next;
			if (tmp->p)
				free(tmp->p);
			free(tmp);
			len -= 1;
		}
	}
	write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}

int	errempty(void)
{
	write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}
