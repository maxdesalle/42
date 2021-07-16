/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:39:52 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/14 15:01:50 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	three_nodes(t_node **a_head)
{
	int	len;

	len = listlen(*a_head);
	if (is_sorted(*a_head))
		return ;
	if (next_bigger(*a_head) && prev_smaller(*a_head))
	{
		rra(a_head, 1);
		return ;
	}
	if (prev_bigger(*a_head) && next_bigger(*a_head))
		sa(a_head, 1);
	if (prev_smaller(*a_head))
		ra(a_head, 1);
	if (next_smaller(*a_head))
		sa(a_head, 1);
}

static void	placer(t_node **a_head, t_node **b_head, int option)
{
	int	len;

	len = pcalc(*a_head, *b_head);
	if (option == 1)
	{
		if (len < 0)
		{
			while (len++ < 0)
				rra(a_head, 1);
		}
		else
		{
			while (len-- > 0)
				ra(a_head, 1);
		}
		pa(a_head, b_head);
		return ;
	}
	if (b_first(*a_head, *b_head))
		pa(a_head, b_head);
	else if (b_last(*a_head, *b_head))
	{
		pa(a_head, b_head);
		len = pcalc(*a_head, *b_head);
		if (len >= 0)
			ra(a_head, 1);
	}
	else
	{
		if (len < 0) {
			while (len++ < 0)
				rra(a_head, 1);
		}
		else
		{
			while (len-- > 0)
				ra(a_head, 1);
		}
		pa(a_head, b_head);
	}
}

static void	four_nodes(t_node **a_head, t_node **b_head)
{
	int	low;

	low = 0;
	pb(a_head, b_head);
	three_nodes(a_head);
	placer(a_head, b_head, 0);
	low = lowest(*a_head);
	if (rotate_calc(*a_head, low) == 0)
	{
		while ((*a_head)->value != low)
			ra(a_head, 1);
	}
	else
	{
		while ((*a_head)->value != low)
			rra(a_head, 1);
	}
}

static void	five_nodes(t_node **a_head, t_node **b_head)
{
	int	low;

	low = 0;
	pb(a_head, b_head);
	pb(a_head, b_head);
	three_nodes(a_head);
	placer(a_head, b_head, 0);
	placer(a_head, b_head, 1);
	low = lowest(*a_head);
	if (rotate_calc(*a_head, low) == 0)
	{
		while ((*a_head)->value != low)
			ra(a_head, 1);
	}
	else
	{
		while ((*a_head)->value != low)
			rra(a_head, 1);
	}
}

void	five(t_node **a_head, t_node **b_head)
{
	int	len;

	len = listlen(*a_head);
	if (len == 2)
	{
		if (next_smaller(*a_head))
			sa(a_head, 1);
	}
	else if (len == 3)
		three_nodes(a_head);
	else if (len == 4)
		four_nodes(a_head, b_head);
	else if (len == 5)
		five_nodes(a_head, b_head);
}
