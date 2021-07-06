/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:45:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/06 11:20:58 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head;

	head = NULL;
	if (argc == ZERO_ARG)
		return (error());
	save(&head, argc, argv);
#if 1	
	int	i;

	i = 8;
	t_node	*tmp;
	tmp = head;
	while (i-- > 0)
	{
		printf("%d - ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
#endif
#if 0
	sa(&head, argc - 1);
#endif
#if 1
	i = 8;
	tmp = head;
	while (i-- > 0)
	{
		printf("%d - ", tmp->value);
		tmp = tmp->next;
	}
#endif
	return (0);
}
