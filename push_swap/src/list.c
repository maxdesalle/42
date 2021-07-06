/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 10:52:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/06 09:53:40 by mdesalle         ###   ########.fr       */
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
	while (tmp != NULL && i-- > 0)
	{
		if (value == tmp->value)
			return (error());
		tmp = tmp->next;
	}
	return (1);
}

static void	create(t_node **head, int value)
{
	t_node	*tmp;
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	else if (*head != NULL && (*head)->next == NULL)
	{
		(*head)->next = new_node;
		new_node->prev = *head;
		return;
	}
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}

void	save(t_node **head, int argc, char **argv)
{
	int	i;
	t_node	*tmp;

	i = 1;
	while (i < argc)
	{
		if (num_check(argv[i]) && d_check(*head, ft_atoi(argv[i]), i))
			create(head, ft_atoi(argv[i]));
		i++;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head;
	(*head)->prev = tmp;
}
