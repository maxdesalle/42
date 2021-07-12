/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:06:18 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/12 14:46:44 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	b_bigger(t_node *a_head, t_node *b_head)
{
	if (!a_head || !b_head)
		return (0);
	if (a_head->value < b_head->value)
		return (1);
	return (0);
}

int	b_smaller(t_node *a_head, t_node *b_head)
{
	if (!a_head || !b_head)
		return (0);
	if (a_head->value > b_head->value)
		return (1);
	return (0);
}

int	b_first(t_node *a_head, t_node *b_head)
{
	if (!a_head || !b_head)
		return (0);
	if (a_head->value > b_head->value && a_head->prev->value > b_head->value)
		return (1);
	return (0);
}

int	b_last(t_node *a_head, t_node *b_head)
{
	if (!a_head || !b_head)
		return (0);
	if (a_head->value < b_head->value && a_head->prev->value < b_head->value)
		return (1);
	return (0);
}
