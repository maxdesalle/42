/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:01:58 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/07 15:40:10 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	listlen(t_node *head)
{
	int		len;
	t_node	*tmp;

	len = 1;
	tmp = head;
	if (head == NULL)
		return (0);
	if (tmp->next == head)
		return (1);
	while (tmp->next != head)
	{
		len += 1;
		tmp = tmp->next;
	}
	return (len);
}
