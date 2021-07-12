/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:53:20 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/12 22:02:00 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_node **head)
{
	int		len;
	t_node	*tmp;

	len = listlen(*head);
	tmp = *head;
	while (len > 0)
	{
		len -= 1;
		if (tmp->next->value < tmp->value)
			break ;
		tmp = tmp->next;
	}
	if (len == 0)
		return (1);
	return (0);
}

int	place_calc(t_node *a_head, t_node *b_head)
{
	int		len;
	int		low;
	int		high;
	t_node	*tmp;

	len = 0;
	low = lowest(a_head);
	high = highest(a_head);
	tmp = a_head;
	while (1)
	{
		if (b_smaller(tmp, b_head) && b_bigger(tmp->prev, b_head))
			break ;
		else if (b_head->value > high && b_bigger(tmp->prev, b_head) && tmp->prev->value == high)
			break ;
		else if (b_head->value < low && b_smaller(tmp, b_head) && tmp->value == low)
			break ;
		tmp = tmp->next;
		len += 1;
	}
	return (len);
}

int	highest(t_node *a_head)
{
	int		len;
	int		high;
	t_node	*tmp;

	len = listlen(a_head);
	tmp = a_head;
	high = tmp->value;
	while (len > 0)
	{
		len -= 1;
		if (high < tmp->value)
			high = tmp->value;
		tmp = tmp->next;
	}
	return (high);
}

int	lowest(t_node *a_head)
{
	int		len;
	int		low;
	t_node	*tmp;

	len = listlen(a_head);
	tmp = a_head;
	low = tmp->value;
	while (len > 0)
	{
		len -= 1;
		if (low > tmp->value)
			low = tmp->value;
		tmp = tmp->next;
	}
	return (low);
}
