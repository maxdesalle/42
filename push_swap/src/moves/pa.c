/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:58:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/07 15:39:52 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	onelink(t_node **a_head, t_node **b_head)
{
	t_node	*mover;
	t_node	*a_tail;

	mover = *b_head;
	a_tail = (*a_head)->prev;
	a_tail->next = mover;
	mover->prev = a_tail;
	mover->next = *a_head;
	(*a_head)->prev = mover;
	*a_head = mover;
	*b_head = NULL;
}

static void	emptylink(t_node **a_head, t_node **b_head)
{
	t_node	*mover;
	t_node	*b_tail;

	mover = *b_head;
	b_tail = (*b_head)->prev;
	*b_head = (*b_head)->next;
	*a_head = mover;
	(*a_head)->prev = *a_head;
	(*a_head)->next = *a_head;
	(*b_head)->prev = b_tail;
	b_tail->next = *b_head;
}

static void	bink(t_node **a_head, t_node **b_head)
{
	t_node	*mover;
	t_node	*b_tail;
	t_node	*a_tail;

	mover = *b_head;
	b_tail = (*b_head)->prev;
	*b_head = (*b_head)->next;
	a_tail = (*a_head)->prev;
	a_tail->next = mover;
	mover->prev = a_tail;
	mover->next = *a_head;
	(*a_head)->prev = mover;
	*a_head = mover;
	b_tail->next = *b_head;
	(*b_head)->prev = b_tail;
}

void	pa(t_node **a_head, t_node **b_head)
{
	int	len;

	if (*b_head == NULL)
		return ;
	len = listlen(*b_head);
	if (len == 1 && *a_head != NULL)
		onelink(a_head, b_head);
	else if (*a_head == NULL)
		emptylink(a_head, b_head);
	else
		bink(a_head, b_head);
}
