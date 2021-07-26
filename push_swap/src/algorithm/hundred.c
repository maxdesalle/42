/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:41:36 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/26 17:25:33 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	modulo(t_node *a_head, int option)
{
	int	i;
	int	len;

	i = 0;
	len = listlen(a_head);
	while (len-- % option != 0)
		i += 1;
	return (i);
}

static int	chuncker(t_node *a_head, int modulo)
{
	int		low;
	int		len;
	int		high;
	int		counter;
	t_node	*tmp;

	low = lowest(a_head);
	counter = 0;
	tmp = a_head;
	while (counter++ < modulo)
	{
		len = listlen(a_head);
		high = highest(a_head);
		tmp = a_head;
		while (len-- > 0)
		{
			if (tmp->value > low && tmp->value < high)
				high = tmp->value;
			tmp = tmp->next;
		}
		low = high;
	}
	return (low);
}

static void	pusher(t_node **a_head, t_node **b_head, int counter, int option)
{
	int	value;

	value = chuncker(*a_head, modulo(*a_head, option));
	while (counter > 0)
	{
		if (counter % option == 0)
			value = chuncker(*a_head, option - 1);
		if (lower(*a_head, value) == 1)
		{
			while ((*a_head)->value > value)
				ra(a_head, 1);
		}
		else
		{
			while ((*a_head)->value > value)
				rra(a_head, 1);
		}
		pb(a_head, b_head);
		counter -= 1;
	}
}

static void	puller(t_node **a_head, t_node **b_head, int counter)
{
	int	value;

	value = 0;
	while (counter > 0)
	{
		value = highest(*b_head);
		if (rotate_calc(*b_head, value) == 1)
		{
			while ((*b_head)->value != value)
				rrb(b_head, 1);
		}
		else
		{
			while ((*b_head)->value != value)
				rb(b_head, 1);
		}
		pa(a_head, b_head);
		counter -= 1;
	}
}

void	hundred(t_node **a_head, t_node **b_head, int option)
{
	pusher(a_head, b_head, listlen(*a_head), option);
	puller(a_head, b_head, listlen(*b_head));
}
