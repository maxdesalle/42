/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:30:22 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/09 16:24:07 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	normal(t_node *h)
{
	int		len;
	t_node	*tmp;

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
	write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}

int	errtoi(void)
{
	write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}
