/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:34:25 by maxdesall         #+#    #+#             */
/*   Updated: 2021/07/26 17:40:38 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	option_one(t_node **a_head, t_node **b_head, int len)
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
}

static void	option_else(t_node **a_head, t_node **b_head, int len)
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
}

void	placer(t_node **a_head, t_node **b_head, int option)
{
	int	len;

	len = pcalc(*a_head, *b_head);
	if (option == 1)
	{
		option_one(a_head, b_head, len);
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
		option_else(a_head, b_head, len);
}
