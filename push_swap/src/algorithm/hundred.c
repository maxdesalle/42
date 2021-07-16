/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:41:36 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/16 18:27:19 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	b_sort(t_node **a_head, t_node **b_head)
{
	int		i;
	int		var;
	int		len;
	int		save;
	int		header;
	int		counter;
	t_node	*tmp;

	i = 0;
	var = 0;
	len = listlen(*b_head);
	counter = 0;
	tmp = *b_head;
	while (i <= len)
	{
		var = place_len(*b_head, tmp);
		counter = b_swap_calc(*b_head, tmp);
		if (counter != 0)
		{
			header = var - counter;
			while (var-- > 0)
				rb(b_head, 1);
			pa(a_head, b_head);
			while (counter -- > 0)
				rrb(b_head, 1);
			pb(a_head, b_head);
			while (header-- > 0)
				rrb(b_head, 1);
		}
		tmp = *b_head;
		save = i;
		while (save-- > 0)
			tmp = tmp->next;
		i += 1;
	}
}

static void	a_sort(t_node **a_head, t_node **b_head)
{
	int		i;
	int		var;
	int		len;
	int		save;
	int		header;
	int		counter;
	t_node	*tmp;

	i = 0;
	var = 0;
	len = listlen(*a_head);
	counter = 0;
	tmp = *a_head;
	while (i <= len)
	{
		var = place_len(*a_head, tmp);
		counter = a_swap_calc(*a_head, tmp);
		if (counter != 0)
		{
			header = var - counter;
			while (var-- > 0)
				ra(a_head, 1);
			pb(a_head, b_head);
			while (counter -- > 0)
				rra(a_head, 1);
			pa(a_head, b_head);
			while (header-- > 0)
				rra(a_head, 1);
		}
		tmp = *a_head;
		save = i;
		while (save-- > 0)
			tmp = tmp->next;
		i += 1;
	}
}

void	hundred(t_node **a_head, t_node **b_head, int median)
{
	int	len;

	len = listlen(*a_head);
	while (len-- > 0)
	{
		if ((*a_head)->value < median)
			pb(a_head, b_head);
		else
			ra(a_head, 0);
	}
	a_sort(a_head, b_head);
	b_sort(a_head, b_head);
	len = listlen(*b_head);
	while (len--)
		pa(a_head, b_head);
}
