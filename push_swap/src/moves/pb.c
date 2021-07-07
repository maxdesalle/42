/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:58:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/07 15:52:30 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	onelink(t_node **a_head, t_node **b_head)
{
	t_node	*mover;
	t_node	*b_tail;

	mover = *a_head;
	b_tail = (*b_head)->prev;
	b_tail->next = mover;
	mover->prev = b_tail;
	mover->next = *b_head;
	(*b_head)->prev = mover;
	*b_head = mover;
	*a_head = NULL;
}

static void	emptylink(t_node **a_head, t_node **b_head)
{
	t_node	*mover;
	t_node	*a_tail;

	mover = *a_head;
	a_tail = (*a_head)->prev;
	*a_head = (*a_head)->next;
	*b_head = mover;
	(*b_head)->prev = *b_head;
	(*b_head)->next = *b_head;
	(*a_head)->prev = a_tail;
	a_tail->next = *a_head;
}

static void	bink(t_node **a_head, t_node **b_head)
{
	t_node	*mover;
	t_node	*a_tail;
	t_node	*b_tail;

	mover = *a_head;
	a_tail = (*a_head)->prev;
	*a_head = (*a_head)->next;
	b_tail = (*b_head)->prev;
	b_tail->next = mover;
	mover->prev = b_tail;
	mover->next = *b_head;
	(*b_head)->prev = mover;
	*b_head = mover;
	a_tail->next = *a_head;
	(*a_head)->prev = a_tail;
}

void	pb(t_node **a_head, t_node **b_head)
{
	int	len;

	if (*a_head == NULL)
		return ;
	len = listlen(*a_head);
	if (len == 1 && *b_head != NULL)
		onelink(a_head, b_head);
	else if (*b_head == NULL)
		emptylink(a_head, b_head);
	else
		bink(a_head, b_head);
	instruct(PB);
}
