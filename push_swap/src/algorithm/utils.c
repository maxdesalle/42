/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:53:20 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/16 13:25:07 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_node *head)
{
	int		len;
	t_node	*tmp;

	len = listlen(head);
	tmp = head;
	while (len-- > 0)
	{
		if (tmp->next->value < tmp->value)
			break ;
		tmp = tmp->next;
	}
	if (len == 0)
		return (1);
	return (0);
}

int	place_len(t_node *head, t_node *node)
{
	int		len;
	int		val;
	t_node	*tmp;

	len = 0;
	val = node->value;
	tmp = head;
	while (tmp->value != val)
	{
		tmp = tmp->next;
		len += 1;
	}
	return (len);
}
