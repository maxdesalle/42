/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:58:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/06 19:25:17 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pb(t_node **a_head, t_node **b_head)
{
	t_node	*mover;
	t_node	*a_tail;
	t_node	*b_tail;
	t_node	*prev_head;

	mover = *a_head;
	if (*be_head != NULL)
		b_tail = (*b_head)->prev;
	a_tail = (*a_head)->prev;
	if (*a_head == NULL)
		return ;
	*a_head = (*a_head)->next;
	a_tail->next = *a_head;
	(*a_head)->prev = a_tail;
	b_tail->next = mover;
	prev_head = *b_head;
	*b_head = mover;
	(*b_head)->next = prev_head;
	prev_head->prev = *b_head;
}
