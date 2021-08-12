/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:45:32 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/12 14:38:00 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static t_conf	*confinit(int argc, char **argv)
{
	t_conf	*c;

	c = malloc(sizeof(t_conf));
	if (!c)
		return (NULL);
	c->len = ft_atoi(argv[1]);
	c->td = ft_atoi(argv[2]);
	c->te = ft_atoi(argv[3]);
	c->ts = ft_atoi(argv[4]);
	c->st = wtii();
	if (!c->st)
		return (NULL);
	if (argc == FIVE_ARG)
		c->ee = ft_atoi(argv[5]);
	pthread_mutex_init(&c->wri, NULL);
	return (c);
}

static int	saver(t_node **h, t_conf *c)
{
	int		i;
	t_node	*tmp;

	i = 1;
	while (i <= c->len)
	{
		tmp = create();
		if (tmp == NULL)
			return (0);
		linker(h, &tmp);
		assign(tmp, c, i);
		mutinit(tmp);
		i += 1;
	}
	tmp = *h;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *h;
	(*h)->prev = tmp;
	(*h)->p->lf = tmp->p->rf;
	return (1);
}

int	init(t_node **h, int argc, char **argv)
{
	t_conf	*c;

	c = confinit(argc, argv);
	if (!c)
	{
		if (c)
			free(c);
		return (-1);
	}
	if (!saver(h, c))
		return (0);
	return (1);
}
