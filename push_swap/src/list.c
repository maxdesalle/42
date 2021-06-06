/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 10:52:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/06/06 10:57:02 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

static t_node	*create(int value)
{
	t_node	*result;

	result = malloc(sizeof(t_node));
	result->value = value;
	result->next = NULL;
	return (result);
}

t_node	*save(int argc, char **argv)
{
	t_node	*head;
	t_node	*tmp;

	head = NULL;
	while (argc-- > 0)
	{
		if (check(argv[argc - 1]))
		{
			tmp = create(ft_atoi(argv[argc - 1]));
			tmp->next = head;
			head = tmp;
		}
	}
	return (head);
}
