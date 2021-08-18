/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:54:38 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/18 11:28:08 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	int		ret;
	t_node	*h;

	h = NULL;
	ret = valcheck(argc, argv);
	if (ret == 0)
		return (errempty());
	else if (ret == -1)
		return (0);
	ret = init(&h, argc, argv);
	if (ret == 0)
		return (error(h));
	else if (ret == -1)
		return (errempty());
	if (!threader(h))
		return (error(h));
	return (normal(h));
}
