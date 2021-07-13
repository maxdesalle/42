/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:39:52 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/13 11:18:03 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	three_nodes(t_node **a_head)
{
	int	len;

	len = listlen(*a_head);
	if (is_sorted(a_head))
		return ;
	if (next_bigger(*a_head) && prev_smaller(*a_head))
	{
		rra(a_head);
		return ;
	}
	if (prev_bigger(*a_head) && next_bigger(*a_head))
		sa(a_head);
	if (prev_smaller(*a_head))
		ra(a_head);
	if (next_smaller(*a_head))
		sa(a_head);
}

static void	placer(t_node **a_head, t_node **b_head, int option)
{
	int	len;

	len = 0;
	if (option == 1)
	{
		len = place_calc(*a_head, *b_head);
		while (len > 0)
		{
			ra(a_head);
			len -= 1;
		}
		pa(a_head, b_head);
		return ;
	}
	if (b_first(*a_head, *b_head))
		pa(a_head, b_head);
	else if (b_last(*a_head, *b_head))
	{
		pa(a_head, b_head);
		ra(a_head);
	}
	else
	{
		len = place_calc(*a_head, *b_head);
		while (len-- > 0)
			ra(a_head);
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
	while ((*a_head)->value != low)
		ra(a_head);
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
	while ((*a_head)->value != low)
		ra(a_head);
}

void	five_or_less(t_node **a_head, t_node **b_head)
{
	int	len;

	len = listlen(*a_head);
	if (len == 2)
	{
		if (next_smaller(*a_head))
			sa(a_head);
	}
	else if (len == 3)
		three_nodes(a_head);
	else if (len == 4)
		four_nodes(a_head, b_head);
	else if (len == 5)
		five_nodes(a_head, b_head);
}
