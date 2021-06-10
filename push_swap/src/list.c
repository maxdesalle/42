/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 10:52:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/06/10 21:52:45 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static int	d_check(t_node *head, int value, int i)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL && i > 0)
	{
		if (value == tmp->value)
			return (error());
		tmp = tmp->next;
		i--;
	}
	return (1);
}

static void	create(t_node **head, t_node **tail, int value, int i)
{
	t_node	*tmp;
	t_node	*result;

	tmp = *head;
	result = malloc(sizeof(t_node));
	if (!result)
		return ;
	result->value = value;
	result->next = NULL;
	if (*head == NULL)
	{
		result->prev = NULL;
		*head = result;
		return ;
	}
	while (tmp->next != NULL && i > 0)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = result;
	result->prev = tmp;
	*tail = result;
	(*tail)->next = *head;
	(*head)->prev = *tail;
}

void	save(t_node **head, t_node **tail, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (num_check(argv[i]) && d_check(*head, ft_atoi(argv[i]), i))
			create(head, tail, ft_atoi(argv[i]), i);
		i++;
	}
}
