/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:09:35 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/27 09:41:21 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	g_len;

void	instruct(int option)
{
	if (option == SA)
		write(STDOUT, "sa", 2);
	else if (option == SB)
		write(STDOUT, "sb", 2);
	else if (option == SS)
		write(STDOUT, "ss", 2);
	else if (option == PA)
		write(STDOUT, "pa", 2);
	else if (option == PB)
		write(STDOUT, "pb", 2);
	else if (option == RA)
		write(STDOUT, "ra", 2);
	else if (option == RB)
		write(STDOUT, "rb", 2);
	else if (option == RRA)
		write(STDOUT, "rra", 3);
	else if (option == RRB)
		write(STDOUT, "rrb", 3);
	else if (option == RRR)
		write(STDOUT, "rrr", 3);
	write(STDOUT, "\n", 1);
	g_len += 1;
}

int	normal(int return_code, t_node *head)
{
	int		len;
	t_node	*tmp;

	len = listlen(head);
	while (len-- > 0)
	{
		tmp = head;
		head = tmp->next;
		free(tmp);
	}
	printf(" Instructions: %d\n", g_len);
	printf("------------------\n");
	exit(EXIT_SUCCESS);
	return (return_code);
}

int	error(void)
{
	write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}
