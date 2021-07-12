/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:39:52 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/12 13:54:00 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	two_nodes(t_node **a_head)
{
	if (next_smaller(*a_head))
		sa(a_head);
}

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

void	five_or_less(t_node **a_head, t_node **b_head)
{
	int	len;

	len = listlen(*a_head);
	if (len == 2)
		two_nodes(a_head);
	else if (len == 3)
		three_nodes(a_head);
}
