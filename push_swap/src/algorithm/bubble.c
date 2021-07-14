/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 09:18:50 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/14 09:36:18 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	bubble_sa(t_node **tmp)
{}

static t_node	()
{
	

void	bubble(t_node *a_head)
{
	t_node	*tmp;

	tmp = a_head;
	while (!is_sorted(tmp))
	{
		if (tmp->next->value < tmp->value)
			b_sa(tmp);
		ra(tmp);
	}
}
