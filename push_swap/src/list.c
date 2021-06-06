/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 10:52:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/06/06 14:03:14 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

static int	num_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_num(str[i]) && !is_sign(str[i]))
			return (error());
		i++;
	}
	return (1);
}

static int	double_check(t_node *head, t_node *value)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (value->value == tmp->value)
			return (error());
		tmp = tmp->next;
	}
	return (1);
}

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
	while (argc > 1)
	{
		if (num_check(argv[argc - 1]))
		{
			tmp = create(ft_atoi(argv[argc - 1]));
			double_check(head, tmp);
			tmp->next = head;
			head = tmp;
		}
		argc--;
	}
	return (head);
}
