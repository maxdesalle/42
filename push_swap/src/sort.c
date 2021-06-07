/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:33:08 by mdesalle          #+#    #+#             */
/*   Updated: 2021/06/07 19:44:18 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	two(t_node *head)
{
	int		swap;
	t_node	*tmp;

	tmp = head->next;
	if (head->value > tmp->value)
	{
		ft_swap(&head->value, &tmp->value);
		instruct(SA);
	}
	return (normal(0));
}

void	sort(t_node *head, int argc)
{
	if (argc == TWO_ARGUMENTS)
		two(head);
}
