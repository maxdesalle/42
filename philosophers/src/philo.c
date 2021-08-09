/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:54:38 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/09 12:22:22 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	listlen(t_node *h)
{
	int		len;
	t_node	*tmp;

	len = 1;
	tmp = h;
	if (h == NULL)
		return (0);
	if (tmp->next == h)
		return (1);
	while (tmp->next != h)
	{
		len += 1;
		tmp = tmp->next;
	}
	return (len);
}

static void	listprint(t_node *h)
{
	int		len;
	t_node	*tmp;

	len = listlen(h);
	tmp = h;
	while (len-- > 0)
	{
		if (len == 0)
			printf("%d\n", tmp->p->id);
		else
			printf("%d - ", tmp->p->id);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*h;

	h = NULL;
	if (!valcheck(argc, argv))
		return (error());
	if (!init(&h, argc, argv))
		return (error());
	listprint(h);
	return (0);
}
