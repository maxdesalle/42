/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 10:52:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/14 10:14:52 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	num_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_num(str[i]) && !is_sign(str[i]))
			return (error());
		i++;
	}
	return (1);
}

int	*multi_save(t_node **a_head, int argc, char **argv)
{
	int		i;
	int		*array;
	t_node	*tmp;

	i = 1;
	array = malloc(sizeof(int) * (argc));
	if (!array)
		return (0);
	while (i < argc)
	{
		if (num_check(argv[i]) && d_check(*a_head, ft_atoi(argv[i]), i))
		{
			create(a_head, ft_atoi(argv[i]));
			array[i - 1] = ft_atoi(argv[i]);
		}
		i += 1;
	}
	tmp = *a_head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *a_head;
	(*a_head)->prev = tmp;
	return (array);
}
