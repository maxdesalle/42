/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:45:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/04 11:33:51 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		len;
	t_node	*a_head;
	t_node	*b_head;

	len = argc - 1;
	a_head = NULL;
	b_head = NULL;
	if (argc == ZERO_ARG)
		return (error());
	else if (argc == ONE_ARG)
		one_save(&a_head, argv, &len);
	else
		multi_save(&a_head, argc, argv);
	if (is_sorted(a_head))
		return (normal(0, a_head));
	if (listlen(a_head) <= 5)
		five(&a_head, &b_head);
	else if (listlen(a_head) > 5 && listlen(a_head) <= 100)
		hundred(&a_head, &b_head, 20);
	else if (listlen(a_head) > 100)
		hundred(&a_head, &b_head, 50);
	else
		return (error());
	listprint(a_head);
	listprint(b_head);
	is_valid(a_head);
	return (normal(0, a_head));
}
