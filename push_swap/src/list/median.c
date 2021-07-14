/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:23:27 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/14 11:43:25 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	not_sorted(int *list, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (list[i] > list[i + 1] && i != (len - 1))
			return (1);
		i += 1;
	}
	return (0);
}

int	median_finder(int *list, int len)
{
	int	i;
	int	index;

	while (not_sorted(list, len))
	{
		i = 0;
		while (i < len)
		{
			if (list[i] > list[i + 1] && i != (len - 1))
				ft_swap(&list[i], &list[i + 1]);
			i += 1;
		}
	}
	index = (len + 1) / 2 - 1;
	return (list[index]);
}
