/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 10:52:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/07 15:39:17 by mdesalle         ###   ########.fr       */
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

static int	d_check(t_node *a_head, int value, int i)
{
	t_node	*tmp;

	tmp = a_head;
	while (tmp != NULL && i-- > 0)
	{
		if (value == tmp->value)
			return (error());
		tmp = tmp->next;
	}
	return (1);
}

static void	linker(t_node **a_head, t_node **new_node)
{
	t_node	*tmp;

	if (*a_head == NULL)
		*a_head = *new_node;
	else if (*a_head != NULL && (*a_head)->next == NULL)
	{
		(*a_head)->next = *new_node;
		(*new_node)->prev = *a_head;
	}
	else
	{
		tmp = *a_head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *new_node;
		(*new_node)->prev = tmp;
	}
}

static void	create(t_node **a_head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	linker(a_head, &new_node);
}

void	save(t_node **a_head, int argc, char **argv)
{
	int		i;
	t_node	*tmp;

	i = 1;
	while (i < argc)
	{
		if (num_check(argv[i]) && d_check(*a_head, ft_atoi(argv[i]), i))
			create(a_head, ft_atoi(argv[i]));
		i++;
	}
	tmp = *a_head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *a_head;
	(*a_head)->prev = tmp;
}
