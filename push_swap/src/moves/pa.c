/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:58:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/06 15:30:06 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_node **a_head, t_node **b_head)
{
	t_node	*mover;
	t_node	*a_tail;
	t_node	*b_tail;
	t_node	*prev_head;

	mover = *b_head;
	a_tail = (*a_head)->prev;
	b_tail = (*b_head)->prev;
	if (*b_head == NULL)
		return ;
	*b_head = (*b_head)->next;
	b_tail->next = *b_head;
	(*b_head)->prev = b_tail;
	a_tail->next = mover;
	prev_head = *a_head;
	*a_head = mover;
	(*a_head)->next = prev_head;
	prev_head->prev = *a_head;
}
