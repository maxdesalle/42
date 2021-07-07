/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:09:35 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/07 15:56:19 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	instruct(int option)
{
	if (option == SA)
		write(1, "sa", 2);
	else if (option == SB)
		write(1, "sb", 2);
	else if (option == SS)
		write(1, "ss", 2);
	else if (option == PA)
		write(1, "pa", 2);
	else if (option == PB)
		write(1, "pb", 2);
	else if (option == RA)
		write(1, "ra", 2);
	else if (option == RB)
		write(1, "sb", 2);
	else if (option == RRA)
		write(1, "rra", 3);
	else if (option == RRB)
		write(1, "rrb", 3);
	else if (option == RRR)
		write(1, "rrr", 3);
	write(1, "\n", 1);
}

int	normal(int return_code)
{
	exit(EXIT_SUCCESS);
	return (return_code);
}

int	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}
