/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:54:38 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/09 16:12:37 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	int		ret;
	t_node	*h;

	h = NULL;
	if (!valcheck(argc, argv))
		return (errtoi());
	ret = init(&h, argc, argv);
	if (ret == 0)
		return (error(h));
	else if (ret == -1)
		return (errtoi());
	return (normal(h));
}
