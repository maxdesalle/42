/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:45:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/12 13:11:24 by mdesalle         ###   ########.fr       */
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
	if (listlen(a_head) <= 5)
		five_or_less(&a_head, &b_head);

	int		i;
	t_node	*tmp;

	i = 3;
	tmp = a_head;
	while (i > 0)
	{
		i -= 1;
		printf("%d - ", tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
