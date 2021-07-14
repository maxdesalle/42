/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:58:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/07 15:56:08 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	two_link(t_node **b_head, t_node **one, t_node **two)
{
	*b_head = *two;
	(*two)->next = *one;
	(*two)->prev = *one;
	(*one)->next = *two;
	(*one)->prev = *two;
}

static void	bink(t_node **one, t_node **two, t_node **three, t_node **tail)
{
	(*two)->next = *one;
	(*two)->prev = *tail;
	(*one)->prev = *two;
	(*one)->next = *three;
	(*three)->prev = *one;
	(*tail)->next = *two;
}

void	sb(t_node **b_head)
{
	int		len;
	t_node	*one;
	t_node	*two;
	t_node	*three;
	t_node	*tail;

	len = listlen(*b_head);
	one = *b_head;
	two = (*b_head)->next;
	three = two->next;
	tail = (*b_head)->prev;
	if (len == 1)
		;
	else if (len == 2)
		two_link(b_head, &one, &two);
	else
	{
		*b_head = two;
		bink(&one, &two, &three, &tail);
	}
	if (len == 3)
		tail->prev = one;
	instruct(SB);
}