/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:28:45 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/09 15:41:03 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	append(t_node **h, t_node **n)
{
	t_node	*tmp;

	tmp = *h;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *n;
	(*n)->prev = tmp;
}

static void	second(t_node **h, t_node **n)
{
	(*h)->next = *n;
	(*n)->prev = *h;
}

int	linker(t_node **h, t_node **n)
{
	if (*h == NULL)
		*h = *n;
	else if (*h != NULL && (*h)->next == NULL)
		second(h, n);
	else
		append(h, n);
	return (1);
}
