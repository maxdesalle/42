/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 10:52:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/06/06 11:56:25 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

static int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_num(str[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
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
		if (check(argv[argc - 1]))
		{
			tmp = create(ft_atoi(argv[argc - 1]));
			tmp->next = head;
			head = tmp;
		}
		else
		{
			exit(EXIT_FAILURE);
			return (0);
		}
		argc--;
	}
	return (head);
}
