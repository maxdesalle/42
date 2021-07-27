/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:55:21 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/27 09:30:18 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	linker(t_node **a_head, t_node **new_node)
{
	t_node	*tmp;

	if (*a_head == NULL)
		*a_head = *new_node;
	else if (*a_head != NULL && (*a_head)->next == NULL)
	{
		(*a_head)->next = *new_node;
		(*new_node)->prev = *a_head;
	}
	else
	{
		tmp = *a_head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *new_node;
		(*new_node)->prev = tmp;
	}
}

int	d_check(t_node *a_head, int value, int i)
{
	t_node	*tmp;

	tmp = a_head;
	while (tmp != NULL && i-- > 0)
	{
		if (value == tmp->value)
			return (error());
		tmp = tmp->next;
	}
	return (1);
}

void	create(t_node **a_head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		error();
		return ;
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	linker(a_head, &new_node);
}
