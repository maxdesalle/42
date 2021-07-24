/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:41:36 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/24 18:21:24 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	pusher(t_node **a_head, t_node **b_head)
{
	int	low;

	low = 0;
	while (listlen(*a_head) != 0)
	{
		low = lowest(*a_head);
		while ((*a_head)->value != low)
			ra(a_head, 1);
		if ((*a_head)->value == low)
			pb(a_head, b_head);
	}
}

void	hundred(t_node **a_head, t_node **b_head)
{
	int	len;

	pusher(a_head, b_head);
	len = listlen(*b_head);
	while (len--)
		pa(a_head, b_head);
}
