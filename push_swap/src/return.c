/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:09:35 by mdesalle          #+#    #+#             */
/*   Updated: 2021/06/07 14:52:36 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	instruct(int option)
{
	if (option == SA)
		write(1, "sa", 2);
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
