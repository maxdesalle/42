/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:54:38 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/14 12:54:40 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	int		ret;
	t_node	*h;

	h = NULL;
	if (!valcheck(argc, argv))
		return (errempty());
	ret = init(&h, argc, argv);
	if (ret == 0)
		return (error(h));
	else if (ret == -1)
		return (errempty());
	if (!threader(h))
		return (error(h));
	return (normal(h));
}
