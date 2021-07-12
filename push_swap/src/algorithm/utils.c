/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:53:20 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/12 13:39:17 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_node **head)
{
	int		len;
	t_node	*tmp;

	len = listlen(*head);
	tmp = *head;
	while (len > 0)
	{
		len -= 1;
		if (tmp->next->value < tmp->value)
			break ;
		tmp = tmp->next;
	}
	if (len == 0)
		return (1);
	return (0);
}
