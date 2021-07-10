/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:09:35 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/10 20:28:26 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		write(STDOUT, "sb", 2);
	else if (option == RRA)
		write(STDOUT, "rra", 3);
	else if (option == RRB)
		write(STDOUT, "rrb", 3);
	else if (option == RRR)
		write(STDOUT, "rrr", 3);
	write(STDOUT, "\n", 1);
}

int	normal(int return_code)
{
	exit(EXIT_SUCCESS);
	return (return_code);
}

int	error(void)
{
	write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}
