/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:45:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/10 20:39:30 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a_head;
	t_node	*b_head;

	a_head = NULL;
	b_head = NULL;
	if (argc == ZERO_ARG)
		return (error());
	else if (argc == ONE_ARG)
		one_save(&a_head, argv);
	else
		multi_save(&a_head, argc, argv);
	return (0);
}
