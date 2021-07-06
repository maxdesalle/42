/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:45:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/06 13:00:11 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a_head;

	a_head = NULL;
	if (argc == ZERO_ARG)
		return (error());
	save(&a_head, argc, argv);
#if 1	
	int	i;

	i = 8;
	t_node	*tmp;
	tmp = a_head;
	while (i-- > 0)
	{
		printf("%d - ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
#endif
#if 0
	sa(&a_head, argc - 1);
#endif
#if 1
	ra(&a_head);
#endif
#if 1
	i = 8;
	tmp = a_head;
	while (i-- > 0)
	{
		printf("%d - ", tmp->value);
		tmp = tmp->next;
	}
#endif
	return (0);
}
