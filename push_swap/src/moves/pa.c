/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:58:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/06 23:23:20 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_node **a_head, t_node **b_head)
{
	t_node	*mover;
	t_node	*b_tail;
	t_node	*a_tail;

	if (*b_head == NULL)
		return ;
	mover = *b_head;
	if ((*b_head)->value == (*b_head)->next->value && *a_head != NULL)
	{
		a_tail = (*a_head)->prev;
		a_tail->next = mover;
		mover->prev = a_tail;
		mover->next = *a_head;
		(*a_head)->prev = mover;
		*a_head = mover;
		*b_head = NULL;
		return ;
	}
	b_tail = (*b_head)->prev;
	*b_head = (*b_head)->next;
	if (*a_head == NULL)
	{
		*a_head = mover;
		(*a_head)->prev = *a_head;
		(*a_head)->next = *a_head;
		(*b_head)->prev = b_tail;
		b_tail->next = *b_head;
		return ;
	}
	a_tail = (*a_head)->prev;
	a_tail->next = mover;
	mover->prev = a_tail;
	mover->next = *a_head;
	(*a_head)->prev = mover;
	*a_head = mover;
	b_tail->next = *b_head;
	(*b_head)->prev = b_tail;
}
