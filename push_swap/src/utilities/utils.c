/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:01:58 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/13 14:03:44 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	listlen(t_node *head)
{
	int		len;
	t_node	*tmp;

	len = 1;
	tmp = head;
	if (head == NULL)
		return (0);
	if (tmp->next == head)
		return (1);
	while (tmp->next != head)
	{
		len += 1;
		tmp = tmp->next;
	}
	return (len);
}

void	listprint(t_node *head)
{
	int		len;
	t_node	*tmp;

	len = listlen(head);
	tmp = head;
	printf("--------------------\n");
	while (len-- > 0)
	{
		if (len == 0)
			printf("%d\n", tmp->value);
		else
			printf("%d - ", tmp->value);
		tmp = tmp->next;
	}
}

void	is_valid(t_node *a_head)
{
	int		len;
	t_node	*tmp;

	len = listlen(a_head);
	tmp = a_head;
	while (--len > 0)
	{
		if (tmp->next->value < tmp->value)
		{
			printf("--------------------\n");
			printf(" Invalid results ❌\n");
			printf("--------------------\n");
			return ;
		}
		tmp = tmp->next;
	}
	printf("------------------\n");
	printf(" Valid results ✅\n");
	printf("------------------\n");
}
