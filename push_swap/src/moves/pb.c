/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:58:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/06 23:15:29 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pb(t_node **a_head, t_node **b_head)
{
	t_node	*mover;
	t_node	*a_tail;
	t_node	*b_tail;

	if (*a_head == NULL)
		return ;
	mover = *a_head;
	if ((*a_head)->value == (*a_head)->next->value && *b_head != NULL)
	{
		b_tail = (*b_head)->prev;
		b_tail->next = mover;
		mover->prev = b_tail;
		mover->next = *b_head;
		(*b_head)->prev = mover;
		*b_head = mover;
		*a_head = NULL;
		return ;
	}
	a_tail = (*a_head)->prev;
	*a_head = (*a_head)->next;
	if (*b_head == NULL)
	{
		*b_head = mover;
		(*b_head)->prev = *b_head;
		(*b_head)->next = *b_head;
		(*a_head)->prev = a_tail;
		a_tail->next = *a_head;
		return ;
	}
	b_tail = (*b_head)->prev;
	b_tail->next = mover;
	mover->prev = b_tail;
	mover->next = *b_head;
	(*b_head)->prev = mover;
	*b_head = mover;
	a_tail->next = *a_head;
	(*a_head)->prev = a_tail;
}
