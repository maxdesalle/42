/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:33:08 by mdesalle          #+#    #+#             */
/*   Updated: 2021/06/10 13:35:46 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	two(t_node *head)
{
	if (head->value > head->next->value)
	{
		ft_swap(&head->value, &head->next->value);
		instruct(SA);
	}
	return (normal(0));
}

void	sort(t_node **head, int argc)
{
	if (argc == TWO_ARG)
		two(*head);
}
