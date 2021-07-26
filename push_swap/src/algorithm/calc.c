/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 09:14:27 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/26 16:58:27 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	place_calc(t_node *a_head, t_node *b_head)
{
	int		len;
	int		low;
	int		high;
	t_node	*tmp;

	len = 0;
	if (!a_head || !b_head)
		return (0);
	low = lowest(a_head);
	high = highest(a_head);
	tmp = a_head;
	while (1)
	{
		if (b_smaller(tmp, b_head) && b_bigger(tmp->prev, b_head))
			break ;
		else if (b_head->value > high && b_bigger(tmp->prev, b_head)
			&& tmp->prev->value == high)
			break ;
		else if (b_head->value < low && b_smaller(tmp, b_head)
			&& tmp->value == low)
			break ;
		tmp = tmp->next;
		len += 1;
	}
	return (len);
}

int	inv_place_calc(t_node *a_head, t_node *b_head)
{
	int		len;
	int		low;
	int		high;
	t_node	*tmp;

	len = 0;
	if (!a_head || !b_head)
		return (0);
	low = lowest(a_head);
	high = highest(a_head);
	tmp = a_head;
	while (1)
	{
		if (b_smaller(tmp, b_head) && b_bigger(tmp->prev, b_head))
			break ;
		else if (b_head->value > high && b_bigger(tmp->prev, b_head)
			&& tmp->prev->value == high)
			break ;
		else if (b_head->value < low && b_smaller(tmp, b_head)
			&& tmp->value == low)
			break ;
		tmp = tmp->prev;
		len += 1;
	}
	return (len);
}

int	pcalc(t_node *a_head, t_node *b_head)
{
	int	a_len;
	int	b_len;

	a_len = (place_calc(a_head, b_head));
	b_len = (inv_place_calc(a_head, b_head));
	if (a_len >= b_len)
		return (b_len * -1);
	else
		return (a_len);
}

int	rotate_calc(t_node *head, int low)
{
	int		a_len;
	int		b_len;
	t_node	*tmp;

	a_len = 0;
	b_len = 0;
	tmp = head;
	while (tmp->value != low)
	{
		tmp = tmp->next;
		a_len += 1;
	}
	tmp = head;
	while (tmp->value != low)
	{
		tmp = tmp->prev;
		b_len += 1;
	}
	if (a_len >= b_len)
		return (1);
	else
		return (0);
}

int	lower(t_node *head, int value)
{
	int		len;
	int		a_len;
	int		b_len;
	t_node	*tmp;

	len = listlen(head);
	a_len = 0;
	b_len = 0;
	tmp = head;
	while (a_len++ < len)
	{
		if (value <= tmp->value)
			break ;
		tmp = tmp->next;
	}
	while (b_len++ < len)
	{
		if (value <= tmp->value)
			break ;
		tmp = tmp->prev;
	}
	if (a_len >= b_len)
		return (1);
	else
		return (-1);
}
