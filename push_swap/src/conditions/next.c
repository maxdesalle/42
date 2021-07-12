/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:39:26 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/12 13:52:32 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	next_bigger(t_node *head)
{
	if (!head || !head->next)
		return (0);
	if (head->value < head->next->value)
		return (1);
	return (0);
}

int	next_smaller(t_node *head)
{
	if (!head || !head->next)
		return (0);
	if (head->value > head->next->value)
		return (1);
	return (0);
}
