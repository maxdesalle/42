/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:03:51 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/13 17:17:43 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	highest(t_node *head)
{
	int		len;
	int		high;
	t_node	*tmp;

	len = listlen(head);
	tmp = head;
	high = tmp->value;
	while (len > 0)
	{
		len -= 1;
		if (high < tmp->value)
			high = tmp->value;
		tmp = tmp->next;
	}
	return (high);
}

int	sec_highest(t_node *head)
{
	int		len;
	int		high;
	int		sec_high;
	t_node	*tmp;

	len = listlen(head);
	tmp = head;
	high = highest(head);
	sec_high = 0;
	while (len > 0)
	{
		len -= 1;
		if (sec_high < tmp->value && high != tmp->value)
			sec_high = tmp->value;
		tmp = tmp->next;
	}
	return (sec_high);
}

int	lowest(t_node *head)
{
	int		len;
	int		low;
	t_node	*tmp;

	len = listlen(head);
	tmp = head;
	low = tmp->value;
	while (len > 0)
	{
		len -= 1;
		if (low > tmp->value)
			low = tmp->value;
		tmp = tmp->next;
	}
	return (low);
}
