/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:58:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/06 11:16:29 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_node **head, int len)
{
	t_node	*one;
	t_node	*two;
	t_node	*three;
	t_node	*tail;

	one = *head;
	two = (*head)->next;
	three = two->next;
	tail = (*head)->prev;
	if (len == 1)
		return ;
	if (len == 2)
	{
		*head = two;
		two->next = one;
		two->prev = one;
		one->next = two;
		one->prev = two;
		return ;
	}
	*head = two;
	two->next = one;
	two->prev = tail;
	one->prev = two;
	one->next = three;
	three->prev = one;
	tail->next = two;
	if (len == 3)
		tail->prev = one;
}
