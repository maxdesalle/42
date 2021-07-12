/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:39:26 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/12 13:48:53 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	prev_bigger(t_node *head)
{
	if (!head || !head->prev)
		return (0);
	if (head->value < head->prev->value)
		return (1);
	return (0);
}

int	prev_smaller(t_node *head)
{
	if (!head || !head->prev)
		return (0);
	if (head->value > head->prev->value)
		return (1);
	return (0);
}
