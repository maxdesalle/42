/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:45:32 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/09 16:25:08 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	assign(t_node *n, t_conf *c, int i)
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

static t_node	*create(void)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

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
	return (c);
}

static int	saver(t_node **h, t_conf *c)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (i < c->len)
	{
		tmp = create();
		if (tmp == NULL)
			return (0);
		linker(h, &tmp);
		assign(tmp, c, i);
		i += 1;
	}
	tmp = *h;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *h;
	(*h)->prev = tmp;
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
